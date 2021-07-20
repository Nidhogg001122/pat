#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool prime(int a) {
	int sqr = sqrt(a);
	for (int i = 2; i <= sqr; i++) {
		if (a % i == 0) return false;
	}
	return true;
}

int main() {
	int N, K, i, j;
	cin >> N >> K;
	char num[1024];
	vector<int> result(K);
	for (i = 0; i < N; i++) cin >> num[i];
	int temp, count;
	for (i = 0; i < N; i++) {
		temp = 0;
		count = 0;
		for (j = i; j < i + K && j < N; j++) {
			temp *= 10;
			temp += num[j] - 48;
			count++;
		}
		if (count == K) {
			if (prime(temp)) {
				for (; i < j; i++) cout << num[i];
				cout << endl;
				return 0;
			}
		}
		else break;
	}
	cout << "404" << endl;
	return 0;
}