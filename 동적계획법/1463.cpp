

#include<cstdio>
#include<iostream>
#include <algorithm>
using namespace std;
//dp[n] : n을 1로 만드는 최소 연산 횟수
int dp[1000000]={0,};

int sol(int n){
  int min;
  //초기조건
  if(n==1){
    return 0;
  }
  //만약 배열에 저장되어 있는 값일 경우
  if(dp[n]>0) return dp[n];
  dp[n]=sol(n-1)+1;
  //2로 나누어떨어진다면
  if(n%2==0){
    int t=sol(n/2)+1;

    dp[n]=(dp[n]<t)?dp[n]:t;
  }
  //3로 나눠떨어진다면
  if(n%3==0){
    int t=sol(n/3)+1;
    dp[n]=(dp[n]<t)?dp[n]:t;

  }
  return dp[n];
    
}

int main(){
  int tn;
  
  scanf("%d",&tn);

  int answer=sol(tn);

  printf("%d\n",answer);  
  
}
