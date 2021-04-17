#include<cstdio>
using namespace std;

int main() {
	char num[1001];		//注意数据应该较大于测试极限
	int result[1001];
	char c;
	int sum = 0;
	int i = 0, j = 0;
	scanf("%c", &c);
	while (c != '\n') {
		num[i] = c;
		scanf("%c", &c);
		i++;
	}
	num[i] = '\0';
	i = 0;
	while (num[i] != '\0') {
		sum += num[i++] - 48;	//字符转为数字
	}
	while (sum > 0) {
		i = sum % 10;
		result[j++] = i;
		sum = sum / 10;
	}
	j = j - 1;
	while (j >= 0) {
		switch (result[j]) {	//其实最难的反而是写对拼音
		case 0:
		{
			printf("ling");
			break;
		}
		case 1:
		{
			printf("yi");
			break;
		}
		case 2:
		{
			printf("er");
			break;
		}
		case 3:
		{
			printf("san");
			break;
		}
		case 4:
		{
			printf("si");
			break;
		}
		case 5:
		{
			printf("wu");
			break;
		}
		case 6:
		{
			printf("liu");
			break;
		}
		case 7:
		{
			printf("qi");
			break;
		}
		case 8:
		{
			printf("ba");
			break;
		}
		case 9:
		{
			printf("9");
			break;
		}
		}
		if (j == 0) printf("\n");
		else printf(" ");
		j--;
	}
}
