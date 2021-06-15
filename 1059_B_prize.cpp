#include<cstdio>
#include<cmath>
using namespace std;

struct data {
	int rank;
	int judge;
}result[10010];

bool prime(int a) {
	int temp = sqrt(a);
	for (int i = 2; i <= temp; i++) {
		if (a % i == 0) return false;
	}
	return true;
}


int main() {
	int n, m, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &result[i].rank);
		result[i].judge = 0;
	}
	int input, find;
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		find = 0;
		scanf("%d", &input);
		for (j = 0; j < n; j++) {
			if (result[j].rank == input) {
				find = 1;
				if (result[j].judge == 0) {
					result[j].judge = 1;
					if (j == 0) printf("%04d: Mystery Award\n", input);
					else if (prime(j + 1)) printf("%04d: Minion\n", input);
					else printf("%04d: Chocolate\n", input);
					break;
				}
				else {
					printf("%04d: Checked\n", input);
					break;
				}
			}
		}
		if (find == 0) printf("%d: Are you kidding?\n", input);
	}
	return 0;
}