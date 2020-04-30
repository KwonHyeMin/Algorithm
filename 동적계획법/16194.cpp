/*
1은 최대 구하기, 2는 최소 구하기 문제!

최소 구하기의 경우 dp[]값을 제일 큰 값으로 초기화 하여 비교하기!

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
    dp[i]=10001;
  }

  for(int i=1;i<=tn;i++){
    for(int j=1;j<=i;j++){
      dp[i]=min(dp[i],dp[i-j]+p[j]);
    }
  }  

  printf("%d\n",dp[tn]);  
  
}
