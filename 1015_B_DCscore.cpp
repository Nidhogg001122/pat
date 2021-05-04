#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct data {
	int id = 0;
	int Dscore = 0;
	int Cscore = 0;
	int sum = 0;
}score[100001];

bool cmp(struct data a, struct data b) {
	if (a.sum != b.sum) return a.sum > b.sum;
	else {
		if (a.Dscore != b.Dscore) return a.Dscore > b.Dscore;
		else return a.id < b.id;
	}
}

struct data first[100001];
struct data second[100001];
struct data third[100001];
struct data fourth[100001];

int main() {
	int total, L, H, i, j, k, m, n;
	int count = 0;
	cin >> total >> L >> H;
	for (i = 0; i < total; i++) {
		cin >> score[i].id >> score[i].Dscore >> score[i].Cscore;
		score[i].sum = score[i].Dscore + score[i].Cscore;
	}
	for (i = 0, j = 0, k = 0, m = 0, n = 0; i < total; i++) {
		if (score[i].Dscore >= L && score[i].Cscore >= L) {
			count++;
			if (score[i].Dscore >= H && score[i].Cscore >= H) first[j++] = score[i];
			else if (score[i].Dscore >= H && score[i].Cscore < H) second[k++] = score[i];
			else if (score[i].Dscore < H && score[i].Cscore < H && score[i].Dscore >= score[i].Cscore) third[m++] = score[i];
			else fourth[n++] = score[i];
		}
	}

	sort(first, first + j, cmp);
	sort(second, second + k, cmp);
	sort(third, third + m, cmp);
	sort(fourth, fourth + n, cmp);
	printf("%d\n", count);
	for (i = 0; i < j; i++) printf("%d %d %d\n", first[i].id, first[i].Dscore, first[i].Cscore);
	for (i = 0; i < k; i++) printf("%d %d %d\n", second[i].id, second[i].Dscore, second[i].Cscore);
	for (i = 0; i < m; i++) printf("%d %d %d\n", third[i].id, third[i].Dscore, third[i].Cscore);
	for (i = 0; i < n; i++) printf("%d %d %d\n", fourth[i].id, fourth[i].Dscore, fourth[i].Cscore);
	return 0;
}