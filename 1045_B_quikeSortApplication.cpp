#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/*
 * ����һ�����п�������ѡȡ����Ԫ����ߵ���С�������ұߴ�����
 * ������������н��е���������Ԫ��λ��Ӧ���ǲ����
 * ��Ȼ������λ�ò���ľ�����Ԫ������Ӧ���������������
 * ���磺1543�������1345������4��λ�ò��䣬������δ��ѡΪ��Ԫ
*/

int main() {
	int n, i, num = 0, result[100010];
	scanf("%d", &n);
	vector<int> input(n), temp(n);	//�൱�ڿɱ䳤�ȵ�����
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
	printf("\n"); //�е���̱����ʹû�����ݣ������������
	return 0;
}