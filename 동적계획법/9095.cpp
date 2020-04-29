//botton up방식 - for문 사용

#include<cstdio>
#include<iostream>

using namespace std;
long long dp[11]={0,};

int main(){
  int tn;
  dp[1]=1;
  dp[2]=2;
  dp[3]=4;
  scanf("%d",&tn);
  for(int i=0;i<tn;i++){
    int n;
    scanf("%d",&n);

    for(int i=4;i<=n;i++){
      if(dp[i]>0) continue;
      dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    printf("%lld\n",dp[n]);  
  }

}
