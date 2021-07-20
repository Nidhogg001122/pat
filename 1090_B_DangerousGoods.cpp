#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int a, b, i, j;
	map<int, int> danger;
	for (i = 0; i < N; i++) {
		cin >> a >> b;
		danger.insert(make_pair(a, b));
		danger.insert(make_pair(b, a));
	}
	int num, judge, good;
	for (i = 0; i < M; i++) {
		cin >> num;
		vector<int> goods;
		for (j = 0; j < num; j++) {
			cin >> good;
			goods.push_back(good);
		}
		judge = 1;
		for (j = 0; j < num; j++) {
			if (danger.find(goods[j]) != danger.end()) {
				if (find(goods.begin(), goods.end(), danger[goods[j]]) != goods.end()) {
					judge = 0;
					break;
				}
			}
		}
		if (judge == 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}