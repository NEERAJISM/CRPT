#include <iostream>
using namespace std;
int mod_inv(int a,int m) {
	int i;
	for(i=0;i<m;++i) {
		if((a*i)%m==1) {
			break;
		}
	}
	return i;
}
void point_add(int x1,int y1,int x2,int y2,int &x3,int &y3,int a,int p) {
	int slope;
	if(x1==x2&&y1==y2) {
		slope=((3*x1*x1+a)*mod_inv(2*y1,p))%p;

	} else {
		slope=((x2-x1)*mod_inv(y2-y1,p))%p;

	}
	if(slope<0){
		slope+=p;
	}
	x3=(slope*slope-x2-x1)%p;
	if(x3<0){
		x3+=p;
	}
	y3=(slope*(x1-x3)-y1)%p;
	if(y3<0) {
		y3+=p;
	}
}
void mult(int x1,int y1,int c,int &x4,int&y4,int a,int p) {
	int x2=x1;
	int y2=y1;
	int x3,y3;
	for(int i=0;i<c;++i) {
		point_add(x1,y1,x2,y2,x3,y3,a,p);
		x2=x3;
		y2=y3;
	}
	cout<<x3<<" "<<y3<<endl;
	x4=x3%p;
	if(x4<0){
		x4+=p;
	}
	y4=y3%p;
	if(y4<0) {
		y4+=p;
	}
}
int main(){
	int a,b,p,x1,y1,x2,y2,x3,y3;
	cout<<"Enter the value of a b and p ";
	cin>>a>>b>>p;
	cout<<"Enter P and Q ";
	cin>>x1>>y1>>x2>>y2;
	point_add(x1,y1,x2,y2,x3,y3,a,p);
	mult(x1,y1,2,x3,y3,a,p);
	point_add(x1,y1,x3,y3,x3,y3,a,p);
	cout<<x3<<" "<<y3<<endl;
	mult(x1,y1,3,x3,y3,a,p);
	//cout<<x3<<" "<<y3;
}
