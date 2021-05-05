#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

struct bignum {	//结构存储大数
	int num[1001];	//数据
	int len;		//长度
	bignum() {		//初始化
		memset(num, 0, sizeof(num));
		len = 0;
	}
};

int R = 0;		//保留余数

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
	while (C.len > 1 && C.num[C.len - 1] == 0) C.len--;	//C至少有一位，在减去高位0时边界为至少保留一位;
	for (i = C.len - 1; i >= 0; i--) printf("%d", C.num[i]);
	printf(" %d\n", R);
	return 0;
}