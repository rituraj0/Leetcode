#include <cstdio>
#include <cstring>
#include <vector>
#include<iostream>
using namespace std;

char word[100009];
char pat[100009];
bool start_of[100009];
int last_before[100009];
int dp[100009];
int sumdp[100009];

#define MOD 1000000007

void kmp(const char* str,const char* wzo){
    #define KMPH(z) while(k>0&&wzo[k]!=z[q])k=p[k];if(wzo[k]==z[q])k++;
    int p[strlen(wzo)+1],k=0,q,m;
    p[1]=0;
    for(q=1;wzo[q];q++){
        KMPH(wzo);
        p[q+1]=k;
    }
    m=q;
    k=0;
    for(q=0;str[q];q++){
        KMPH(str);
        if(m==k){
            start_of[q-m+1]=1;;
            k=p[k];
        }
    }
}

int main(){
    scanf("%s %s",word,pat);
    kmp(word,pat);
    int last=-1;
    int len=strlen(word);
    int len2=strlen(pat);
    for(int i=0;i<=len;i++){
        if(i>=len2&&start_of[i-len2]){last=i-len2;}
        last_before[i]=last;

        std::cout<<last_before[i]<<"_";
    }
    dp[0]=1;
    sumdp[0]=1;
    //dp[i] is the answer to the question for substring to i
    for(int i=0;i<len;i++){
        dp[i+1]=dp[i];
        if(last_before[i+1]!=-1){
            dp[i+1]+=sumdp[last_before[i+1]];
        }
        dp[i+1]%=MOD;
        sumdp[i+1]=sumdp[i]+dp[i+1];
        sumdp[i+1]%=MOD;
    }
    printf("%d\n",(MOD+dp[len]-1)%MOD );
}
