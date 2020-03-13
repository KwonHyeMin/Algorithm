#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
bool r[10001]={};

void getRes(int i){
  int sum=0;
  sum+=i;

  sum+=i/10000+(i/1000)%10+(i/100)%10+(i/10)%10+i%10;
  if(sum<=10000){
      if(r[sum]==false){
        r[sum]=true;
      }
      
    }

}

//방법2 : 1~10000를 만들어놓고 제거하기
int main() {
  
  //vector<int> res(10000);
  //vector<int>::iterator iter;
  
  int result;
  //set <int> s;
  //bool res[100];
  int sum;
  //s에 셀프넘버 아닌거 대입
  for(int i=1;i<=10000;i++){

    getRes(i);
    
  }
  //  s.insert(sum);
    for(int i=1;i<10000;i++){
      if(r[i]==false)
        printf("%d\n",i);
    }
}
