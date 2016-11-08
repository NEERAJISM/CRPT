#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,p,x;
	char c;
	int t,tmp,tz = (int) 'Z';
	//cout<<tz;
	cout<<"enter the plain text : ";
	cin>>s;
	
	cout<<"enter the key value : ";
	cin>>t;
	
	int n = s.length();
	for(int i=0;i<n;i++)
	{
			tmp = (int)s[i] + t;
			
			if(tmp>tz)
			    tmp = 64 + tmp-tz;
			   
			//cout<<tmp<<"*\n"; 
			c = (char)tmp;
			p.push_back(c);	
	}
	cout<<"\n THE CIPHERED TEXT IS : "<<p;
	
	for(int i=0;i<n;i++)
	{
			tmp = (int)p[i] - t;
			
			if(tmp<65)
			    tmp = 90-65+tmp;
			   
			//cout<<tmp<<"*\n"; 
			c = (char)tmp;
			x.push_back(c);	
	}
	
	cout<<"\n th deciphered text is : "<<x;
}
