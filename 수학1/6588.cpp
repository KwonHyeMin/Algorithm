/*
STL 간단 정리
<배열>
- 스택영역에 자료 저장하고, 컴파일 시 공간 확보
- 장점 : index로 접근 가능/자료의 접근과 저장이 빠름/자료 순차적 저장 가능
- 단점
1. 한번 확보한 배열크기 조절 쉽지 않음-> 메모리 낭비.
2. 중간 값 삽입/삭제가 어려움(shift힘듦)

<vector> : 동적배열
- 배열의 '단점1'을 보완
- 그러나 '단점2'는 극복x
(앞/뒤 삽입/삭제는 가능하지만 중간은 불가)
- 검색 속도 느림(data가 순차적으로 저장되니까..)
-> 물론 index를 안다면 배열처럼 쉽게접근 가능

<list> : vector의 단점인 중간값 삽입/삭제 가능해짐
- 포인터를 이용하여 다음 값을 찾는방식
-> 중간에서도 삽입/삭제 용이
- 단점 
1. vector처럼 data의 index로 접근 불가
2. 순차 접근이라 검색이 느림

<map> : key, value가 한 쌍이다
- 트리구조
- key를 기준으로 자동 정렬됨
- 검색 속도가 빠르다!(list,vector보다)
- 단점 : 삽입/삭제가 빈번하면 안된다 (매번 정렬하므로!)

<set> : map인데 key만 저장하는 map
- 마찬가지로 트리구조
- key를 신속하게 검색하고, key를 정렬할 때 사용


<총정리>
1. 간단하게 쓰고 싶다 -> 배열
2. 동적으로 쓰고 싶다 -> vector / list
- index로 검색하고 싶다-> vector
- 중간에 삽입/삭제하고 싶다 -> list
3. 검색 많이 할 것 같다(정렬도 됨) -> map (대신 삽입/삭제 자주하면 안됨)
4. 검색 많이 할거고 정렬도 할건데 key만 필요 -> set
---------STL아님----------
5. 검색 많이 할 거고 data도 많음, 정렬은 안함 -> hasy_map
6. 위의 경우인데 key만 필요 -> hash_set


*/


/*

<배열과 vector/list>
- 만약 간단하게 쓰고 싶을 때 : 배열
- 동적으로 쓰고 싶다면 : vector/list


<vector 와 list의 차이점>
- vector : 메모리 할당을 연속적으로(배열과 비슷)
-> 미리 일정크기 할당한 후 그 이상의 값들이 추가되면 새로운 더 큰 메모리를 할당한다
- list : 메모리 할당을 자유롭게 따로따로(linked list와 비슷)
-> 값을 넣을 때마다 메모리를 할당

그래서!
- pushback/popback : vector가 더 빠름(매번 메모리 할당 안하니까)
- 중간에 추가하는 insert,delete : list가 더 빠름(vector는 배열을 계속 재구성해야하니까)

그렇다면 메모리 해제는!
- vector : 값 삭제해도 메모리 해제 안함(심지어 clear해도 메모리는 그대로!)
- list : 변수가 해제될 때마다 메모리에서 해제

정리! 
- 맨 뒤에서 추가, 삭제가 일어나는 경우 vector가 빠르며 메모리 손실도 적다
즉, 순서가 상관없거나 순차적으로 추가/삭제 : vector가 유리
- 순서가 중요해서 중간에 추가,삭제가 되는 경우 메모리는 물론 많이 잡아먹지만 속도가 엄청 빠르기에 : list가 유리
- 일반적으로는 vector가 list보다 메모리 더 적게 사용! 왜냐면 vector는 연속적인 주소에 할당되므로 list처럼 next등의 추가적인 다른 변수 가질 필요 없거든!

*/

/*
<소수 찾는 법>
1. 어떤 수 N이 소수인지, 아닌지 판별법
- 단순히 2~n-1까지의 수중 n%i==0이면 false라고 표시
-> 시간 복잡도 : O(n)
---<더빠른법>---
- 2~n/2까지의 수중 n%i==0인지 확인
---<더빠른법>---
- 2~루트 n가지의 수중 ...

2. 특정 구간에 있는 N들이 소수인지, 아닌지 판별법
=> 에라토스테네스의 체로 내가 원하는 전체 구간에서 
소수인지 아닌지 boolean값으로 판별

*/

/*

처음에 시간초과 난 이유: MAX가 1000000라서!
-> 중간 for문에 j=i*i에서 n까지 할 떄 
i*i하면 overflow발생하니까 i*2로 바꾸기!

*/

#include <iostream>
#include <cstdio>

using namespace std;
//int list;
//vector<int>v;
//원래n은 1000000까지인데 나는 그중 홀수인 것들만 소수인지 알고 싶음
#define MAX 1000000

//int isPrime[MAX];
int pn = 0;
bool check[MAX];//지워진 애면 true
int n = MAX;

void getPrime() {
    //printf("hello11111\n");

    for (int i = 2; i <= n; i++) {
        if (check[i] == false) {
            //isPrime[pn++]=i;
            for (int j = i * 2; j <= n; j += i) {
                //2x2, 2x3,2x4,2x5,2x6,,
                //지우기
                check[j] = true;
            }
        }
    }
    //printf("ITs done\n");
}

/*
void getPrime(){
  //0 * 2 + 3->3
  //1 *2 +3->5
  //2->7

  isPrime[0]=0;
  for(int i=5;i<MAX;i=i+2){
    for(int j=3;j<i;j=j+2){
      //소수가 아니라면 그 값을 1로!
      //소수면 0으로!
      if(i%j==0){
        isPrime[(i-3)/2]=1;
        break;
      }
    }
  }
}
*/

void solution(int a) {
    //getPrime();
    int b = 0, c = 0;
    int i;

    for (int i = 3; i <= n; i += 2) {
        if (!check[i] && !check[a - i]) {
            b = i;
            c = a - i;
            break;
        }
    }


    if (b == 0 && c == 0) {
        printf("Goldbach's conjecture is wrong.\n");
    }
    else
        printf("%d = %d + %d\n", a, b, c);
}

int main() {
    getPrime();
    //printf("hello\n");

    while (1) {
        int a;
        scanf("%d", &a);
        //cout << a;
        if (a == 0) {
            //printf("hello\n");
            break;
        }
        solution(a);

    }
}
