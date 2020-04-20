#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
//두 값을 비교하여 최대값을 RETURN하는 함수
int get_max(int a,int b){
  return a>b? a:b;
}
//입력받을 삼각형의 숫자를 저장할 배열 A
int A[501][501];
//레벨 r의 c번째 원소에서 끝나는 최적 경로의 값을 저장하는 배열 best
int best[501][501]={0,};
//최적값을 갖기 위해 거쳐야할 이전 단계의 방향에 대한 정보 L, R갖고 있음
char s[501][501];
int main() {
  //삼각형의 크기를 저장할 변수 n
  int n;
  scanf("%d",&n);
  
  //for문을 돌며 삼각형값을 입력받는다
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      scanf("%d",&A[i][j]);
    }
  }
  //for문을 돌며 삼각형 각 숫자들의 최적 경로의 합을 best배열에 저장한다
  for(int r=1;r<=n;r++){
    for(int c=1;c<=r;c++){
      //A[r][c]까지 오는 경로는, A[r-1][c-1]과 A[r-1][c]까지의 경로중 가장 큰 값에 본인의 값을 더한 값이다
      //만약 c-1이 더 크면 왼쪽방향에서 온것
      if(best[r-1][c-1] > best[r-1][c]){
        best[r][c] = A[r][c]+best[r-1][c-1];
        s[r][c]='L';
      }
      //만약 c가 더 크면 오른쪽 방향에서 온 것
      else{
        best[r][c] = A[r][c]+best[r-1][c];
        s[r][c]='R';
        
      }
    }
  }
  //최대합을 저장할 max변수
  //최대합을 갖고 있는 마지막 줄의 c를 저장할 ind변수
  int max=0, ind=0;
  //for문을 돌며 마지막 줄에서 가장 큰 값을 max에, 그러한 index를 idn에 저장한다
  for(int i=1;i<=n;i++){
    if(max < best[n][i]){
      max = best[n][i];
      ind=i;
    }
  }
  //최적의 경로(가장 큰 값)출력
  printf("length : %d\n",best[n][ind]);

  //경로를 역순으로부터 추정해나가기 때문에 이 값을 저장할 vector v생성
  vector<int> v;
  //우선 제일 밑에 level의 원소를 집어넣는다
  v.push_back(A[n][ind]);

  for(int i=n;i>1;i--){
    //만약 왼쪽방향에서 최적의 값을 가져왔으면
    if(s[i][ind]=='L'){
      //왼쪽대각선값을 v에 넣고 index를 왼쪽으로 변화한다
      v.push_back(A[i-1][ind-1]);
      ind = ind-1;
    }
    //만약 오른쪽 방향에서 최적의 값을 가져왔으면
    else{
      //오른쪽 대각선 값을 v에 넣는다
      v.push_back(A[i-1][ind]);
    }
  }
  //v를 역순으로 출력한다
  printf("수열 : ");
  for(int i=n-1;i>=0;i--){
    printf("%d ",v[i]);
  }
}
