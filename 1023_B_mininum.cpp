#include<cstdio>
using namespace std;

int main() {
	int i = 0,num[10],j=0;
	for (i = 0; i < 10; i++) {
		scanf("%d", &num[i]);		//��¼0~9��Ŀ
	}
	for (i = 1; i <= 9; i++) {		//���ڲ���0��ͷ������1~9��Ѱ�ҵ�һλ
		if (num[i]) {
			printf("%d", i);
			num[i]--;
			break;
		}
	}
	for (i = 0; i <= 9; i++) {		//��0~9�������С����ÿһλ��ѡ��С
		if (num[i]) {
			for (j = 0; j < num[i]; j++) {
				printf("%d", i);
			}
		}
	}
}