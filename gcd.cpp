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
    return 0;
}
