#include<iostream>
#include<cstring>
using namespace std;

void reverse(char *a) {
	int length = strlen(a);
	int temp = 0;
	for (int i = 0; i < length / 2; i++) {
		temp = a[i];
		a[i] = a[length - i - 1];
		a[length - i - 1] = temp;
	}
}

int main() {
	char N[32], num1[32], num2[32];
	int result[32];
	cin >> N >> num1 >> num2;
	int len1 = strlen(num1), len2 = strlen(num2);
	reverse(N);
	reverse(num1);
	reverse(num2);
	int i = 0, add1, add2, temp, c = 0, mod;
	while (len1 > 0 || len2 > 0) {
		if (len1 <= 0) add1 = 0;
		else add1 = num1[i] - 48;
		if (len2 <= 0) add2 = 0;
		else add2 = num2[i] - 48;
		temp = add1 + add2 + c;
		if (N[i] == '0' || N[i] == 'd') mod = 10;
		else mod = N[i] - 48;
		result[i] = temp % mod;
		c = temp / mod;
		len1--;
		len2--;
		i++;
	}
	result[i] = c;
	int j = i;
	for (i = 0; i <= j / 2; i++) {
		temp = result[i];
		result[i] = result[j - i];
		result[j - i] = temp;
	}
	i = 0;
	while (result[i] == 0) i++;
	if (i == j + 1) cout << 0;
	else while (i <= j) cout << result[i++];
	cout << endl;
	return 0;
}