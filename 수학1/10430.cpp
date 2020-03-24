
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void solution(int A, int B, int C) {
  cout << (A+B)%C <<"\n";
  cout << ((A%C) + (B%C))%C <<"\n";
  cout << (A*B)%C <<"\n";
  cout << ((A%C) * (B%C))%C <<"\n";
     
}

int main() {
  int a,b,c;
  
  cin >> a>> b>> c;
  solution(a,b,c);
  
}
