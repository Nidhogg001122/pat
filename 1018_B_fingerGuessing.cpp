#include<cstdio>
#include<iostream>
using namespace std;

typedef struct data {
	int win = 0;
	int draw = 0;
	int lose = 0;
	int c = 0;
	int j = 0;
	int b = 0;
}Count;

char game[100001][2];

int main() {
	int num, i;
	cin >> num;
	for (i = 0; i < num; i++) scanf("%s %s", &game[i][0], &game[i][1]);
	Count A, B;
	for (i = 0; i < num; i++) {
		if (game[i][0] == 'C' && game[i][1] == 'J') {
			A.c++;
			A.win++;
			B.lose++;
		}
		else if (game[i][1] == 'C' && game[i][0] == 'J') {
			B.c++;
			B.win++;
			A.lose++;
		}
		else if (game[i][0] == 'J' && game[i][1] == 'B') {
			A.j++;
			A.win++;
			B.lose++;
		}
		else if (game[i][1] == 'J' && game[i][0] == 'B') {
			B.j++;
			B.win++;
			A.lose++;
		}
		else if (game[i][0] == 'B' && game[i][1] == 'C') {
			A.b++;
			A.win++;
			B.lose++;
		}
		else if (game[i][1] == 'B' && game[i][0] == 'C') {
			B.b++;
			B.win++;
			A.lose++;
		}
		else {
			A.draw++;
			B.draw++;
		}
	}
	char maxA, maxB;
	if (A.b >= A.c) {
		if (A.c >= A.j) maxA = 'B';
		else {
			if (A.b >= A.j) maxA = 'B';
			else maxA = 'J';
		}
	}
	else {
		if (A.c >= A.j) maxA = 'C';
		else maxA = 'J';
	}
	if (B.b >= B.c) {
		if (B.c >= B.j) maxB = 'B';
		else {
			if (B.b >= B.j) maxB = 'B';
			else maxB = 'J';
		}
	}
	else {
		if (B.c >= B.j) maxB = 'C';
		else maxB = 'J';
	}
	printf("%d %d %d\n%d %d %d\n%c %c\n", A.win, A.draw, A.lose, B.win, B.draw, B.lose, maxA, maxB);
	return 0;
}