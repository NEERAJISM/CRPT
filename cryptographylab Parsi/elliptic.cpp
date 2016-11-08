#include<bits/stdc++.h>
using namespace std;

int main()
{

    int b,c ;
    scanf("%d%d",&b,&c);
    cout<<"enter 2 points"<<endl;
    double x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2&&y1==y2)
    {
        double m=(3*x1*x1+b)/(2*y1);
        double x3=m*m-x1-x2;
        double y3=m*(x1-x3)-y1;
    }
    else{
        double m= (y2-y1)/(x2-x1);
        double x3=m*m-x1-x2;
        double y3=m*(x1-x3)-y1;
    }
    cout<<x3<<" "<<y3<<endl;
}
