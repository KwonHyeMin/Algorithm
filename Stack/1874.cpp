/*

며칠동안 해결 못했는데 결국 정답은말이지...
그냥 stacK<int>s;를 while문 안에 선언해서 
매번 새로 선언이 되기 때문에 empty로 넘어가기 때문이었어

*/

#include <iostream>
#include <stack>
//#include <queue>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    string str;
    int tc;
    scanf("%d", &tc);
    //getchar();
    int cnt = 1;
    int flag = 0;

    stack<int>s;
    while (tc--) {
        int a;
        scanf("%d", &a);
        if (s.empty() || s.top() < a) {
            while (cnt <= a) {
                s.push(cnt);
                //printf("%d\n",s.top());
                str += "+\n";
                cnt += 1;
            }
            str += "-\n";
            s.pop();
        }
        else if (s.top() == a) {
            s.pop();
            str += "-\n";
        }
        else if (s.top() > a) {
            flag = 1;

            break;
        }
    }
    if (flag == 1) {
        printf("NO\n");
    }
    else {
        cout << str;
    }
}
