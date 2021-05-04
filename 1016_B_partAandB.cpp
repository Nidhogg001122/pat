#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int A, B, Da, Db, Pa = 0, Pb = 0;
	int temp, count, i;
	cin >> A >> Da >> B >> Db;
	count = 0;
	while (A) {
		temp = A % 10;
		if (temp == Da) count++;
		A = A / 10;
	}
	for (i = 0; i < count; i++) Pa = Pa * 10 + Da;
	count = 0;
	while (B) {
		temp = B % 10;
		if (temp == Db) count++;
		B = B / 10;
	}
	for (i = 0; i < count; i++) Pb = Pb * 10 + Db;
	printf("%d\n", Pa + Pb);
	return 0;
}