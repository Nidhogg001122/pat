#include<iostream>
using namespace std;

int result[10010] = { 0 };

int main() {
	int n, i, difference;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> difference;
		difference = difference - i;
		if (difference < 0) difference = -difference;
		result[difference]++;
	}
	for (i = 10009; i >= 0; i--) {
		if (result[i] > 1) cout << i << ' ' << result[i] << endl;
	}
	return 0;
}