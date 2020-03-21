#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;
//물건 개수, 제한부피
int n, W;

int volume[100];
int need[100];
int cache[100][100001];
//캐리어에 남은 용량


//item : 몇번째 물건인지 index
//V : 지금까지 캐리어의 부피
int pack(int item, int V) {
	//기저사례 : 더 담을 물건이 없다
	if (item == n)return 0;
	int& ret =cache[item][V];
	if (ret != -1)return ret;
	
	//ret = 0;
	//물건을 담는 경우
	if (V + volume[item] <= W)
		if (pack(item + 1, V + volume[item])> ret)
			ret = pack(item + 1, V + volume[item]) + need[item];
	//물건을 담지 않는 경우
	if (pack(item + 1, V) > ret)
		ret = pack(item + 1, V);

	return ret;
}
//pack에서 선택한 물건 목록을 picked에 쌓는다
void reconstruct(int item, int V, vector<int>& picked) {
	if (item == n)return;

	if (pack(item, V) == pack(item + 1, V))
		reconstruct(item + 1, V, picked);

	else {
		picked.push_back(item);
		reconstruct(item + 1, V + volume[item], picked);
	}
}
//메인
int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		//무게저장할 cache와 각 물건의절박감,부피저장할 배열 초기화
		memset(cache, -1, sizeof(cache));
		memset(need, 0, sizeof(need));
		memset(volume, 0, sizeof(volume));
		//개수, 제한무게 입력받음
		cin >> n >> W;
		//str 벡터에 물건 이름 입력받음
		vector<string>str;
		for (int i = 0; i < n; ++i) {
			string x;
			cin >> x >> volume[i] >> need[i];
			str.push_back(x);
		}
		//pack 재귀 시작 (현재까지 캐리어의무게 0, index도 0)
		int maxv = pack(0, 0);
		//절박도가 최대가 되도록 고른 것들의 index저장할 picked벡터
		vector<int>picked;
		reconstruct(0, 0, picked);

		//결과 출력
		cout << maxv << ' ' << picked.size() << '\n';
		for (int i = 0; i < picked.size(); ++i)
			cout << str[picked[i]] << '\n';
	}
	return 0;
}
