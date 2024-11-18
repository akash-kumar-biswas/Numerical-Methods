#include <bits/stdc++.h>
using namespace std;

void calculateSums(vector<double>& x, vector<double>& y, double& sumX, double& sumX2, double& sumY, double& sumXY) {


    int n = x.size();
    for (int i = 0; i < n; i++) {
        double xi = x[i];
        double yi = y[i];
        
        sumX += xi;
        sumX2 += xi * xi;
        sumY += log(yi);  
        sumXY += xi * log(yi);
    }
}

void curveFitting(vector<double>& x, vector<double>& y, double& a, double& b) {
    double sumX=0, sumX2=0, sumY=0, sumXY=0;
    
    calculateSums(x, y, sumX, sumX2, sumY, sumXY);
    
    int n = x.size();
    
    double B = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double A = (sumY - B * sumX) / n;
    
    a = exp(A);  
    b = exp(B);    
}

void printEquation(double a, double b) {
    cout << "Equation: y = " << a << "*" << b << "^x" << endl;
}

int main() {
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {2, 4, 8, 16, 32};  // y = 1 * 2^x

    double a, b;
    
    curveFitting(x, y, a, b);
    
    printEquation(a, b);
    
    return 0;
}
