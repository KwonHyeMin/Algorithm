  /*
1. 숫자가 너무 커지는 경우 long long사용하기!
-> 이때 printf쓰려면 %lld임!!

2. 나머지 연산
(a+b)%m = ((a%m)+(b%m))%m

*/
#include<cstdio>
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long dp[1001]={0,};
int main(){
  int n;
  scanf("%d",&n);
  dp[1]=1;
  dp[2]=3;
  for(int i=3;i<=n;i++){
    dp[i]=(dp[i-1]%10007+2*dp[i-2]%10007)%10007;
  }
  printf("%lld",dp[n]);


}
