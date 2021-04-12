#include<cstdio>
using namespace std;

const int maxn = 1000001;	//��Χ������
int prime[maxn], num = 0;
bool judge[maxn];

void primeTable(int n) {
	for (int i = 2; i < maxn; i++) {
		if (judge[i] == false) {
			prime[num++] = i;
			if (num > n) break;	//С��n�����˳�
			for (int j = i + i; j < maxn; j += i) {
				judge[j] = true;
			}
		}
	}
}


int main() {
	int m, n, count = 0;
	scanf("%d%d", &m, &n);
	primeTable(n);
	for (int i = m; i <= n; i++) {
		printf("%d", prime[i - 1]);
		count++;
		if (count == 10) {
			printf("\n");
			count = 0;
		}
		else if (i < n) printf(" ");
	}
	return 0;
}