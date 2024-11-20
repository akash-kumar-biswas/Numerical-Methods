#include <bits/stdc++.h>

using namespace std;

void calculateSums(vector<double>& x,vector<double>& y, double& sumX, double& sumY, double& sumX2, double& sumXY) { 
    int n = x.size();
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumX2 += x[i] * x[i];
        sumXY += x[i] * y[i];
    }
}

void curveFitting(vector<double>& x,vector<double>& y, double& b, double& a) {
    double sumX=0, sumY=0, sumX2=0, sumXY=0;
    calculateSums(x, y, sumX, sumY, sumX2, sumXY);
    
    int n = x.size();
    
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX); 
    a = (sumY - b * sumX) / n; 
}

// Function to print the fitted line equation
void printEquation(double b, double a) {
    cout << "Equation: y = " << a << " + " << b << "*x" << endl;
}

int main() {
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {3, 5, 7, 9, 11};
    
    double b, a;
    
    // Perform linear curve fitting
    curveFitting(x, y, b, a);
    
    // Print the fitted line equation
    printEquation(b, a);
    
    return 0;
}
