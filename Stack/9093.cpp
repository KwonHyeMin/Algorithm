/*
<string에서 단어 단위로 접근하기>
1. for(char ch : str){
  //str의 글자 하나하나 단위로 접근 가능
}
2. for(int i=0;i<str.size();i++){
  str[i],,
  //인덱스로 string객체 각 글자 접근 가능
}


*/


#include <iostream>
#include <stack>
#include <cstdio>
#include <string>

using namespace std;

int main() {
  string str;
  int t;
  scanf("%d",&t);
  getchar();
  
  stack<char>s;
  

  while(t--){
    while(!s.empty())s.pop();
    
    getline(cin,str);
    
    str+=" ";
    
    for(int i=0;i<str.size();i++){
    
      if(str[i]!=' '){
        s.push(str[i]);
      }
      else{
        while(!s.empty()){
          cout << s.top();
          s.pop();
        }
        cout << ' ';
      
      }

    }
    
    cout <<"\n";
  }
}
