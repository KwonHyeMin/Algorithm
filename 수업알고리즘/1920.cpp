/*
시간초과, 메모리 초과 안나려면 scanf쓰고, vector를 인자로 넘겨주는게 아니라
전역으로 선언해야함


*/


#include<vector>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
vector<int> a;
int findNum(int fir, int las,int temp){
  int mid=(las+fir)/2;
  
  if(fir>las){
    return 0;
  }
  else{
    if(a[mid]>temp){
      return findNum(fir,mid-1,temp);
    }
    else if(a[mid]< temp){
      return findNum(mid+1,las,temp);
    }
    else{
      return 1;
    }

  }  
}

int main() {
  int n,m;
  int temp; 
  
  //n입력받음
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int s;
    scanf("%d",&s);
    a.push_back(s);
  }
  //배열 a를 정렬
  sort(a.begin(),a.end());
  //m입력받음
  scanf("%d",&m);
  for(int i=0;i<m;i++){
    scanf("%d",&temp);
    
    printf("%d\n",findNum(0,n-1,temp));

  }
  
}
