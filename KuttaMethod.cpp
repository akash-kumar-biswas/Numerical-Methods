#include <bits/stdc++.h>
using namespace std;

double f(double x, double y) {
    return sin(x);  
}

void rk4(double y0, double x0, double x_end, double h) {
    int n_steps = (x_end - x0) / h;
    vector<double> x_values(n_steps + 1);
    vector<double> y_values(n_steps + 1);

    x_values[0] = x0;
    y_values[0] = y0;

    double y_n = y0;
    for (int n = 0; n < n_steps; n++) {
        double x_n = x_values[n];
        
        double k1 = h * f(x_n, y_n);
        double k2 = h * f(x_n + h / 2, y_n + k1 / 2);
        double k3 = h * f(x_n + h / 2, y_n + k2 / 2);
        double k4 = h * f(x_n + h, y_n + k3);
        
        y_n += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        
        x_values[n + 1] = x_n + h;
        y_values[n + 1] = y_n;
    }

    cout << fixed << setprecision(6);
    cout << "x\t\ty\n";
    for (int i = 0; i < x_values.size(); i++) {
        cout << x_values[i] << "\t\t" << y_values[i] << "\n";
    }
}

int main() {
    double y0 = 1.0;      // Initial condition
    double x0 = 0.0;      // Start value of x
    double x_end = 5.0;   // End value of x
    double h = 0.1;       // Step size

    rk4(y0, x0, x_end, h);
}
