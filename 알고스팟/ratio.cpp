#include <iostream>
#include <cstdio>
//#include <cmath>
#include <math.h>
#define MAX 2000000000
using namespace std;

//math
int main() {
  int c;
  scanf("%d",&c);
  for(int i=0;i<c;i++){
    //double n,m;
    //scanf("%lf %lf",&n,&m);

    long long n,m;
    //scanf("%d %d",&n,&m);
    cin >> n >> m;
    //cout << (m*100.0)/n << endl;
    //밑에 계산에서 분모가 0되는 경우 방지
    double r = floor((m*100.0)/n)+1;
    if(r>99) {
      printf("-1\n");
      continue;
    }
    //cout << "cout : "<<r<< endl;
    double temp = (r*n-100*m)/(100-r);
    //cout << temp <<endl;
    //cout << ceil(temp) <<endl;
    double x = ceil((r*n-100*m)/(100-r));
    //cout << temp <<endl;

    if(x>MAX){ 
      printf("-1\n");
    }
    else{
      printf("%d\n",int(x));
    }
  }
}
