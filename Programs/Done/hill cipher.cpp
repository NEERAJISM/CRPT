/*
* this program is brought to you by : Neeraj & Paras
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k1,k2,k3,k4,d,val = (int)'a',tmp,tmp1,n;
	int m1[2][2],m2[2][2];
	string s,is,ds;

	cout<<"enter the value of  k1, k2, k3 k4 : ";
	cin>>k1>>k2>>k3>>k4;
	d = k1*k4 - k2*k3;
	cout<<"\nthe determinant is : "<<d<<"\n";

	if(d!=0 && __gcd(d,26) == 1)
	{
			m1[0][0] = k1;
			m1[0][1] = k2;
			m1[1][0] = k3;
			m1[1][1] = k4;

			m2[0][0] = k4;
			m2[0][1] = -k2;
			m2[1][0] = -k3;
			m2[1][1] = k1;

			cout<<"enter the plaintext : ";
			cin>>s;
			n = s.length();
			for(int i=0;i<=n-2;i+=2)
			{
				int a1 = (int)s[i]-val,b1 =(int)s[i+1]-val;

				is.push_back((char)(97+(k1*a1 + k2*b1)%26));
				is.push_back((char)(97+(k3*a1 + k4*b1)%26));
			}

			 cout<<"\n the hill cipher tex is : "<<is;

			k1= m2[0][0];
			k2= m2[0][1];
			k3= m2[1][0];
			k4= m2[1][1];

			if(d < 0)
			{
				d = -d;

				m2[0][0] *= (-1);
				m2[0][1] *= (-1);
				m2[1][0] *= (-1);
				m2[1][1] *= (-1);
			}

				int i,flg,alp = d;
				for(i=0;i<=25;i++)
				{
					flg = (alp*i)%26;
					if(flg == 1)
						break;
				}
				cout <<"\nd = "<<i<<"\n";
				d = i;

			for(int i=0;i<=n-2;i+=2)
			{
				int a1 = (int)is[i]-val,b1 =(int)is[i+1]-val;

				int tt = ((m2[0][0]*a1 + m2[0][1]*b1)*d)%26;

				if(tt < 0)
					tt+=26;
				ds.push_back((char)(97+tt));

				tt = ((m2[1][0]*a1 + m2[1][1]*b1)*d)%26;
				if(tt < 0)
					tt+=26;
				ds.push_back((char)(97+tt));
			}

			 cout<<"\n the decrypted plain text is : "<<ds;
	}
	return 0;
}
