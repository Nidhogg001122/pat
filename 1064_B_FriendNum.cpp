#include+<cstdio>
#include<algorithm>
using namespace std;

/*
* ���������������Ŀ��Ҫ������Ϊ����Ѱ������֤��
* �����������ж����ֲ�ͬ�ĺ�
* ���磺
* 8
* 123 899 51 998 27 33 36 12
* 
* 1+2+3=5+1=3+3=6
* 8+9+9=9+9+8=26
* 2+7=3+6=9
* 
* ����Ϊ������֤��ֻ��6��9��26
* ��������������ӣ�������Ŀ������3�����
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