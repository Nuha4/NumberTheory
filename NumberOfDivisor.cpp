#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 24
#define size 50

int prime[size], status[MAX];
int factor[size], divis[size];
int p;

void siv()
{
    int n, i, j;
    n=MAX;
    int sq= sqrt(n);
    for(i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(j=i*i; j<=n; j+=(i+i))
            {
                status[j]=1;
            }
        }
    }
    prime[0]=2;
    p=1;
    for(i=3; i<=n; i+=2)
    {
        if(status[i]==0)
        {
            prime[p++] = i;
        }
    }
    /*cout <<"p is " << p << endl;
    for(i=0; i<p; i++)
    {
        cout << "prime " << prime[i] << endl;;
    }*/
}

/*void primeFactor1()
{
    int n;
    n = MAX;
    int i, j, d;
    d=0;
    for(i=0; i<p; i++)
    {
        while(n%prime[i]==0)
        {
            factor[d++] = prime[i];
            n /= prime[i];
        }
    }
    cout <<"prime Factorization1 is : ";
    for(i=0; i<d; i++)
    {
        cout << factor[i] << " ";
    }
    cout << endl;
}*/

void primeFactor2()
{
    int n;
    n = MAX;
    int i, j, f;
    int sq= sqrt(n);
    f=0;
    int d, count;
    d=0;

    for(i=0; prime[i]<=sq; i++)
    {
        count =0;
        while(n%prime[i]==0)
        {
            factor[f++] = prime[i];
            n /= prime[i];
            count++;
        }
        if(count!=0)
            divis[d++] = count+1;
    }
    if(n>1)
    {
        factor[f++] = n;
        count =1;
        divis[d++] = count+1;
    }
    cout <<"prime Factorization2 is: ";
    for(i=0; i<f; i++)
    {
        cout << factor[i] << " ";
    }
    cout << endl;
    cout << "number of prime divisor is : " << f << endl;
    int ans =1;
    for(i=0; i<d; i++)
    {
        ans *=divis[i];

    }
    cout << "number of divisor is : " << ans << endl;
    cout << endl;

}
int main()
{
    siv();
    //primeFactor1();
    primeFactor2();
    return 0;
}

