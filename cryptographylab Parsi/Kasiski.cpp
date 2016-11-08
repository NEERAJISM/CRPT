#include <bits/stdc++.h>
using namespace std;
#define NUMCHARS 128

#define TEXTLEN 10000   /* Ciphertext array */
int Clen;

char R[TEXTLEN];        /* Array to store repeated characters */
#define RTHRESH 3       /* Repeats this big are considered "interesting"
*/




int main()
{
char c;
int i,j,k;

/* Read in and echo text, saving only A-Z */
i = 0;

string C;
cin>>C;
Clen = C.length();

/* Look for repeats. For short text, the O(n^2) algorithm will do */
for (i=0;i<Clen;i++) {
    j = i+1;
    while(j<Clen) {
        k = 0;
        while (C[i+k] == C[j+k]) {
            R[k] = C[i+k];
            k++;
            }
        R[k] = '\0';
        if (k >= RTHRESH) {
            printf("%s\tat %d and %d with diff %d\n", R, i, j, j-i);
            }
        j++;
        }
    }
}

