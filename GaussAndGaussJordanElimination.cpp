#include<bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<double>> matrix){
    for(auto row: matrix){
        for(auto val: row){
            cout<<val<<" ";
        }
        cout<<"\n";
    }
}

vector<double> row_ech(vector<vector<double>> A){
    int n = A.size();
    vector<double> result(n);

    for (int i = n - 1; i >= 0; i--) {
        result[i] = A[i][n]; // Start with the last column (constants)
        for (int j = i + 1; j < n; j++) {
            result[i] -= A[i][j] * result[j]; // Subtract the known values
        }
        result[i] /= A[i][i]; // Divide by the pivot to solve for the variable
    }
    return result;
}

vector<vector<double>> gauss_eli(vector<vector<double>> A){
    
    int n = A.size(); 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i][i] == 0) {
                swap(A[i], A[j]); // Swap rows if pivot is zero
            }
        }

        // Eliminate entries below the pivot
        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i]; // Determine the factor to eliminate
            for (int k = i; k < n + 1; k++) {
                A[j][k] -= factor * A[i][k]; // Subtract the multiple of the pivot row
            }
        }
    }
    return A;
}

vector<vector<double>> jordan_eli(vector<vector<double>> A){
    int n=A.size();

    for (int i = n - 1; i >= 0; i--) {
        // Normalize the pivot row
        double pivot = A[i][i];
        for (int j = 0; j < A[0].size(); j++) {
            A[i][j] /= pivot; // Normalize the pivot row
        }

        // Eliminate entries above the pivot
        for (int j = 0; j < i; j++) {
            double factor = A[j][i];
            for (int k = 0; k < A[0].size(); k++) {
                A[j][k] -= factor * A[i][k]; // Subtract the multiple of the pivot row
            }
        }
    }
    return A;
}


void Gauss_Elimination(vector<vector<double>> A){
    vector<vector<double>> A1=gauss_eli(A);
    cout<<"\nUpper Triangular Matrix: \n";
    printMatrix(A1);
    vector<double> solution = row_ech(A1);
    cout<<"\nThe solution is: \n";
    for(int i=0;i<solution.size();i++){
        cout<<solution[i]<<" ";
    }
}

void Gauss_Jordan_Elimination(vector<vector<double>> A) {
    vector<vector<double>> A1 = gauss_eli(A);
    cout<<"\nUpper Triangular Matrix: \n";
    printMatrix(A1);

    vector<vector<double>> A2 = jordan_eli(A1);
    cout<<"\nJordan Elemeneted Matrix: \n";
    printMatrix(A2);
    vector<double> solution = row_ech(A2);
    cout<<"\nThe solution is: \n";
    for(int i=0;i<solution.size();i++){
        cout<<solution[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;

    vector<vector<double>> A(n, vector<double>(n+1));

    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            cin>>A[i][j];
        }
    }

    cout<<"\nOriginal Matrix: \n";
    printMatrix(A);

    Gauss_Elimination(A);
    Gauss_Jordan_Elimination(A);
    return 0;
    
}

/* 
1 1 1 6
0 2 5 -4
2 3 4 1
*/