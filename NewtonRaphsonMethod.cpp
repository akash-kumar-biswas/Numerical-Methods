#include <bits/stdc++.h>
#define toler .000001
using namespace std;

double f(double x) {
    return x*x + x -6;
}

double fPrime(double x) {
    return 2 * x + 1;
}

void newtonRaphson(double x0,int maxIter) {
    int iter=0;

    while (iter < maxIter) {

        double x1=x0-f(x0)/fPrime(x0);

        if (fabs(x1-x0) < toler) {
            break; 
        }
        
        x0=x1;
        iter++;
    }

    cout<<iter<<endl;
    cout<<x0<<endl;
}

int main() {
    double x0=1;
    int maxIter=100;

    newtonRaphson(x0, maxIter);

    return 0;
}
