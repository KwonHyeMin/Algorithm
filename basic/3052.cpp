//#include <iostream>
//#include <stdio.h>
#include <cstdio>
#include <set>
using namespace std;
int main() {
  set<int>s;
  int arr[10];
  for(int i=0;i<10;i++){
    scanf("%d",&arr[i]);
    s.insert(arr[i]%42);    
  }
  int res=s.size();
  printf("%d\n",res);

//  std::cout << "Hello World!\n";
}
