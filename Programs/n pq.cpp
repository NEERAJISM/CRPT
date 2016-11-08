#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k,n,p,q,phi;
	cin>>n;
	
	if(n%2 == 0)
	{
		p = 2;
		q = n/2;
		cout<<"p = "<<p<<" q = "<<q<<" phi = "<<(p-1)*(q-1);
		
	}
	else
	{
		for(i=3;i<=sqrt(n);i+=2)
		{
			if(n%i == 0)
			{
				cout<<"p = "<<i<<" q = "<<n/i<<" phi = "<<(p-1)*(q-1);
				break;
			}
		}
	}
	
	return 0;
}
