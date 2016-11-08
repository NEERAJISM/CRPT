#include <bits/stdc++.h>
using namespace std;

#define l long long

int main(){
	long long e,n;cin>>e>>n;

	double x=(double)e/(double)n;
	vector<long long>v;
	for(int i=0;i<30;i++){
		//if(x==0)break;
		x=1.0/x;
		int u=x;
		v.push_back(u);
		l fnum=0,fden=1;
		for(int j=v.size()-1;j>=0;j--){
			l a=v[j];
			//cout<<v[j]<<" ";
			l valnum=fden;
			l valden=a*fden+fnum;

			fnum=valnum;
			fden=valden;
		}
		cout<<fnum<<"/"<<fden<<endl;
		cout<<endl;
		x=x-u;
	}
}
