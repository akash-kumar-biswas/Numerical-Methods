#include <bits/stdc++.h>
using namespace std;

void differenceTable( vector<double>& x, vector<double>& y, vector<vector<double>>& diffTable) {
    int n = x.size();
    
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
        }
    }
}

double forwardInterpolation(vector<double>& x,vector<double>& y, double x0) {
    int n = x.size();
    vector<vector<double>> diffTable(n, vector<double>(n));
    
    differenceTable(x, y, diffTable);
        for(auto row: diffTable){
        for(auto val: row){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    double h = x[1] - x[0]; 
    double s = (x0 - x[0]) / h; 
    double value = diffTable[0][0]; 

    for (int i = 1; i < n; i++) {
        double term = diffTable[0][i];
        for (int j = 0; j < i; j++) {
            term *= (s - j) / (j + 1);
        }
        value += term;
    }

    return value;
}

int main() {
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {1, 4, 9, 16, 25};

    double x0;
    cout<<2.5*2.5<<endl;
    cout << "Enter the value of x0: ";
    cin >> x0;

    double result = forwardInterpolation(x, y, x0);
    cout << "The interpolated value at x = " << x0 << " is: " << setprecision(5) << fixed << result << endl;

    return 0;
}