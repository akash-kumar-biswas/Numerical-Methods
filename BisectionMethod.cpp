#include <bits/stdc++.h>
#define EPSILON .000001
using namespace std;

double f(double x) {
    return x*x + x -6; 
}

void findInterval(double *a, double *b, double step) {
    *b = *a + step;

    while (1) {
        if (f(*a) * f(*b) < 0) {
            return;
        }
        *a = *b;
        *b = *a + step;
    }
}

void bisectionMethod(double a, double b, int maxIter) {
    double c; 
    int iter=0;

    while (fabs((b-a)) >= EPSILON &&  iter<maxIter) { 
        c = (a + b) / 2; 

        if (f(c) == 0 ) {
            cout<<"Root : "<< c <<endl;
        } 

        else if (f(a) * f(c) < 0) {
            b = c;
        } 
        else {
            a = c;
        }
        iter++;
    }
    cout<<iter<<"\n";
    cout<< "Root : " << c; 
}

int main() {
    double a = 1;       
    double b;
    int maxIter = 200;    
    findInterval(&a,&b,.1);
    bisectionMethod(a, b, maxIter);
    return 0;
}
