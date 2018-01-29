#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 100
#define size 1000

int N, np;
int p[MAX+10], e[MAX+10]; // product of p[i]^e[i]
int primeFact1(int x)
{
    int n =x;
    int i;
    np=0;
    if(x<=1) return 1;

    if(n%2==0) p[np] = 2;
    while(!(n%2)) n/=2, e[np]++;
    if(e[np]) np++;

    // i=0; prime[i]*prime[i]<n ;i++
    // i=0 prime[i]<=n; i++

    for(i=3; i<=n; i+=2)
    {
        if(n%i==0) p[np] = i;
        while(n%i==0) e[np]++, n/=i;
        if(e[np]) np++;
    }
    if(n>1) p[np] = n, e[np] = 1, np++;

}

int main()
{
    int n;
    cin >> n;
    primeFact1(n);
    for(int i=1; i<=np; i++)
    {
        printf("%d ^ %d " , p[i], e[i]);
    }
    return 0;
}
