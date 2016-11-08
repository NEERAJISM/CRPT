#include<bits/stdc++.h>
using namespace std;

int power(int alp , int n)
{
	if( n == 0)
		return 1;

	long long int tmp = power(alp, n/2);

	if(n%2 == 0)
	{
		return (tmp*tmp)%26;
	}
	else
	{
		return (((tmp*alp)%26)*tmp)%26;
	}
}

int main()
{
	string s,p,x;
	char c;
	int alp,bet,tmp,tz = (int) 'Z',tt;
	//cout<<tz;
	cout<<"enter the plain text : ";
	cin>>s;

	cout<<"enter the alpha value : ";
	cin>>alp;

	if(__gcd(alp,26) == 1)
	{
		int n = s.length();
		for(int i=0;i<n;i++)
		{
				tmp = (((int)s[i]-65)*alp)%26;

				tmp = 65 + tmp;
				c = (char)tmp;
				p.push_back(c);
		}
		cout<<"\n THE CIPHERED TEXT IS : "<<p;

		for(int i=0;i<n;i++)
		{
				tmp = ((int)p[i]-65)%26;

				if(tmp < 0)
					tmp+=26;

				//finding the inverse
				int ii;
				for(ii = 0;ii<26;ii++)
				{
					int flg = (alp*ii)%26;
					if(flg == 1)
						break;
				}

				tt = (tmp * (ii)%26)%26;
			   	tt+=65;
				c = (char)tt;
				x.push_back(c);
		}

		cout<<"\n th deciphered text is : "<<x;
	}
	else
	{
		cout<<"\ngcd is not 1 so ciphering ca't be done";
	}
}
