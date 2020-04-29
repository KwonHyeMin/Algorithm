//재귀함수로 풀기
// top down방식

/*
만약 값이 int범위를 넘어갈 경우
1. mod연산의 속성 활용
=> (a+b)%m = ((a%m)+(b%m))%m
2. long long (%lld)이용
*/

#include<cstdio>
#include<iostream>

using namespace std;
int dp[1001]={0,};

int sol(int n){
  if(n==1){
    return 1;
  }
  else if(n==2){
    return 2;
  }
  else{
    if(dp[n]>0){
      return dp[n];
    }
    else{
      dp[n]=(sol(n-1)+sol(n-2))%10007;
      return dp[n];
    }
  }
}

int main(){
  int tn;
  
  scanf("%d",&tn);

  int answer=sol(tn);

  printf("%d\n",answer);  
  
}
