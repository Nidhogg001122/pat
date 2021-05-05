#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

struct bignum {	//�ṹ�洢����
	int num[1001];	//����
	int len;		//����
	bignum() {		//��ʼ��
		memset(num, 0, sizeof(num));
		len = 0;
	}
};

int R = 0;		//��������

int main() {
	bignum A, C;
	char input[1001];
	int B;
	cin >> input >> B;
	int i = 0, j = strlen(input) - 1;
	A.len = strlen(input);
	for (i = 0; i < strlen(input); i++) A.num[i] = input[j--]-48;
	C.len = A.len;
	int temp = 0;
	for (i = A.len - 1; i >= 0; i--) {
		temp = R * 10 + A.num[i];
		if (temp >= B) {
			C.num[i] = temp / B;
			R = temp % B;
		}
		else {
			C.num[i] = 0;
			R = temp;
		}
	}
	while (C.len > 1 && C.num[C.len - 1] == 0) C.len--;	//C������һλ���ڼ�ȥ��λ0ʱ�߽�Ϊ���ٱ���һλ;
	for (i = C.len - 1; i >= 0; i--) printf("%d", C.num[i]);
	printf(" %d\n", R);
	return 0;
}