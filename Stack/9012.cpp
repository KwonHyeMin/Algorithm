/*
1. pop할 게 없는데 pop하라고 하면 런타임에러 뜬다

*/

#include <iostream>
#include <stack>
//#include <queue>
#include <cstdio>
#include <string>

using namespace std;

int main() {
  string str;
  int tc;
  scanf("%d",&tc);
  getchar();

  while(tc--){
  stack<char>s;

  getline(cin,str);
    
  //str+=" ";
  for(int i=0;i<str.size();i++){
    if(str[i]=='(')
      s.push(str[i]);
    else{
      if(s.empty()){
        printf("NO\n");    
        break;
      }
      s.pop();
    }
    if (i==str.size()-1){
      if(!s.empty()){
        printf("NO\n");
      }
      else
        printf("YES\n");

    }
  }
  }
  
}
