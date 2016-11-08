#include<bits/stdc++.h>
using namespace std;

int main()
{
    string p;
    string c;
    cin>>p;
    int k;
    cin>>k;
    for(int i=0;i<p.length();i++)
    {
        c.push_back((((p[i]-'a')+k)%26)+'a');
    }
    int i;
    for(i = 0 ; i < 26; i++)
    {
        string temp = c;
        for(int j = 0 ; j < c.length(); j++)
        {
            temp[j] = ((temp[j]-'a'-i + 26)%26 + 'a');
        }
        cout<<temp<<endl;
    }

}
