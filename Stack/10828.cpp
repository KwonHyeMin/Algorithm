
/*
1. scanf
-scanf : 띄어쓰기/엔터/탭을 읽어들인다
-만약 앞에 정수 입력받아 버퍼에 \n이 남아있다면 쓸 수 있는 방법
=> getchar();
ex)
scanf("%d", &a);
getchar();
scanf("%c", &c);

2. printf
-printf로 string출력하고싶으면
-cout << str <<'\n';
printf("%s\n",str.c_str());

*/

/*
1. cin
-cin은 공백을 무시
-cin : 입력값 기준이 띄어쓰기/엔터/탭
-대신 띄어쓰기/엔터/탭 문자가 버퍼에 그대로 남아있다
=> 그래서 getline에서 안 꼬이려면 cin.ignore써줘야함!
cin >> t;
cin.ignore();
while(t--){
   // cout << t <<'\n';
   getline(cin,str);
   
   cout << str <<'\n';

2. getline
-getline : 입력값 기준은 \n만나기 전까지
-\n직전까지를 입력으로 받은 후 \n을 버린다

*/

/*
1. python의 .split()함수처럼 ' '단위로 쪼개는 방법
-> vector<string>을 쓰거나, stringstream 쓰기
2. C++에서 입력 여러개 처리
-> 그냥 scanf로 처리

*/

#include <vector>
#include <iostream>
#include<sstream>
#include <cstdio>
#include <string>

using namespace std;

int stack[100];
int cnt=0;

void push(int x){
  cnt+=1;
  stack[cnt]=x;
}
int pop(){
  int temp;
  if(cnt==0)
    return -1;
  else{
    temp=stack[cnt];
    stack[cnt]=0;
    cnt-=1;

    return temp;
  }
}
bool empty(){
  if(cnt==0)
    return true;
  else
    return false;
}

int size(){
  //만약 배열의 크기 원하면
  //sizeof(stack)/sizeof(int)
  return cnt;
}

int top(){
  if(cnt==0){
    return -1;
  }
  else 
    return stack[cnt];
}


int main() {
  
  int t;
  string str;
//  vector<string> spl=split(str, ' ');
  //cin >> t;
  //cin.ignore();
  
  scanf("%d",&t);
  //getchar();
  
  while(t--){
   // cout << t <<'\n';
   //getline(cin,str);

   //scanf("%s",&str);
   cin >> str;


   if(!str.compare("push")){
     int x;
     cin >> x;
     push(x);
   }
   else if(!str.compare("pop")){
     cout << pop() <<"\n";
   }
   else if(!str.compare("empty")){
     cout << empty() <<"\n";
   }
   else if(!str.compare("top")){
     cout << top() <<"\n";
   }
   else{
     size();
     cout << size() <<"\n";
   }
   
  }
}
