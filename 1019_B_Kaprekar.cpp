#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int toNum(int a[]) {//数组变成数字
	int num = 0, i;
	for (i = 0; i < 4; i++) {
		num = num * 10 + a[i];
	}
	return num;
}

void toArray(int num, int a[]) {//数字变成数组
	for (int i = 0; i < 4; i++) {
		a[i] = num % 10;
		num /= 10;
	}
}

int main() {
	int num = 0, a[4], max, min;
	scanf("%d", &num);
	while (1) {
		toArray(num, a);
		sort(a, a + 4);//默认从小到大排序
		min = toNum(a);
		sort(a, a + 4, cmp);//从大到小排序
		max = toNum(a);
		num = max - min;
		printf("%04d - %04d = %04d\n", max, min, num);
		if (num == 0 || num == 6174) break;
	}
	return 0;
}