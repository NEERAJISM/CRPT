#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;

//multiplication of long long
ULL mulmod(ULL a, ULL b, ULL c)
{
	ULL x = 0, y = a%c;

	while(b>0)
    {
		if(b&1)
            x = (x+y)%c;

		y = (y<<1)%c;
		b >>= 1;
	}

	return x;
}

/*
    the idea is to use mulmod when 2 long long
    multiply
*/

ULL pow(ULL a, ULL b, ULL c){

	if(b == 0)
        return 1;

	if(b == 1)
        return a%c;

    if(b == 2)
        return mulmod(a,a,c);

    ULL tmp = pow(a,b/2,c);
    ULL tmp2 = mulmod(tmp,tmp,c);

    if(b%2 == 0)
        return tmp2;
    else
        return  mulmod(tmp2,a,c);
}

bool miller_rabin(ULL p, int it)
{
	if(p<2)
        return false;

	if(p==2)
        return true;

	if((p&1)==0)
        return false;

	ULL d = p-1;

	while(d%2==0)
        d >>= 1;

	while(it--)
    {
		ULL a = rand()%(p-1)+1;
		ULL tmp = d;
		ULL md = pow(a,tmp,p);

		while(md!= 1 && md!=p-1 && tmp != p-1)
        {
            md = mulmod(md,md,p);
            tmp *= 2;
		}

        if(md!=p-1 && tmp%2 == 0)
            return false;

	}
	return true;
}

int main()
{
	int T;
	unsigned long long N;
	scanf("%d",&T);

	while(T--){
		scanf("%llu",&N);
		printf("%s\n",miller_rabin(N,4)? "YES" : "NO");
	}

	return 0;
}
