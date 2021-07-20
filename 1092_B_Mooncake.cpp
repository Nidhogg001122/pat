#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct mooncake {
	int id;
	int sellnum;
};

bool cmp(struct mooncake a, struct mooncake b) {
	return a.sellnum != b.sellnum ? a.sellnum > b.sellnum:a.id < b.id;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<mooncake> count(N);
	int i, j;
	for (i = 0; i < N; i++) {
		count[i].id = i + 1;
		count[i].sellnum = 0;
	}
	int num;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			cin >> num;
			count[j].sellnum += num;
		}
	}
	sort(count.begin(), count.end(), cmp);
	cout << count[0].sellnum << endl;
	cout << count[0].id;
	for (i = 1; i < N; i++) {
		if (count[i].sellnum == count[0].sellnum) {
			cout << ' ' << count[i].id;
		}
		else break;
	}
	cout << endl;
	return 0;
}