/*
<최대최소구하는 법>
1. #include<algorithm>으로 min(1,2) 또는 max(1,2)
구하기!

2. 그냥 if문 써서 작은거, 큰거 변수2개에 저장

*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void solution(int a, int b) {
  int i=1;
  for(i=min(a,b);i>=1;i--){
    if(a%i==0 && b%i==0){
      break;
    }
  }
  int k=a*b/i;

  cout << i<<"\n";
  cout << k <<"\n";
     
}

int main() {
  int a,b,c;
  
  cin >> a>> b;
  solution(a,b);
  
}
