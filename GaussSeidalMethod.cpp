#include <bits/stdc++.h>
using namespace std;

const int maxIterations = 10000;
const int tolerance = .00001;

void makeDiagonallyDominant(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                sum += fabs(A[i][j]);
            }
        }

        if (fabs(A[i][i]) < sum) {
            for (int k = i + 1; k < n; k++) {
                double newSum = 0.0;
                for (int j = 0; j < n; j++) {
                    if (k != j) {
                        newSum += fabs(A[k][j]);
                    }
                }
                if (fabs(A[k][k]) >= newSum) {
                    swap(A[i], A[k]);
                    swap(b[i], b[k]);
                    break;
                }
            }
        } 
    }
}

void gaussSeidelMethod(vector<vector<double>>& A,vector<double>& b, vector<double>& x) {
    int n = A.size();
    vector<double> x_new(n);

    for (int iteration = 0; iteration < maxIterations; iteration++) {

        for (int i = 0; i < n; i++){
            double sum = 0.0;

            for (int j = 0; j < i; j++) {
                sum += A[i][j] * x_new[j];
            }

            for (int j = i + 1; j < n; j++) {
                sum += A[i][j] * x[j];
            }

            x_new[i] = (b[i] - sum) / A[i][i];
        }
       
        vector<double> error(n);
        for (int i = 0; i < n; i++) {
            error[i]= fabs(x_new[i] - x[i]);
        }

        if (error[0] < tolerance && error[1] < tolerance && error[2] < tolerance) {
            x = x_new;
            return;
        } 
        x = x_new;
    }

}

int main() {
    int n;
    cout<<"Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double> (n));
    vector<double> b(n), x(n, 0.0);

    cout<<"Enter the coefficient matrix and right hand value: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
        cin >> b[i];
    }

    makeDiagonallyDominant(A,b);
    gaussSeidelMethod(A, b, x);
    
    cout<<"The solution is: ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}


//System of Equation

/*
4 -1 0 1
-1 3 -1 2
0 -1 5 3

15 5 4 2 5
4 20 6 2 8
4 5 21 6 8
1 7 8 25 2 

*/