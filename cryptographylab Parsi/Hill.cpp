#include<bits/stdc++.h>

using namespace std;

int main()
{
    int k[3][3];
    int p[3][1];
    int c[3][1];
    printf("enter 9 character Key\n");
    char ch;
    for(int i=0;i<3;i++)
    {

        for(int j=0;j<3;j++)
        {
            scanf("%c",&ch);
            if(65<=ch&&ch<=91)
            k[i][j]=(int)ch%65;
            else
                k[i][j]=(int)ch%97;

        }
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << k[i][j] << "  ";
        }
        cout << endl;
    }
    cout<<"enter the plain text of multiple 3"<<endl;
    string pi;
    cin>>pi;
    int l=pi.length();
    for(int m=0;m<l;m=m+3)
    {

        if (65 <= pi[m] && pi[m] <= 91)
                p[0][0] = (int) pi[m] % 65;
            else
                p[0][0] = (int) pi[m] % 97;
       if (65 <= pi[m+1] && pi[m+1] <= 91)
                p[1][0] = (int) pi[m+1] % 65;
            else
                p[1][0] = (int) pi[m+1] % 97;
       if (65 <= pi[m+2] && pi[m+2] <= 91)
                p[2][0] = (int) pi[m+2] % 65;
       else
                p[2][0] = (int) pi[m+2] % 97;
      for(int j=0;j<3;j++)
      {

          c[j][0]=0;
      }
      for(int i=0;i<3;i++)
      {

          for(int j=0;j<1;j++)
          {

              for(int k1=0;k1<3;k1++)
              {

                  c[i][j]+=k[i][k1]+p[k1][j];
              }
          }
      }
      for (int i = 0; i < 3; ++i)
        {
            c[i][0] = c[i][0] % 26;
            printf("%c ", (char) (c[i][0] + 65));
        }
    }
}
