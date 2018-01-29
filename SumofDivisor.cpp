#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 24

#define size 50

int prime[size], status[MAX];
int factor[size], alpha[size], sumOfdivis[MAX], arr[size];
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

void sumOfDivisor()
{
    int n, a, sum;
    n = MAX;
    int i, j, f;
    int sq= sqrt(n);
    f=0;
    int d, count;
    d=0;
    a=0;
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
        {
            alpha[d++] = count+1;
            arr[a++] = prime[i];
        }
    }
    if(n>1)
    {
        factor[f++] = n;
        count =1;
        alpha[d++] = count+1;
        arr[a++] = prime[i];
    }
    /*cout <<"prime Factorization2 is: ";
    for(i=0; i<f; i++)
    {
        cout << factor[i] << " ";
    }
    cout << endl;
    cout << "number of prime divisor is : " << f << endl;*/
    int ans =1;
    for(i=0; i<d; i++)
    {
        cout << alpha[i] << " ";
    }
    cout << endl;
    for(i=0; i<a; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    sum = 1;
    for(i=0; i<a; i++)
    {
        for(j=1; j<=alpha[i]; j++)
        {
            sum*= alpha[i];
              //cout << "sum is : " << sum << endl;
        }
    }
    cout << "sum is : " << sum << endl;

}
int main()
{
    siv();
    sumOfDivisor();
    return 0;
}

