#include <cstdio>


using namespace std;

//방법2 : 1~10000를 만들어놓고 제거하기
int main() {
   //지역변수는 선언할때 초기화 필요, 전역 변수는 초기화 필요없음
  bool r[10001]={};//지역변수라서 초기화

  
  int result;

  int sum;
    
  for(int i=1;i<=10000;i++){
    sum=0;
    sum+=i;

    sum+=i/10000+(i/1000)%10+(i/100)%10+(i/10)%10+i%10;
    if(sum<=10000){
      if(r[sum]==false){
        r[sum]=true;
      }
    }
    
  }
    for(int i=1;i<10000;i++){
      if(r[i]==false)
        printf("%d\n",i);
    }
}
