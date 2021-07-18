#include<iostream>
#include<cstring>
using namespace std;

//输入有空格，不能直接读入

int main() {
	char pass[128], c;
	int n, i, j, length;
	bool num, letter, judge;
	cin >> n;
	c = getchar();
	for (i = 0; i < n; i++) {
		j = 0;
		c = getchar();
		while (c != '\n') {
			pass[j++] = c;
			c = getchar();
		}
		pass[j] = '\0';
		length = strlen(pass);
		if (length < 6) cout << "Your password is tai duan le." << endl;
		else {
			num = false;
			letter = false;
			judge = true;
			for (j = 0; j < length; j++) {
				if ((pass[j] < '0' && pass[j] != '.') || (pass[j] > '9' && pass[j] < 'A') || (pass[j] > 'Z' && pass[j] < 'a') || pass[j] > 'z') {
					judge = false;
					break;
				}
				if (pass[j] >= '0' && pass[j] <= '9') num = true;
				if ((pass[j] >= 'A' && pass[j] <= 'Z') || (pass[j] >= 'a' && pass[j] <= 'z')) letter = true;
			}
			if (judge) {
				if (num && letter) cout << "Your password is wan mei." << endl;
				else if (num && !letter) cout << "Your password needs zi mu." << endl;
				else cout << "Your password needs shu zi." << endl;
			}
			else cout << "Your password is tai luan le." << endl;
		}
	}
	return 0;
}