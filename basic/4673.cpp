#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
/*
//방법1 :차집합
int main() {



  vector<int> res(10000);
  vector<int>::iterator iter;
  int result;
  set <int> s;
  //bool res[100];
  int sum;
  //s에 셀프넘버 아닌거 대입
  for(int i=1;i<=10000;i++){
    sum=0;
    sum+=i;

    sum+=i/10000+(i/1000)%10+(i/100)%10+(i/10)%10+i%10;
    if(sum<=10000)
      s.insert(sum);
  }

  auto itr = set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), result.begin());//차집합
[출처] [c++ STL] 집합 알고리즘|작성자 지피지기
  



*/

  /*
  for(int i=1;i<=10000;i++){

  }
  for(set<int>::iterator it=s.begin();it!=s.end();it++){
    printf("%d ",*it);
  }
  */
  //s.size() 
  //result=10000-s.size();

//}
//방법2 : 1~10000를 만들어놓고 제거하기
int main() {
  bool r[10001]={};
  //vector<int> res(10000);
  //vector<int>::iterator iter;
  
  int result;
  //set <int> s;
  //bool res[100];
  int sum;
  //s에 셀프넘버 아닌거 대입
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
  //  s.insert(sum);
    for(int i=1;i<10000;i++){
      if(r[i]==false)
        printf("%d\n",i);
    }
}
