#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char info[4][64];
	int week, hour, min;
	int i = 0, j = 0;
	for (i = 0; i < 4; i++) {
		cin >> info[i];
	}
	char temp;
	for (i = 0; i < strlen(info[0]) && i < strlen(info[1]); i++) {
		temp = info[0][i];
		if (temp >= 'A' && temp <= 'G') {
			if (temp == info[1][i]) {
				week = temp - 'A' + 1;
				break;
			}
		}
	}

	for (j = i + 1; j < strlen(info[0]) && j < strlen(info[1]); j++) {
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
	for (i = 0; i < strlen(info[2]) && i < strlen(info[3]); i++) {
		temp = info[2][i];
		if (temp >= 'A' && temp <= 'z') {
			if (temp == info[3][i]) {
				min = i;
				break;
			}
		}
	}
	//MON ��ʾ����һ��TUE ��ʾ���ڶ���WED ��ʾ��������THU ��ʾ�����ģ�FRI ��ʾ�����壬SAT ��ʾ��������SUN ��ʾ������
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