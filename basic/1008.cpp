#include <stdio.h>

int main(void) {
  int a,b;
  scanf("%d %d", &a ,&b);

  double c = (double)a/b;
  printf("%.9f",c);
  return 0;
}
