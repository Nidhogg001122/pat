//���κ�һ�������� n���������ż������ô��������һ�룻���������������ô�� (3n+1) ����һ�롣
//���ڸ���һϵ�д���֤�����֣�����ֻ��Ҫ��֤���еļ����ؼ������Ϳ��Բ������ظ���֤���µ����֡�
//�����������ҳ���Щ�ؼ����֣������Ӵ�С��˳��������ǡ�

#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {	//�Ӵ�С����
	return a > b;
}
int main() {
	int n, num[100], result[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);	//��������
	sort(num, num + n, cmp);	// ��������
	int travel[100][100] = { 0 };	//�����ά���飬ÿһ�м�¼��i�����ݱ���Ԫ�أ�ȫΪ�����һ�ж�Ӧ�ؼ�ֵ
	int temp;
	for (int i = 0; i < n; i++) {
		temp = num[i];
		while (temp != 1)	//��֤��ǰ��3n+1����
		{
			if (temp % 2)
			{
				temp = (3 * temp + 1) / 2;
				for (int j = 0; j < n; j++) {	//��¼��֤������
					if (temp == num[j]) travel[i][j] == 1;
					break;
				}
			}
			else
			{
				temp = temp / 2;
				for (int j = 0; j < n; j++) {	//��¼��֤������
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