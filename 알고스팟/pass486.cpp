/*
memset : 특정 범위에 있는 연속된 메모리에 값을 지정하고 싶을 때 사용. for문보다 빠를 수 있다.


*/
//완전탐색 방법 사용
#include <iostream>
#include <cstdio>
#include <cstring> //memset때문에!
#include <cmath>//exit때문에!
using namespace std;
const int TM = 1000*1000*10;

int factors[TM+1];

void getFactorBrute(){
  memset(factors,0,sizeof(factors));
  for(int div=1;div<=TM;++div){
    for(int multiple=div;multiple<=TM;multiple+=div){
      factors[multiple]+=1;
    }
  }

}

int main() {
  int c;
  scanf("%d",&c);
  getFactorBrute();
  for(int i=0;i<c;i++){
    int n,lo,hi;
    scanf("%d %d %d",&n,&lo,&hi);
    if(n > 400 || lo<1 || lo>TM || hi<1 || hi>TM)
      exit(-1);
    int result=0;
    for(int j=lo;j<=hi;j++){
      if(factors[j]==n)
        result+=1;
    }
    printf("%d\n",result);

  }
}
