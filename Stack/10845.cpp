/*
1. queue : 순차적으로 일 처리할 때 사용
=> 주로 BFS에서 활용

2. 구현
1) 일차원 배열로 구현 [begin,end)

*/

/*
<런타임에러 발생 이유>
배열에 할당된 크기를 넘어서 접근했을 때
전역 배열의 크기가 메모리 제한을 초과할 때
지역 배열의 크기가 스택 크기 제한을 넘어갈 때
0으로 나눌 떄
라이브러리에서 예외를 발생시켰을 때
재귀 호출이 너무 깊어질 때
이미 해제된 메모리를 또 참조할 때

=> 내가 틀린 이유
: arr의 크기를.. 입력N이 10000까지인데 1000까지만 해서!!
입력크기 잘보자 해민!!
=> 그리고 대부분 런타임에러는 배열 크기, 참조 등에서 잘못됐을 때!

*/

#include <cstdio>
#include<iostream>
#include<string>

using namespace std;

int arr[10000];

int b = 0;
int n = 0;

void push(int x) {
    arr[n] = x;
    n += 1;

}
int empty() {
    if (b == n) {
        return 1;
    }
    else
        return 0;
}
int pop() {
    if (empty()) {
        return -1;
    }
    else
        b += 1;
    return arr[b - 1];
}

int size() {
    return n - b;
}
int front() {
    if (empty()) {
        return -1;
    }
    else
        return arr[b];
}
int back() {
    if (empty()) {
        return -1;
    }
    else
        return arr[n - 1];

}
int main() {
    int tc;
    scanf("%d", &tc);
    //getchar();

    while (tc--) {
        string str;
        cin >> str;
        if (str == "push") {
            int a;
            cin >> a;
            push(a);
        }
        else if (str == "front") {
            cout << front() << "\n";
        }
        else if (str == "back") {
            cout << back() << "\n";
        }
        else if (str == "pop") {
            cout << pop() << "\n";
        }
        else if (str == "empty") {
            cout << empty() << "\n";
        }
        else if (str == "size") {
            cout << size() << "\n";
        }
    }
}
