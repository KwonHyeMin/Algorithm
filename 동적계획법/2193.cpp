/*
예제 문제는 잘 돌아가는데 왜 틀렸는지 모르겠을 때는
n범위 중에 제일 큰 값을 넣어봐서 오버플로우 발생하는지 보기!
*/
#include<cstdio>
#include<iostream>
#include <algorithm>
#define MOD 1000000000
using namespace std;

//dp[i][j] : 수의 길이가 i일 때 마지막 계단의 수가 j인 방법의 수
long long dp[91][2]={0,};

int main(){
  int tn;
  long long answer=0;
  scanf("%d",&tn);

  dp[1][1]=1;
  

  for(int i=2;i<=tn;i++){
    dp[i][0]=dp[i-1][0]+dp[i-1][1];
    dp[i][1]=dp[i-1][0];
    
  }
  
  answer=dp[tn][1]+dp[tn][0];
  
  printf("%lld\n",answer);    
}
