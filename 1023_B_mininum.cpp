#include<cstdio>
using namespace std;

int main() {
	int i = 0,num[10],j=0;
	for (i = 0; i < 10; i++) {
		scanf("%d", &num[i]);		//记录0~9数目
	}
	for (i = 1; i <= 9; i++) {		//由于不能0开头，故在1~9中寻找第一位
		if (num[i]) {
			printf("%d", i);
			num[i]--;
			break;
		}
	}
	for (i = 0; i <= 9; i++) {		//从0~9中输出最小数，每一位都选最小
		if (num[i]) {
			for (j = 0; j < num[i]; j++) {
				printf("%d", i);
			}
		}
	}
}