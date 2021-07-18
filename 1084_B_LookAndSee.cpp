#include<iostream>
#include<cstring>
using namespace std;

void next(char* a, char* b) {
	int length = strlen(a);
	if (length == 1) {
		b[0] = a[0];
		b[1] = '1';
		b[2] = '\0';
	}
	else {
		int i, j, k, count = 1;
		for (i = 0, j = 1, k = 0; j < length; j++, i++) {
			if (a[i] == a[j]) {
				count++;
			}
			else {
				b[k++] = a[i];
				b[k++] = count+48;
				count = 1;
			}
		}
		b[k++] = a[i];
		b[k++] = count + 48;
		b[k] = '\0';
	}
}

int main() {
	int N;
	char d[100000], d_next[100000]; // 在次数越来越多时，字符串的长度急剧增长
	cin >> d >> N;
	for (int i = 0; i < N - 1; i++) {
		next(d, d_next);
		strcpy(d, d_next);
	}
	cout << d << endl;
	return 0;
}