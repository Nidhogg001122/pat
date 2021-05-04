#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char info[4][64];	//记录句子
	int week, hour, min;
	int i = 0, j = 0;
	for (i = 0; i < 4; i++) {
		cin >> info[i];
	}
	char temp;
	for (i = 0; i < strlen(info[0]) && i < strlen(info[1]); i++) {
		temp = info[0][i];
		if (temp >= 'A' && temp <= 'G') {	//寻找第一对相同的大写字母，已知一周七天，仅比较到G
			if (temp == info[1][i]) {
				week = temp - 'A' + 1;
				break;
			}
		}
	}

	for (j = i + 1; j < strlen(info[0]) && j < strlen(info[1]); j++) {	//由题意，在找到星期后继续寻找第二对相同数字或大写字母
		temp = info[0][j];
		if (temp == info[1][j]) {
			if (temp >= '0' && temp <= '9') {
				hour = temp - 48;
				break;
			}
			else if (temp >= 'A' && temp <= 'N') {
				hour = temp - 'A' + 10;
				break;
			}
		}
	}
	for (i = 0; i < strlen(info[2]) && i < strlen(info[3]); i++) {		//寻找相同字母
		temp = info[2][i];
		if (temp >= 'A' && temp <= 'z') {
			if (temp == info[3][i]) {
				min = i;
				break;
			}
		}
	}
	//MON 表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示星期五，SAT 表示星期六，SUN 表示星期日
	switch (week)
	{
	case 1: {
		cout << "MON ";
		break;
	}
	case 2: {
		cout << "TUE ";
		break;
	}
	case 3: {
		cout << "WED ";
		break;
	}
	case 4: {
		cout << "THU ";
		break;
	}
	case 5: {
		cout << "FRI ";
		break;
	}
	case 6: {
		cout << "SAT ";
		break;
	}
	case 7: {
		cout << "SUN ";
		break;
	}
	}
	printf("%02d:%02d\n", hour, min);
	return 0;
}
