#include<bits/stdc++.h>
using namespace std;

int main()
{
    string p;
    cin>>p;
    string key;
    cin>>key;
    string c;
    int j=0;
    for(int i=0;i<p.length();i++)
    {
        c.push_back(((p[i]+key[j]-'a'-'a')%26)+'a');
        j=(j+1)%key.length();
    }
    cout<<c<<endl;
    string d;
    j=0;
    for(int i=0;i<c.length();i++)
    {
         d.push_back(((c[i]-key[j]+26)%26)+'a');
         j=(j+1)%key.length();
    }
    cout<<"decrypt as "<<d<<endl;
}
