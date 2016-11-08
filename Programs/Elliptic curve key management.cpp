#include<stdio.h>
#include<conio.h>
int a=2,b=1;//coefficents of polynomial
int n=17;
int count=1;
int x=5,y=1;//Generator points
int inverse(int);
int findorder(int,int);
int pointmul(int,int,int,int,int &,int &);
void BobKeysharing(int,int,int,int&,int&);
void AliceKeysharing(int,int,int,int&,int&);
void keycalulation(int,int,int);

int main()
{	
	int count;
	printf("\nElliptic curve coefficents a=%d ,b =%d",a,b);
	printf("\nGenerator point is G(%d,%d)\n",x,y);
	int x2=x,y2=y;
	int d1,d2,order;
	int x3,y3,x4,y4;
	count=findorder(x,y);
	printf("\n\norder of generator is %d",count);	
	order=count;
	
	
	printf("\n*********Key Exchange*******\n");
	
	printf("\n\nBobs key calculation\n");
	printf("Bob selects a random point between 1 to %d:",order-1);
	scanf("\n %d",&d1);
	BobKeysharing(d1,x,y,x3,y3);
	printf("\ncalculated point by Bob \n x=%d and y=%d",x3,y3);
	
	printf("\n\nAlice key calculation\n");
	printf("Alice selects a random point between 1 to %d:",order-1);
	scanf("\n %d",&d2);
	AliceKeysharing(d2,x,y,x4,y4);
	printf("\ncalculated point by Alice \n x=%d and y=%d",x4,y4);
	
	printf("\n\n\n\n***key calculation****");
	
	printf("\n key calculation by Bob");
	keycalulation(d1,x4,y4);
		
	
	printf("\n key calculation by Alice");
	keycalulation(d2,x3,y3);
	
	
	return 0;
}

int findorder(int x2,int y2)
{
	int slope;
	int x1,y1,x3,y3;
	x1=x,y1=y;
	if(count>1&&(x1==x2))
	return ++count;
	count=pointmul(x1,y1,x2,y2,x3,y3);
	printf("\n points on curve is (%d,%d)",x3,y3);
	findorder(x3,y3);	
}


int pointmul(int x1,int y1,int x2,int y2,int &x3,int &y3)
{
	int slope;
	if(x1==x2 && y1==y2)
	{
		slope=((3*x1*x1+a)*inverse(2*y1))%n;
		if(slope<0)
		slope=(slope+n)%n;			
	}
	else
	{
		slope=((y2-y1)*inverse(x2-x1))%n;
		if(slope<0)
		slope=(slope+n)%n;		
	} 
	
	x3=(slope*slope-x1-x2)%n;
	if(x3<0)
	x3=(x3+n)%n;
	y3=(slope*(x1-x3)-y1)%n;
	if(y3<0)
		y3=(y3+n)%n;
	return ++count;
}

int inverse(int a)
{
	if(a<0)
	a=(a+n)%n;	
	int r,r1=a,r2=n;
	int s1=1,s2=0,s;
	int t1=0,t2=1,t,q;
	while(r2>0)
		{
			q=r1/r2;
			r=r1-q*r2;
			r1=r2;r2=r;
			s=s1-s2*q;
			s1=s2;s2=s;
			t=t1-t2*q;
			t1=t2;t2=t;			
		}
		s=s1;t=t1;
		return s;	
}

void BobKeysharing(int d1,int x,int y,int &x3,int &y3)
{
	int i;
	int x1,y1,x2,y2;
	x1=x,y1=y;
	x2=x,y2=y;
	pointmul(x1,y1,x2,y2,x3,y3);
	for(i=1;i<d1;i++)
	{
			x1=x,y1=y;
			x2=x3,y2=y3;
			pointmul(x1,y1,x2,y2,x3,y3);
	}	
			
}

void AliceKeysharing(int d2,int x,int y,int &x3,int &y3)
{
	int i;
	int x1,y1,x2,y2;
	x1=x,y1=y;
	x2=x,y2=y;
	pointmul(x1,y1,x2,y2,x3,y3);
	for(i=1;i<d2;i++)
	{
			x1=x,y1=y;
			x2=x3,y2=y3;
			pointmul(x1,y1,x2,y2,x3,y3);
	}	
		 	
}

void keycalulation(int d,int x,int y)
{
int i;
	int x1,y1,x2,y2,x3,y3;
	x1=x,y1=y;
	x2=x,y2=y;
	pointmul(x1,y1,x2,y2,x3,y3);
	for(i=1;i<d;i++)
	{
			x1=x,y1=y;
			x2=x3,y2=y3;
			pointmul(x1,y1,x2,y2,x3,y3);
	}	
	printf("\n x=%d and y=%d",x3,y3); 
	
}
