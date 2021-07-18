#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct data{
	int id;
	double result;
}score[10010];

bool cmp(struct data a, struct data b) {
	return a.result > b.result;
}

int main() {
	int n, i, x, y;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> score[i].id >> x >> y;
		score[i].result = sqrt(x * x + y * y);
	}
	sort(score, score + n, cmp);
	printf("%04d %04d\n", score[n - 1].id, score[0].id);
	return 0;
}