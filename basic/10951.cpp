/*
1. C의 경우 입출력방식
scanf, printf (또는 cin cout)
2. scanf의 리턴값은 성공적으로 입력받은 변수의 개수이다

*/


//#include <iostream>
#include <cstdio>

int main() {
  int a,b;

  while(scanf("%d %d",&a,&b)==2){
    printf("%d\n",a+b);
  }

  //std::cout << "Hello World!\n";
}
