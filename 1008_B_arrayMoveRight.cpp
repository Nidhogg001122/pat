#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int n, num[202], right,i;
	cin >> n >> right;
	right = right % n;
	for (i = 1; i <= n; i++) cin >> num[i];
	int temp = 0;
	for (i = n; i > 0; i--) num[i + right] = num[i];
	for (i = n + right; i > n; i--) num[i - n] = num[i];
	for (i = 1; i < n; i++) cout << num[i]<<' ';
	cout << num[i] << endl;
	return 0;
}