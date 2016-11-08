#include<bits/stdc++.h>
using namespace std;
int arr[12]={1,3,5,7,9,11,15,17,19,21,23,25};
int main()
{
    string p;
    int a,b;
    cin>>p>>a>>b;
    string c;
    for(int i=0;i<p.length();i++)
    {
        c.push_back(((a*(p[i]-'a')+b)%26)+'a');
    }
    cout<<c<<endl;
    cout<<"bruteforce"<<endl;
    for(int i=0;i<12;i++)
    {

        for(int j=1;j<=26;j++)
        {
            string temp;
            for(int k=0;k<c.length();k++)
            {
                temp.push_back ((arr[i]*(c[k]-'a'-j+26))%26+'a');
            }
            cout<<temp<<endl;
        }
    }

}
