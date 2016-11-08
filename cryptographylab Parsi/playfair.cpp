#include<bits/stdc++.h>
using namespace std;
void get_pos(char key[5][5],char p,int* r, int* c)
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(key[i][j]==p)
            {
                *r=i;
                *c=j;
            }
        }
    }
    r=0;
    c=0;
    return;
}
int main()
{
    char key[5][5];
    for(int i=0;i<5;i++)
    {

        for(int j=0;j<5;j++)
        {
            char c;
            scanf("%c",&key[i][j]);
            scanf("%c",&c);
        }
    }
    for(int i=0;i<5;i++)
    {

        for(int j=0;j<5;j++)
        {

            printf("%c ",key[i][j]);

        }
        printf("\n");
    }
    string ptext,ctext;
    string r="x";
    cout<<"enter plain text"<<endl;
    cin>>ptext;
    for(int i=0;i<ptext.length();i=i+2)
    {
        if(ptext[i]==ptext[i+1])
        {
            ptext.insert(i+1,r);
        }
    }
    if(ptext.length()%2!=0)
    {
        ptext.append(r);
    }
    cout<<ptext<<endl;
    for(int i=0;i<ptext.length();i=i+2)
    {
        int r1,c1,r2,c2;
        get_pos(key,ptext[i],&r1,&c1);
        get_pos(key,ptext[i+1],&r2,&c2);
        cout<<ptext[i]<<" "<<r1<<c1;
        cout<<ptext[i+1]<<" "<<r2<<c2;
        if(r1==r2)
        {
            ctext.push_back(key[r1][(c1+1)%5]);
            ctext.push_back(key[r2][(c2+2)%5]);
        }
        else if(c1==c2)
        {
            ctext.push_back(key[(r1+1)%5][(c1)]);
            ctext.push_back(key[(r2+1)%5][(c2)]);
        }
        else
        {
            ctext.push_back(key[(r1)][(c2)]);
            ctext.push_back(key[(r2)][(c1)]);
        }
    }
    cout<<"the cipher text is"<<endl;
    cout<<ctext<<endl;

}
