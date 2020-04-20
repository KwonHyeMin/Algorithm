#include <cstdio>
#include <vector>
using namespace std;
//사용자에게 입력받는 배열
int A[1000];
//A[i]로 끝나는 최장증가부분수열의 길이
int h[1000];
//수열 추적위한 p배열 선언
int p[1000];
//최장부분수열의 길이와 그 수열을 출력하는 함수
void longest_increasing_subseq(int n){
  for(int i=1;i<=n;i++){
    for(int j=0;j<i;j++){
      //값이 증가하고 있고, 길이가 갱신되야할 떄는
      if(A[i]>A[j]&& h[i]<h[j]+1){
        //길이를 갱신
        h[i]=h[j]+1;
        //추적을 위한 배열에j값 입력
        p[i]=j;
      }
    }
  }
  int max=0;
  int index=0;
  //for문을 돌며 h길이가 가장 큰 것을 찾는다
  for(int i=1;i<=n;i++){
    if(h[i]>max)
      max=h[i];
      index=i;
  }
  //부분수열의 길이 출력
  printf("%d\n",max);
  //부분수열의 인덱스 저장할 vector v선언
  vector<int> v;
  //for문돌며 p의 값으로 부분수열추적한다
  for(int i=0;i<max;i++){
    v.push_back(index);
    index=p[index]; 
  }
  //뒤에서부터 추적했으므로 반대 순서로 p배열의 값을 출력한다
  for(int i=max-1;i>=0;i--){
    printf("%d ",A[v[i]]);
  }
}

int main() {
  //전체 수열의 길이
  int n;
  scanf("%d",&n);
  //a[0]를 가장 작은 값으로 가정
  A[0]=-12345;
  for(int i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }
  //최장부분수열의 길이와 그 수열을 구하는 함수 호출
  longest_increasing_subseq(n);
  
}
