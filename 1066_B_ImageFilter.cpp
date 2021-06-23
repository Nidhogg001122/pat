#include<iostream>
using namespace std;

int image[500][500];

int main() {
	int m, n, low, high, back;
	cin >> m >> n >> low >> high >> back;
	int i, j, temp;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cin >> temp;
			if (temp >= low && temp <= high) image[i][j] = back;
			else image[i][j] = temp;
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%03d", image[i][j]);
			if (j < n - 1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}