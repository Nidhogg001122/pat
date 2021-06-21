#include+<cstdio>
#include<algorithm>
using namespace std;

/*
* 可能是我误解了题目的要求。我以为它在寻求朋友证号
* 结果输出的是有多少种不同的和
* 例如：
* 8
* 123 899 51 998 27 33 36 12
* 
* 1+2+3=5+1=3+3=6
* 8+9+9=9+9+8=26
* 2+7=3+6=9
* 
* 我认为的朋友证号只有6，9，26
* 而无论是输出例子，还是题目，都有3这个答案
*/

int temp[64] = { 0 };
int friendnum[64];

int main() {
	int n, i, num, sum;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		sum = 0;
		while (num) {
			sum += num % 10;
			num /= 10;
		}
		temp[sum]++;
	}
	int count = 0;
	for (i = 0; i < 64; i++) {
		if (temp[i] > 1) {
			friendnum[count] = i;
			count++;
		}
	}
	printf("%d ", count);
	for (i = 0; i < count - 1; i++) printf("%d ", friendnum[i]);
	printf("%d\n", friendnum[i]);
	return 0;
}