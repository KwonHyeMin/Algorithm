/*
최소 스패닝 트리

*/
#include<cstdio>
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000
//int W[MAX][MAX]={};
int main(){

  int v,e;
  int W[v][v]={1,};
  scanf("%d %d",&v,&e);
  int a,b,c;
  for(int i=0;i<e;i++){
    scanf("%d %d %d",&a,&b,&c);
    W[a][b]=c;
    W[b][a]=c;  
  }

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
