#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

char A[1000010], B[1000010];

int main() {
	cin.getline(A, 1000010);
	cin.getline(B, 1000010);
	int ascii[128] = { 0 };
	int lengthA = strlen(A), lengthB = strlen(B);
	for (int i = 0; i < lengthA; i++) {
		if (ascii[A[i]] == 0) {
			cout << A[i];
			ascii[A[i]] = 1;
		}
	}
	for (int i = 0; i < lengthB; i++) {
		if (ascii[B[i]] == 0) {
			cout << B[i];
			ascii[B[i]] = 1;
		}
	}
	cout << endl;
	return 0;
}