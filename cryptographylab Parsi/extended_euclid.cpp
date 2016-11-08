#include<bits/stdc++.h>
using namespace std;

int euclid(int r1,int r2)
{
    int q=r1/r2;
    int i=r1;
    int r=r1%r2;
    int t1=0;
    int t2=1;
    int t=t1-q*t2;
    while(r2>0)
    {

        r1=r2;
        r2=r;
        if(r2<=0)
        {
            break;
        }
        q=r1/r2;
        r=r1%r2;
        t1=t2;
        t2=t;
        t=t1-q*t2;
    }
    if(t1<0)
    {
        return i-t1;
    }
    else
    {
        return t1;
    }
}
int main()
{

    int r1,r2;
    cin>>r1>>r2;
    printf("%d\n",euclid(r1,r2));
}
