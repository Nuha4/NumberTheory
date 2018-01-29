#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 100
#define size 50
int prime[size], status[MAX];

void siv()
{
    int n, i, j, p;
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
    cout <<"p is " << p << endl;
    for(i=0; i<p; i++)
    {
        cout << "prime " << prime[i] << endl;;
    }

}

int main()
{
    siv();
    return 0;
}
