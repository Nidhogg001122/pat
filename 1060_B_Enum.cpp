#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

/*
* “爱丁顿数” E ，即满足有 E 天骑车超过 E 英里的最大整数 E
* 将输入的骑行数据（从下标1开始存储），从大到小排序
* 设开始爱丁顿数Enum为0
* 若当前骑行数大于下标，则Enum++
* 例如：
* 下标：1，2，3，4，5
* 数值：5，4，3，2，1
* 5>1,Enum++，说明有1天大于1，4>2,由于是递减排序，4之前的数也大于2，故有2天大于2，Enum++变大；
* 以此类推，直到某个数不再大于下标，退出，此时的Enum为最大；
*/

/*
* 关于为何下标不像从前一样从0开始：
* 考虑下列情况
* 下标：0，1，2，3，4
* 数值：1，0，0，0，0（或者1，1，1，1，1）
* 因为1>0,得到的结果为1，但其实并没有1天骑行数超过1
*/

int length[100010];

int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &length[i]);
	sort(length + 1, length + i + 1, cmp);
	int Enum = 0;
	for (i = 1; i <= n; i++) {
		if (length[i] > i) Enum++;
		else break;
	}
	printf("%d\n", Enum);
	return 0;
}