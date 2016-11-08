#include <bits/stdc++.h>
using namespace std;

int power(int alp , int n)
{
	if( n == 0)
		return 1;

	int tmp = power(alp, n/2);

	if(n&1)
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
	int a,b,n,tmp,tt;
	string x;
	char s[] = "UFQFAU OMF FNDO VHEE";
	char c;

	cout<<"Brute force attack (312)\n\n";

	cout<<"enter the cipher text : ";
	//scanf("%s",s);
	n = strlen(s);
	n = 20;
	for(a = 1;a<=25;a++)
	{
		if(__gcd(a,26) != 1)
			continue;

		for(b=0;b<26;b++)
		{
			cout<<"\n THE De-CIPHERED TEXT IS : ";

			for(int i=0;i<n;i++)
			{
				if(s[i] == ' ')
				{
					x.push_back(' ');
					continue;
				}

				tmp = ((int)s[i]-65 - b)%26;

				if(tmp < 0)
					tmp+=26;

				int ii;
				for(ii = 0;ii<26;ii++)
				{
					int flg = (a*ii)%26;
					if(flg == 1)
						break;
				}

				tt = (tmp * (ii)%26)%26;
			   	tt+=65;
				c = (char)tt;
				x.push_back(c);
			}

			cout<<x<<"\n";
			if(x == "DEFEND THE EAST WALL")
			{
				break;
			}
			x.clear();
		}

		if(x == "DEFEND THE EAST WALL")
			{
				break;
			}
	}
	return 0;
}
//UFQFAU OMF FNDO VHEE
