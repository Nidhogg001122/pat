#include<algorithm>
using namespace std;

/*
* 设有一个无序序列：1 5 7 4 6 3
* 若使用插入排序，第一次发生改变为：1 4 5 7 6 3
* 若使用归并排序，第一次变化后为：1 5 4 7 3 6
* 使用插入排序的特点是一次仅改变一个数据的位置，也就是说，下一个待排序的
* 数据和原序列中的位置是一致的，例子中的插入排序下一个处理6，它与原序列6
* 还在同一位置，可依此判断排序方法；
*/

int main() {
	int num, input[110], output[110];
	int i;
	scanf("%d", &num);
	for (i = 0; i < num; i++) scanf("%d", &input[i]);
	for (i = 0; i < num; i++) scanf("%d", &output[i]);
	bool judge = true;
	int j = 0;
	for (i = 0; i < num - 1; i++) {
		if (output[i] > output[i + 1]) {
			j = i;
			break;
		}
	}
	int current = j;
	for (j = j + 1; j < num; j++) {
		if (input[j] != output[j]) judge = false;
	}
	if (judge) {
		printf("Insertion Sort\n");
		sort(input, input + current + 2);	//current表示当前数据后的数据是需要处理的，故sort时加2
	}
	else {
		printf("Merge Sort\n");
		//对原序列使用归并排序，直到和给出的中间序列相同，再进行一轮后输出
		int same = 1, k = 1;
		while (same) {
			same = 0;
			for (i = 0; i < num; i++) {
				if (input[i] != output[i]) {
					same = 1;
					break;		//还是和中间序列不同，继续归并
				}
			}
			k = k * 2;
			for (i = 0; i < num / k; i++) {
				sort(input + i * k, input + (i + 1) * k);
			}
			sort(input + num / k * k, input + num);
		}
	}
	for (i = 0; i < num - 1; i++) printf("%d ", input[i]);
	printf("%d\n", input[i]);
	return 0;
}