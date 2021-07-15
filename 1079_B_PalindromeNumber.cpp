#include<iostream>
#include<cstring>
using namespace std;

char num[1024], reversal[1024], sum[1024], sumtemp[1024];

void reverse(char* a,char* b) {
	//将a反转为b
	int length = strlen(a);
	for (int i = 0; i < length ; i++) b[length - i - 1] = a[i];
	b[length] = '\0';
}

void add(char* a, char* b, char* c) {
	int length = strlen(a), cout = 0, temp;
	//本来需要反转从低位相加，但这两个数本身就是反转关系
	for (int i = 0; i < length; i++) {
		temp = a[i] - 48 + b[i] - 48 + cout;
		sumtemp[i] = temp % 10 + 48;
		cout = temp / 10;
	}
	if (cout != 0) sumtemp[length++] = cout + 48;
	reverse(sumtemp,c);
	c[length] = '\0';
}

bool judge(char *a) {
	int length = strlen(a);
	for (int i = 0; i < length / 2; i++) {
		if (a[i] == a[length - i - 1]) continue;
		else return false;
	}
	return true;
}

int main() {
	cin >> num;
	if (num[0] == '0') cout << "0 is a palindromic number." << endl;
	else {
		int i;
		for (i = 0; i < 10; i++) {
			if (judge(num)) {
				cout << num << " is a palindromic number." << endl;
				break;
			}
			else {
				reverse(num,reversal);
				add(num, reversal, sum);
				cout << num << " + " << reversal << " = " << sum << endl;
				for (int i = 0, length = strlen(sum); i < length; i++) num[i] = sum[i];
			}
		}
		if (i == 10) cout << "Not found in 10 iterations." << endl;
	}
	return 0;
}