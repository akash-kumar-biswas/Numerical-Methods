#include <bits/stdc++.h>
#define toler .000001
using namespace std;

double f(double x) {
    return x*x + x -6; 
}

void secantMethod(double x0, double x1,int maxIter) {
    double x2; 
    int iter = 0;
    while (iter < maxIter) {

        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;

        if(fabs(f(x2))<toler) break;

        iter++;
    }

    cout<<iter<<endl;
    cout<<"Root: "<<x2<<endl;
}

int main() {
    double x0 = 5.0; 
    double x1 = 9.0; 
    int maxIter = 1000; 
    secantMethod(x0, x1,maxIter);

    return 0;
}
