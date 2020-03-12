#include <cstdio>

//using namespace std;
int getResult(int num){
  int result=0;
  int x,y,z;
  if(num>=100){
    result+=99;
    for(int i=101;i<=num;i++){
      x=i%10;
      y=(i/10)%10;
      z=i/100;

      int temp=x-y;

      if(y-z==temp){
        result+=1;
      }

    }
  }
  else{
    result=num;
  }
  return result;

}
int main() {
  int num;
  int result;
  
  scanf("%d",&num);
  result=getResult(num);
  printf("%d\n",result);

}
