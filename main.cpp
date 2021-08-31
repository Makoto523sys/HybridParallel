#include<iostream>
#include<cmath>

double f(double);
const long int N = 1e9;

int main(int argc, char **argv){
    double ans;
    double a, b;
    a = 0.0; b = 1.0;
    double dx = (b-a) / N;
    ans = 0.0;


    for(int i = 0; i < N; i++){
        ans += dx * f(dx * i);
    }
    std::cout << std::abs(M_PI / 8 - ans) << std::endl;
    return 0;
}

double f(double x){
    return x * std::asin(x);
}
