//对任何一个正整数 n，如果它是偶数，那么把它砍掉一半；如果它是奇数，那么把 (3n+1) 砍掉一半。
//现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。
//你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int num[100], result[100] = { 0 }, printTxt[100];

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int i, j, n, temp;
	cin >> n;
	for (i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n, cmp);	//将输入数据从大到小排序，便于输出
	for (i = 0; i < n; i++) {
		temp = num[i];
		while (temp != 1)
		{
			if (temp % 2)
			{
				temp = (3 * temp + 1) / 2;
				for (j = 0; j < n; j++) {
					if (temp == num[j]) {
						result[j] = 1;	//此数可被其他数查找，不是关键数
						break;
					}
				}
			}
			else
			{
				temp = temp / 2;
				for (j = 0; j < n; j++) {
					if (temp == num[j]) {
						result[j] = 1;	//此数可被其他数查找，不是关键数
						break;
					}
				}
			}
		}
	}
	for (i = 0, j = 0; i < n; i++) {
		if (result[i] == 0) printTxt[j++] = num[i];
	}
	for (i = 0; i < j - 1; i++) {
		cout << printTxt[i] << " ";
	}
	cout << printTxt[i] << endl;
	return 0;	//对于pat的 奇葩要求，返回值必须是0
}