/*

드래곤 커브는 간단한 수학 규칙으로 그릴 수 있는 그림이다.

드래곤 커브는 선분 하나에서 시작해서 간단한 규칙으로 이 선분을 변형해서 만들어지며,

변형이 한번 이루어져 세대가 변할때마다 더욱 복잡한 모양으로 진화한다.

드래곤 커브 문자열은 X, Y, F, +, -로 구성된 문자열인데 우리는 한 점에서 시작해 커브를 그리면 된다.



0세대 드래곤 커브를 그리는 문자열은 선분 하나인 FX이다.

그리고 이후 다음 세대는 이전 세대의 문자열의 각 글자를 다음과 같이 치환해서 만들어진다

X -> X+YF

Y -> FX-Y

n세대 드래곤 커브 문자열을 구하되 모두 구하면 너무 기니, 문자열 중 skip번째 글자부터

range 글자만을 계산하는 프로그램을 작성하시오

*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 1000000000 + 1;
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";
//length[i]=X나 Y를 i번 치환한 후의 길이
int length[51];

//초기 문자열 seed를 generations 세대 진화한 결과 출력
/*
void curve(const string &seed, int generations)
{
        //기저 사례
        if(generations == 0)
        {

               cout << seed;

               return;

        }

        for (int i = 0; i < seed.size(); i++)

        {

               if (seed[i] == 'X')

                       curve("X+YF", generations - 1);

               else if (seed[i] == 'Y')

                       curve("FX-Y", generations - 1);

               else

                       cout << seed[i];

        }

}

*/
//문자열의 길이 계산
void preCalculate(void)
{
    length[0] = 1; //FX, index 0부터 시작하므로 2가 아닌 1
    for (int i = 1; i <= 50; i++)
        length[i] = min(MAX, length[i - 1] * 2 + 2); //X를 n세대 진화시킨 결과의 길이 = n-1세대 진화시킨 X의 길이 + n-1세대 진화시킨 Y의 길이 + 2
}

//dragonCurve를 generations 진화시킨 결과에서 skip번째 문자 반환
char expand(const string& dragonCurve, int generations, int skip)
{
    //기저 사례
    if (generations == 0)
    {
        if (skip > dragonCurve.size()) //더 이상 확장되지 않는데 문자열 크기보다 skip이 큰 경우 프로그램 종료
            exit(-1);
        return dragonCurve[skip];
    }
    for (int i = 0; i < dragonCurve.size(); i++)
    {
        //문자열이 확장된 경우
        if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y')
        {
            if (skip >= length[generations])
                skip -= length[generations];
            else if (dragonCurve[i] == 'X')
                return expand(EXPAND_X, generations - 1, skip);
            else
                return expand(EXPAND_Y, generations - 1, skip);
        }
        //확장되진 않지만 건너뛰어야할 경우
        else if (skip > 0)
            --skip;
        //답을 찾은 경우
        else
            return dragonCurve[i];
    }
}

int main(void)
{
    int test_case;
    cin >> test_case;
    if (test_case < 1 || test_case>50)
        exit(-1);
    preCalculate();

    for (int i = 0; i < test_case; i++)
    {
        int generation, skip, range;
        cin >> generation >> skip >> range;
        if (generation < 0 || generation>50 || skip < 1 || skip>1000000000 || range < 1 || range>50)
            exit(-1);

        for (int j = 0; j < range; j++) //skip번째 문자부터 range만큼 글자 출력
            cout << expand("FX", generation, skip + j - 1);
        cout << endl;
    }
    return 0;
}
