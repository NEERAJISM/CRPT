#include<bits/stdc++.h>
using namespace std;
int power(int a,int d,int n)
{
    if(d==0)  return 1;

    int num=power(a,d/2,n);
    if(d%2==0)  return (num*num)%n;
    if(d%2==1)  return ((num*num)%n)*a%n;
}
int findodd(int n)
{
    int k=n;
    while(n%2==0)
    {
        n=n/2;
    }
    return n;
}
bool millertest(int n, int d)
{
    int a = rand()%(n-2)+2;
    int x=power(a,d,n);
    if(x==1||x==n-1)
    {
        return true;
    }
    while(d!=n-1)
    {
        x=(x*x)%n;
        if(x==1)return false;
        if(x==n-1)return true;
    }

}
bool isPrime(int n, int k)
{

    if(n==2||n==3)
    {

        return true;
    }
    if(n%2==0)
    {
        return false;
    }
    int d=findodd(n-1);
    while(k--)
    {

        if(millertest(n,d)==false)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    if(isPrime(n,100))
    {
        printf("prime\n");
    }
    else{
        printf("composite\n");
    }
}
