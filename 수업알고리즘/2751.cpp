/*
1. 퀵 정렬 시간더 빨리하는 법
- pivot을 start,mid,end순으로 먼저 정렬하여 mid를 pivot으로 만들기!
- 퀵정렬쓸 때, 그냥 정석적으로 partition, quick_sort부분 만들기!

*/

#include <cstdio>
#include <iostream>

using namespace std;
#define MAX 1000000

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int arr[MAX];

int get_pivot(int start,int end){
  int mid = (start+end)/2;
  //printf("mid = %d\n",mid);

  if(arr[start]>arr[mid]){
    swap(arr[start],arr[mid]);
  }
  if(arr[start]>arr[end]){
    swap(arr[start],arr[end]);
  }
  if(arr[end]<arr[mid]){
    swap(arr[end],arr[mid]);
  }
  return mid;
}
int partition(int left, int right){
  int idx = get_pivot(left,right);
  swap(arr[left],arr[idx]);

    int pivot = arr[left];
    int i=left+1;
    int j=right;
      
    do{
      while(i<=right && arr[i]<=pivot){
        i++;
      }
      while(j>=left && arr[j]>pivot){
        j--;
      }
      if(i<j)
        swap(arr[j],arr[i]);
    }while(i<j);
    swap(arr[j],arr[left]);
    return j;

  

}

void quick_sort(int left, int right){
  if (left>=right)
    return ; 
  int j = partition(left,right);
  quick_sort(left,j-1);
  quick_sort(j+1,right);
    //quick_sort(arr,left,j-1);
    //quick_sort(arr,j+1,right);

}





int main() {
  int c;
  
  scanf("%d",&c);
  //int arr[c];
  for(int i=0;i<c;i++){
    scanf("%d",&arr[i]);
  }
  //quick_sort(arr,0,c-1);
  quick_sort(0,c-1);
  for(int i=0;i<c;i++){
    printf("%d\n",arr[i]);
  }
}
