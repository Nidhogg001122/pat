#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/*
 * 对于一个进行快速排序选取的主元，左边的数小于它，右边大于它
 * 若对输入的序列进行递增排序，主元的位置应当是不变的
 * 当然并不是位置不变的就是主元，它还应大于它左边所有数
 * 例如：1543，排序后1345，对于4，位置不变，但它还未被选为主元
*/

int main() {
	int n, i, num = 0, result[100010];
	scanf("%d", &n);
	vector<int> input(n), temp(n);	//相当于可变长度的数组
	for (i = 0; i < n; i++) {
		scanf("%d", &input[i]);
		temp[i] = input[i];
	}
	sort(temp.begin(), temp.end());
	int max = 0;
	for (i = 0; i < n; i++) {
		if (input[i] == temp[i] && input[i] > max) result[num++] = input[i];
		if (input[i] > max) max = input[i];
	}
	printf("%d\n", num);
	if (num != 0) {
		for (i = 0; i < num - 1; i++) printf("%d ", result[i]);
		printf("%d", result[i]);
	}
	printf("\n"); //有点脑瘫，即使没有数据，依旧输出空行
	return 0;
}