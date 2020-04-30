/*
- 이거 계속 틀렸는데, 알고 보니 이유가 answer를 long long으로 선언 안해서이다..!!
 혹시 dp를 long long으로 선언했다면 answer도 long long도 선언하기!
dp에서 연속을 피하기 위해 이차원 배열을 사용!
dp[i][j] : i번째 수 중 마지막 자리가 j인 방법의 수 

만약 j의 종류가 2가지 밖에 없으면 1차원으로도 가능함!


- 초기화가 중요!!
*/
#include<cstdio>
#include<iostream>
#include <algorithm>
#define MOD 1000000000
using namespace std;

//dp[i][j] : 수의 길이가 i일 때 마지막 계단의 수가 j인 방법의 수
long long dp[101][11]={0,};

int main(){
  int tn;
  int answer=0;
  scanf("%d",&tn);

  for(int i=1;i<10;i++){
    dp[1][i]=1;
  }

  for(int i=2;i<=tn;i++){
    for(int j=0;j<10;j++){
      if(j==0){
        dp[i][j]=(dp[i-1][1])%MOD;
      }
      else if(j==9){
        dp[i][j]=(dp[i-1][8])%MOD;
      }
      else{
        dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MOD;
      }
      
    }
    
  }
  for(int j=0;j<10;j++){
    answer+=dp[tn][j];
  }
  printf("%d\n",answer%MOD);    
}
