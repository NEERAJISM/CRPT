#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,pn;
    cin>>n>>pn;
    int s=n-pn+1;
    int p=(s+(sqrt(s*s-4*n)))/2;
    int q=(s-(sqrt(s*s-4*n)))/2;
    cout<<p<<" "<<q<<endl;
}
