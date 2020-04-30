/*
dp에서 연속을 피하기 위해 이차원 배열을 사용!
dp[i][j] : i번째 수 중 마지막 자리가 j인 방법의 수 

만약 j의 종류가 2가지 밖에 없으면 1차원으로도 가능함!

- 틀렸습니다 1번 떴는데, 그 이유는 (a+b)%m = (a%m + b%m)%m 잘못생각해서!

- 초기화가 중요!!
*/
#include<cstdio>
#include<iostream>
#include <algorithm>
#define MOD 1000000009
using namespace std;

//dp[i][j] : 합이 i일 때 마지막으로 더한 숫자가 j인 방법의 수
long long dp[100001][3]={0,};

int main(){
  int tn;
  int answer;
  scanf("%d",&tn);


  //dp[1][0]=1;
  dp[1][1]=1;
  //dp[1][2]=1;

  //dp[2][1]=1;
  dp[2][2]=1;

  dp[3][1]=1;
  dp[3][2]=1;
  dp[3][0]=1;
  for(int i=1;i<=tn;i++){
    int n;
    scanf("%d",&n);

    for(int i=4;i<=n;i++){
      dp[i][1]=(dp[i-1][2]+dp[i-1][0] )%MOD ;
      dp[i][2]=(dp[i-2][1] +dp[i-2][0] )%MOD ;
      dp[i][0]=(dp[i-3][2] +dp[i-3][1] )%MOD ;

    }

    answer = (dp[n][1]+dp[n][2]+dp[n][0])%MOD;
    printf("%d\n",answer);    
  }
}
