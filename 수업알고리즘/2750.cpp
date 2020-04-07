//삽입정렬
/*
1. 헷갈렷던 점 
: 앞쪽에 삽입할 때는 j인덱스를 뒤에서부터 바꾸기 (인덱스 주의)
2. swap은 iostream, std필요

*/
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int c;
  scanf("%d",&c);
  int arr[c];
  for(int i=0;i<c;i++){
    scanf("%d",&arr[i]);
  }
  int key;
  for(int i=1;i<c;i++){
    //key=arr[i];
    for(int j=i-1;j>=0;j--){
      if(arr[j+1] < arr[j]){
        //arr[j+1]=arr[j]
        swap(arr[j+1],arr[j]);
        //break;
      }
    }
    
  }

  for(int i=0;i<c;i++){
    printf("%d\n",arr[i]);
  }
}
