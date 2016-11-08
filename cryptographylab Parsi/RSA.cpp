#include<bits/stdc++.h>
using namespace std;
int power(int a, int d, int n)
{
    if(d==0)return 1;
    int num = power(a,d/2,n);
    if(d%2==0)return (num*num)%n;
    if(d%2==1)return ((num*num)%n )* a%n;
}
int main()
{
    int p,e,n;
    cin>>p>>e>>n;
    int c=power(p,e,n);
    cout<<c<<endl;
}
