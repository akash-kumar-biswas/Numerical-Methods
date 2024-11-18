#include <bits/stdc++.h>
using namespace std;

double lagrangeInterpolation(vector<double>& x, vector<double>& y, double point) {
    double result = 0.0;
    int n = x.size();
    
    for (int i = 0; i < n; i++) {
        double term = y[i];
        
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (point - x[j]) / (x[i] - x[j]);
            }
        }
        
        result += term;
    }
    return result;
}

int main() {
    vector<double> x = {1.0, 2.0, 3.0,4.0,5.0};
    vector<double> y = {1.0, 4.0, 9.0,16.0,25.0};
    
    double point = 5;
    
    double interpolatedValue = lagrangeInterpolation(x, y, point);
    cout<< "Interpolated value at point " << point << " is " << interpolatedValue << endl;
    return 0;
}
