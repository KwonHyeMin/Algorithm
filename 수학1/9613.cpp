/*
최대공약수 구하기
1. min(a,b)보다 작은 값들로 나눠서 동시에 0되는 것들 찾기
-> 시간복잡도 O(n)
2. 유클리도 호제법
GCD(a,b)= GCD(b,a%b)일때 a%b가 0이 되는 b가 최대공약수
- 재귀함수
- 반복문
-> 시간복잡도 O(logN)

*/
/*
만약 값이 너무 커질 것 같은 경우 sum같은 변수는 long long으로 선언하기!
*/


#include <cstdio>
#include<iostream>
#include<string>

using namespace std;

int getGCD(int a,int b){
  if(b==0) return a;
  else{
    return getGCD(b,a%b);
  }
}

int main() {
  int t;
  cin >> t;
  for(int i=0;i<t;i++){
    int n;
    cin >> n;
    int lst[n];

    for(int j=0;j<n;j++){
      cin >> lst[j];
    }
    long long sum=0;
    for(int k=0;k<n-1;k++){
      for(int l=k+1;l<n;l++){
        sum+=getGCD(lst[k],lst[l]);
      }
    }
    cout << sum << "\n";
  }
    
}
