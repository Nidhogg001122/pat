//对任何一个正整数 n，如果它是偶数，那么把它砍掉一半；如果它是奇数，那么把 (3n+1) 砍掉一半。
//现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。
//你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {	//从大到小排序
	return a > b;
}
int main() {
	int n, num[100], result[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);	//读入数据
	sort(num, num + n, cmp);	// 数据排序
	int travel[100][100] = { 0 };	//定义二维数组，每一行记录第i个数据遍历元素，全为零的那一列对应关键值
	int temp;
	for (int i = 0; i < n; i++) {
		temp = num[i];
		while (temp != 1)	//验证当前数3n+1猜想
		{
			if (temp % 2)
			{
				temp = (3 * temp + 1) / 2;
				for (int j = 0; j < n; j++) {	//记录验证过的数
					if (temp == num[j]) travel[i][j] == 1;
					break;
				}
			}
			else
			{
				temp = temp / 2;
				for (int j = 0; j < n; j++) {	//记录验证过的数
					if (temp == num[j]) travel[i][j] == 1;
					break;
				}
			}
		}	
	}
	int flag,k=0;
	for (int i = 0; i < n; i++) {
		flag = 1;
		for (int j = 0; j < n; j++) {
			if (travel[j][i]) {
				flag = 0;
				break;
			}
		}
		if (flag) result[k++] = num[i];
	}
	for (int i = 0; i < k-1; i++) {
		printf("%d ", result[i]);
	}
	printf("%d", result[k-1]);
	return 1;
}