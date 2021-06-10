#include<cstdio>
#include<iostream>
using namespace std;

bool judge(char* temp) {
	int i = 0;
	int dot = 0, integer = 0, decimal = 0;
	if (temp[0] == '-') i = 1;	//对负数进行处理
	for (; temp[i] != '\0'; i++) {
		if ((temp[i] < '0' || temp[i]>'9') && temp[i] != '.') return false;	//有非法字符，不为有效数据
		if (dot == 1 && temp[i] == '.') return false;	//出现两次小数点，非法
		if (dot > 0) decimal++;
		if (temp[i] == '.') dot = 1;	//记录第一次出现小数点
		if (dot == 0) integer++;	//整数位数
	}
	if (decimal > 2) return false;
	double a = atof(temp);	//将字符串转换为浮点数
	if (a < -1000.0 || a>1000.0) return false;
	return true;
}

int main() {
	int n, i;
	scanf("%d", &n);
	char input[128];
	int num = 0;
	double sum = 0, average;
	for (i = 0; i < n; i++) {
		scanf("%s", &input);
		if (judge(input)) {
			num++;
			sum += atof(input);
		}
		else {
			printf("ERROR: %s is not a legal number\n", input);
		}
	}
	average = sum / num;
	if (num == 0) printf("The average of 0 numbers is Undefined\n");
	else if (num == 1) printf("The average of 1 number is %.2f\n", average);
	else printf("The average of %d numbers is %.2f\n", num, average);
	return 0;
}
