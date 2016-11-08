#include<bits/stdc++.h>
using namespace std;
string s1[2][8]={{"101","010","001","110","011","100","111","000"},
{"001","100","110","010","000","111","101","011"}};
string s2[2][8]={{"100","000","110","101","111","001","011","010"},
{"101","011","000","111","110","010","001","100"}};
string expand(string R)
{
    string x;
    x.push_back(R[0]);
    x.push_back(R[1]);
    x.push_back(R[3]);
    x.push_back(R[2]);
    x.push_back(R[3]);
    x.push_back(R[2]);
    x.push_back(R[4]);
    x.push_back(R[5]);
    return x;
}
string f(string R, string K)
{
    string x=expand(R);
    for(int i=0;i<x.size();i++)
    {
        int ch=(x[i]-'0')^(K[i]-'0');
        x[i]=(char)(ch+'0');
    }
    string fh=x.substr(0,4);
    string nh=x.substr(4,4);
    int h=(fh[1]-'0')*4+(fh[2]-'0')*2+(fh[3]-'0')*1;
    string new1=s1[fh[0]-'0'][h];
    int g=(nh[1]-'0')*4+(nh[2]-'0')*2+(nh[3]-'0')*1;
    string new2=s2[nh[0]-'0'][g];
    new1.append(new2);
    return new1;

}
string encrypt(string p,string k1)
{
    string L,R;
    L=p.substr(0,6);
    R=p.substr(6,6);
    string X=f(R,k1);
    for(int i=0;i<L.size();i++)
    {
        int ch=(L[i]-'0')^(X[i]-'0');
        X[i]=(char)(ch+'0');
    }
    R.append(X);
    return R;
}
int main()
{
    string p;
    cin>>p;
    string k1="11100011";
    string ctext;
    ctext=encrypt(p,k1);
    cout<<ctext;
}

