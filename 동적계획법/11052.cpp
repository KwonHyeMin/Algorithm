/*
실수할 뻔한 부분 : dp[4]+p[1]과 d[1] + p[4]는 다르다!!

*/


#include<cstdio>
#include<iostream>
#include <algorithm>

using namespace std;

//dp[n] : n을 1로 만드는 최소 연산 횟수
int dp[1001]={0,};

int main(){
  int tn;
  int p[1000]={0,};
  scanf("%d",&tn);

  for(int i=1;i<=tn;i++){
    scanf("%d",&p[i]);
  }
  dp[1]=p[1];

  for(int i=1;i<=tn;i++){
    for(int j=1;j<=i;j++){
      dp[i]=max(dp[i],dp[i-j]+p[j]);
    }
  }  

  printf("%d\n",dp[tn]);  
  
}
