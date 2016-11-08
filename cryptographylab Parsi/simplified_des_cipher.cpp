#include<bits/stdc++.h>
using namespace std;
string key;
vector<vector<string> > s1,s2;
vector<vector<string> > init()
{
    int i,j;
	vector<vector<string> > ss1;
	for(i=0;i<2;i++)
	{
		vector<string> vec;
		for(j=0;j<8;j++)
		{
			string s;
			cin>>s;
			vec.push_back(s);
		}
		ss1.push_back(vec);
	}
	return ss1;
}
int convert(string str)
{
	int n=0,i=0;
	while(i<str.length())
	 n=n*2+str[i++]-'0';
	return n;
}
string cipher(string l,string r)
{
	for(int i=0;i<2;i++)
	{
		string k;
		int j,count=0;
		for(j=i;count<8;j=(j+1)%9,count++)
		k.push_back(key[j]);
		cout<<k<<endl;
		string temp,temp1;
		temp.push_back(r[3]);
		temp.push_back(r[2]);
		temp=r.substr(0,2)+temp+temp+r.substr(4,2);
		cout<<temp<<endl;
		for(int m=0;m<8;m++)
		 temp[m]=((temp[m]-'0')^(k[m]-'0'))+'0';
		int row,col;
		row=temp[0]-'0';
		col=convert(temp.substr(1,3));
		temp1+=s1[row][col];
		row=temp[4]-'0';
		col=convert(temp.substr(5,3));
		temp1+=s2[row][col];
		for(int m=0;m<6;m++)
		  temp1[m]=((temp1[m]-'0')^(l[m]-'0'))+'0';
		l=r;
		r=temp1;
		cout<<l<<" "<<r<<endl;
	}
	return r+l;
}
int main()
{
	string str;
	cin>>str;
	int n=str.length();
	s1=init();
	s2=init();
	int i=n/12,j=0;
	key="111000111";
	while(i--)
	{
	
	    string l=str.substr(j,6);
	    j+=6;
	    string r=str.substr(j,6);
	    j+=6;
		cout<<cipher(l,r);
	}
	return 0;
}
