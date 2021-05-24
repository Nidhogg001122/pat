#include<algorithm>
using namespace std;

/*
* ����һ���������У�1 5 7 4 6 3
* ��ʹ�ò������򣬵�һ�η����ı�Ϊ��1 4 5 7 6 3
* ��ʹ�ù鲢���򣬵�һ�α仯��Ϊ��1 5 4 7 3 6
* ʹ�ò���������ص���һ�ν��ı�һ�����ݵ�λ�ã�Ҳ����˵����һ���������
* ���ݺ�ԭ�����е�λ����һ�µģ������еĲ���������һ������6������ԭ����6
* ����ͬһλ�ã��������ж����򷽷���
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
		sort(input, input + current + 2);	//current��ʾ��ǰ���ݺ����������Ҫ����ģ���sortʱ��2
	}
	else {
		printf("Merge Sort\n");
		//��ԭ����ʹ�ù鲢����ֱ���͸������м�������ͬ���ٽ���һ�ֺ����
		int same = 1, k = 1;
		while (same) {
			same = 0;
			for (i = 0; i < num; i++) {
				if (input[i] != output[i]) {
					same = 1;
					break;		//���Ǻ��м����в�ͬ�������鲢
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