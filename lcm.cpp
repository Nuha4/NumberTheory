#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 10000
#define size 1000

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    int lcm, a, b;
    lcm = (a*b)/gcd(a,b);
    cout << "LCM is : " << lcm << endl;
    return 0;
}
