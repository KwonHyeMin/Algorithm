/*
1. string관련 한 패키지 사용 : string

<C++에서 문자열 입력받기>
2. C++에서 C처럼 string 입력받기

char str[10];
scanf("%s", str);

char s[LENGTH];
scanf( "%s", s );

3. scanf처럼 형식지정자 지정안해두 됨
char s[LENGTH];
gets( s );

4. cin사용(s를 잘못 선언해 int로 썼어도 cin>>s;컴파일 과정에서 저절로 에러를 잡아줌)

char s[LENGTH];
cin.getline( s, sizeof( s ) );

5. s를 string객체로 대체해 사용해보기

string s;
getline( cin, s );

*/

/*

1. char를 int로 바꾸기
char s='5'
int n;
n=s-48;
또는
n=s-'0';

2. string객체를 int로 바꿀 때 -> stoi사용
string s="123";
int i;
i=stoi(s);

*/


#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
  int a,b;
  int t;
  scanf("%d",&t);
//  string str;
  
  while(t--){
    //문자열입력방법1
    char c[4];
    scanf("%s",c);
    a=c[0]-48;
    b=c[2]-48;

    printf("%d\n",a+b);
  }
}

