#include<iostream>
using namespace std;

bool automorph(int K, int N) {
	int temp = K * K * N;
	bool judge = false;
	while (K) {
		if (K % 10 == temp % 10) {
			judge = true;
			K /= 10;
			temp /= 10;
		}
		else {
			judge = false;
			break;
		}
	}
	return judge;
}

int main() {
	int M;
	cin >> M;
	int num, i, j;
	bool judge;
	for (i = 0; i < M; i++) {
		cin >> num;
		judge = false;
		for (j = 1; j < 10; j++) {
			if (automorph(num, j)) {
				judge = true;
				break;
			}
		}
		if (judge) 	cout << j << ' ' << num * num * j << endl;
		else cout << "No" << endl;
	}
	return 0;
}