#include <stdio.h>

int main(void) {
  int c;
  scanf("%d", &c);

  for(int i=0;i<c;i++){
    int N;
    int sum=0,std=0;
    double avg;  
    scanf("%d",&N);
    int score[N];
    for(int j=0;j<N;j++){
      scanf("%d",&score[j]);
      sum+=score[j];
    }
    avg=(double)sum/N;
    for(int j=0;j<N;j++){
      if(avg<score[j])
        std+=1;
    }
    printf("%.3lf%%\n",(double)std*100/N);


  }
}
