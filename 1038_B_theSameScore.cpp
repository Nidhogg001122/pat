#include<cstdio>
using namespace std;

int score[100] = { 0 };

int main() {
	int num, serchnum;
	scanf("%d", &num);
	int i, input,serchscore;
	for (i = 0; i < num; i++) {
		scanf("%d", &input);
		score[input]++;
	}
	scanf("%d", &serchnum);
	for (i = 0; i < serchnum; i++) {
		scanf("%d", &serchscore);
		printf("%d", score[serchscore]);
		if (i < serchnum - 1) printf(" ");
	}
	printf("\n");
	return 0;
}