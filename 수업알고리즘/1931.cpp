/*
참고하기좋은 사이트 : 
https://www.zerocho.com/category/Algorithm/post/584ba5c9580277001862f188
*/
/*
그리디 알고리즘
- 탄생 배경 : dp를 쓰면 지나치게 많이 일을 하게 되어 dp와 함께 쓰이며 서로 보완하는 알고리즘이다.
- 개념 : 미래를 생각하지 않고 현재 단계에서 가장 최선의 선택을 하는 기법. 매 단계에서 최선의 선택을 하면, 그게 전체적으로도 최선의 선택이다.
ex) 마시멜로 : 지금 선택하면1개, 1분뒤 선택하면 2개. -> 당장 최선의 선택은 1개를 받는게 좋지만, 결과적으로는 1분 기다렸다가 2개 받는게 최선의 선택!

- 풀 수 있는 유형
1. 활동 선택 문제
한 강의실에서 여러 수업을 할 때 한 번에 가장 많은 수업을 할 수 있는 경우를 골라라.

- 최적의 해를 구하기 위해서는 첫 번째 활동이 최대한 일찍 끝나면 된다. 그래야 다른 활동을 더 많이 선택할 수 있다. 
- 푸는 법 : 끝나는 시간으로 정렬한 후, 반복문을 돌며, 회의가 끝나는 시간이 다음 회의 시작 시간보다 작으면 집합에 추가한다

2. 분할 가능 배낭 문제
무게가 초과되면 물건을 쩌개서 일부만 넣을 수 있다

- 푸는 법 : 무게 대비 profit이 높은 것 순서대로 넣기!


*/
#include<cstdio>
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<pair<int,int>> v;
  vector<pair<int,int>>::iterator it;
  int n;
  scanf("%d",&n);
  int a,b;
  for(int i=0;i<n;i++){
    scanf("%d %d",&a,&b);
    v.push_back(make_pair(b,a));
  }
  sort(v.begin(),v.end());
  /*
  for(it =v.begin();it!=v.end();it++ ){
    printf("%d %d\n",it->first, it-> second);
  }
  */
  int result=1;
  int temp = v[0].first;
  for(int i=1;i<n;i++){
    if(v[i].second >= temp){
      temp = v[i].first;
      result+=1;

    }
  }
  printf("%d\n",result);
}
