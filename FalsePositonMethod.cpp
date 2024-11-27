#include<bits/stdc++.h>
#define EPSILON 0.000001 
using namespace std;

double f(double x) {
    return x*x + x - 6;
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

void falsePosition(double a, double b, int maxIter) {
    
    double c ; 
    int iter = 0;

    while (fabs(f(c))>=EPSILON && iter<maxIter) {
      
        c = b-(f(b)*(b-a))/(f(b)-f(a));

        if (f(c)==0){
            cout << "Root : " << c << endl;
            return;
        }

        else if (f(c)*f(a)<0) b = c;
        else a = c;

        iter++;
    }
    cout<<iter<<endl;
    cout << "Root : " << c << endl;
}

int main() {
    double a=1, b=4;
    int maxIter = 20;
    findInterval(&a, &b, 0.1);
    cout<<a<<" "<<b<<endl;
    falsePosition(a, b, maxIter);
    return 0;
}
