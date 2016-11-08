#include <stdio.h>
#include <limits.h>
#include<string.h>
int main() {
    char a[100] ="XLILSYWIMWRSAJSVWEPIJSVJSYVQMPPMSRHSPPEVWMXMWASVXLQSVILYVVCFIJSVIXLIWIPPIVVIGIMZIWQSVISJJIVW";
        int hash[26] = {0},k=0;
        char ct[100];
        int i;
        for(i = 0; i < strlen(a); i++) {
                hash[a[i] - 'A']++;
        }
        int maxIndex = INT_MIN, maxValue = INT_MIN;
        for(i = 0; i < 26; i++) {
                if(maxValue < hash[i]) {
                        maxValue = hash[i];
                        maxIndex = i;
                }
        }
        int b = maxIndex - 4;
        if(b < 0) {
                b += 26;
        }
        for(i = 0; i < strlen(a); i++) {
                char ch = (a[i] - 'A' - b) % 26 + 'A';
                if(ch < 'A') {
                        ch += 26;
                }
                ct[k++]=ch;
        }
        printf("Applying Statistical Attack: \n");
       printf("Encrypted string is %s\n",ct);
        return 0;
}
