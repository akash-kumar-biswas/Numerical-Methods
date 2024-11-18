
//Numerical Integration using Trapezoidal ,simpson 1/3 and simpson 3/8 rule

#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x*x*x;  
}

double trapezoidal_rule(double a,double b,int n) {
    double h=(b-a)/n;
    double sum=f(a)+f(b);
    for (int i=1;i<n;i++) {
        sum+=2*f(a+i*h);
    }
    return sum*h/2;
}

double simpson_1_3_rule(double a,double b,int n) {
    if (n%2!=0){
        cerr<<"Simpson's 1/3 rule requires an even number of subintervals!"<<endl;
        return -1; 
    }

    double h=(b-a)/n;
    double sum=f(a)+f(b);
    for (int i=1;i<n;i++) {
       if(i%2!=0) sum+=4*f(a+i*h);
       else sum+=2*f(a+i*h);
    }
    return sum*h/3;
}

double simpson_3_8_rule(double a, double b, int n) {
    if (n%3!=0){
        cerr<<"Simpson's 3/8 rule requires the number of subintervals to be a multiple of 3"<<endl;
        return -1;
    }

    double h=(b-a)/n;
    double sum=f(a)+f(b);
    for (int i=1;i<n;i++){
        if(i%3!=0) sum +=3*f(a+i*h);
        else sum +=2*f(a+i*h);
    }
    return sum*h*3/8;
}

int main(){
    double a=0.0;  
    double b=1.0;  
    int n=6; 

    double trap_result=trapezoidal_rule(a,b,n);
    cout <<"Trapezoidal Rule Result: "<<trap_result<<endl;

    double simpson1_result=simpson_1_3_rule(a,b,n);
    if (simpson1_result!=-1) {
        cout<<"Simpson's 1/3 Rule Result: "<<simpson1_result<<endl;
    }

    double simpson38_result=simpson_3_8_rule(a,b,n);
    if (simpson38_result!=-1){
        cout<<"Simpson's 3/8 Rule Result: "<<simpson38_result<<endl;
    }
    return 0;
}
