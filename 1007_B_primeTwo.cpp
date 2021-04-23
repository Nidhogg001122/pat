#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

bool prime(int num) {
	int sqr = (int)sqrt(num * 1.0);
	for (int i = 2; i <= sqr; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main() {
	int num, i, j, front, later, current;
	cin >> num;
	int count = 0;
	front = 2;
	for (i = 3; i <= num; i++) {
		if (prime(i)) {
			current = i;
			if ((current - front) == 2) count++;
			front = current;
		}
	}
	cout << count << endl;
	return 0;
}