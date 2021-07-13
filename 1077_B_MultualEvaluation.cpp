#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct {
	int teacher;
	int student[128];
}score[128];

int main() {
	int N, M;
	cin >> N >> M;
	int i, j, temp;
	for (i = 0; i < N; i++) {
		cin >> score[i].teacher;
		for (j = 0; j < N - 1; j++) {
			cin >> temp;
			if (temp >= 0 && temp <= M) score[i].student[j] = temp;
			else score[i].student[j] = -1;
		}
		sort(score[i].student, score[i].student + N - 1);
	}
	float sum, avg;
	int min, count;
	for (i = 0; i < N; i++) {
		sum = score[i].teacher;
		min = 1;
		avg = 0;
		count = 0;
		for (j = 0; j < N - 2; j++) {
			if (score[i].student[j] == -1) continue;
			else if (min == 1) {
				min = 0;
				continue;
			}
			else {
				avg += score[i].student[j];
				count++;
			}
		}
		avg /= count;
		printf("%d\n", (int)((sum + avg) / 2 + 0.5));
	}
	return 0;
}