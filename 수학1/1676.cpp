

#include <iostream>
#include <cstdio>

using namespace std;

/*
전체 factorial을 먼저 다 구하고
그다음에 5로 나눠 개수세면 시간초과!
unsigned long long이 표현할 수 있는 최대의 수는 18446744073709551615 입니다
따라서 500!는 구할수 x


void solution(int n) {
  int cnt=0;
  int fac=1;
  for(int i=1;i<=n;i++){
    fac*=i;
  }
  
  while(1){
    if(fac%5==0){

      fac/=5;
      //cout << fac <<endl;
      cnt+=1;

    } 
    else break; 

  }
  cout << cnt;
}
*/
void solution(int n){

  int cnt=0;
  int temp=5;
  while(temp<=n){
    //temp * 
    cnt+=n/temp;
    temp*=5;

  }
  cout << cnt;

}

int main() {
  int n;
  cin >> n;
  solution(n);

  
}
