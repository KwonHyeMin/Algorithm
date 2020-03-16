#include <iostream>
#include <stack>
//#include <queue>
#include <cstdio>
#include <string>

using namespace std;

int main() {
  string str;
  
  stack<char>s;
  getline(cin,str);
    
  str+=" ";
  int flag=0;
  for(int i=0;i<str.size();i++){
    if(flag==0){
      if(str[i]==' '){
        while(!s.empty()){
          cout << s.top();
          s.pop();
        }
        cout << ' ';
      } 
      else if(str[i]=='<'){
        while(!s.empty()){
          cout << s.top();
          s.pop();
        }
        flag=1;
        cout << str[i];
      }
      else 
        s.push(str[i]);      
    }
    else{
      cout << str[i];
      if(str[i]=='>')
        flag=0;
        
    }

  }
  cout <<"\n";
}
