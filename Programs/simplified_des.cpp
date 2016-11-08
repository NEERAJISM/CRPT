#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ptext[12],key[9],i,erl[8],l1[6],r1[6],l2[6],r2[6],val;
    string s1[2][8]={"101","010","001","110","011","100","111","000","001","100","110","010","000","111","101","011"};
    string s2[2][8]={"100","000","110","101","111","001","011","010","101","011","000","111","110","010","001","100"};
    cout<<"enter 12 bit plain text";
	for(i=0;i<12;i++)
	  cin>>ptext[i];
	cout<<"enter the 9 bit key for encryption";
	for(i=0;i<9;i++)
	  cin>>key[i]; 
	int k=0;
	for(i=6;i<12;i++)
	  l1[k++]=ptext[i];

	 erl[0]=ptext[6];
	 erl[1]=ptext[7];
	 erl[2]=ptext[9];
	 erl[3]=ptext[8];
	 erl[4]=ptext[9];
	 erl[5]=ptext[8];
	 erl[6]=ptext[10];
	 erl[7]=ptext[11];
	 
	 for(i=0;i<8;i++)
       erl[i]=erl[i]^key[i];
      
	 string frk="";  
     val=erl[1]*4+erl[2]*2+erl[3]*1;
	 //cout<<val<<" ";  
	frk=frk+s1[erl[0]][val];
	  //cout<<frk<<" ";
	  val=erl[5]*4+erl[6]*2+erl[7]*1;
	    //cout<<val<<" "; 
	  
	frk=frk+s2[erl[4]][val];
	  //cout<<frk<<" ";
	 
	 for(i=0;i<6;i++)       
	   {
	      r1[i]=frk[i]-'0';
	      r1[i]=r1[i]^ptext[i];
	  }
   
   /*for(i=0;i<6;i++)
     cout<<l1[i]<<" ";
   cout<<"\n";  
   for(i=0;i<6;i++)
     cout<<r1[i]<<" ";*/  
    int key1[9];
     k=0; 
      for(i=1;i<9;i++)
        key1[k++]=key[i];
      key1[k]=key[0];  
	
	//for(i=0;i<9;i++)
	  //cout<<key1[i]<<" ";
	k=0;
	for(i=0;i<6;i++)
	  l2[i]=r1[i];

	 erl[0]=r1[0];
	 erl[1]=r1[1];
	 erl[2]=r1[3];
	 erl[3]=r1[2];
	 erl[4]=r1[3];
	 erl[5]=r1[2];
	 erl[6]=r1[4];
	 erl[7]=r1[5];
	 
	 for(i=0;i<8;i++)
	   cout<<erl[i]<<" ";
	 for(i=0;i<8;i++)
       erl[i]=erl[i]^key1[i];
      
	 frk="";  
     val=erl[1]*4+erl[2]*2+erl[3]*1;  
	frk=frk+s1[erl[0]][val];
	 cout<<frk<<" ";
	  val=erl[5]*4+erl[6]*2+erl[7]*1;
	frk=frk+s2[erl[4]][val];
	 
	 cout<<frk<<" ";
	 cout<<"\n";
	 for(i=0;i<6;i++)       
	   {
	      r2[i]=frk[i]-'0';
	      r2[i]=r2[i]^l1[i];
	  }
   
     for(i=0;i<6;i++)
   	     cout<<l2[i];
   	 for(i=0;i<6;i++) 
		 cout<<r2[i];

return 0;		    
}
