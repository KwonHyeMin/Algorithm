//언젠가 A+B -9도전해보기! <- 이 문제는 입력이 엄청 다양한 경우이므로 변수 자료형의 입력 크기 등에 대해 많이 생각해보기!

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
  int a,b;
  int t;

  scanf("%d",&t);
  int k=t;
  while(t--){
    scanf("%d %d",&a,&b);
    
    printf("Case #%d: %d + %d = %d\n",k-t,a,b,a+b);
    
  }
}
