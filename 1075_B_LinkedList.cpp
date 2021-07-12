#include<iostream>
#include<cstdio>
using namespace std;

struct {
	int data;
	int next;
}list[100010];


int main() {
	int first, N, K;
	cin >> first >> N >> K;
	int i, address;
	for (i = 0; i < N; i++) {
		cin >> address;
		cin >> list[address].data >> list[address].next;
	}
	int next = 1;
	for (address = first; address != -1;) {
		if (list[address].data < 0) {
			if (next != 1) printf("%05d\n", address);
			else next = 0;
			printf("%05d %d ", address, list[address].data);
		}
		address = list[address].next;
	}
	for (address = first; address != -1;) {
		if (list[address].data >= 0 && list[address].data <= K) {
			if (next != 1) printf("%05d\n", address);
			else next = 0;
			printf("%05d %d ", address, list[address].data);
		}
		address = list[address].next;
	}
	for (address = first; address != -1;) {
		if (list[address].data > K) {
			if (next != 1) printf("%05d\n", address);
			else next = 0;
			printf("%05d %d ", address, list[address].data);
		}
		address = list[address].next;
	}
	cout << -1 << endl;
	return 0;
}