#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char input[128], output[128];
	int keyboard[128] = { 0 };
	cin >> input >> output;
	int len_1 = strlen(input), len_2 = strlen(output), i;
	for (i = 0; i < len_1; i++) {
		if (input[i] >= 97 && input[i] <= 122) input[i] -= 32;
	}
	for (i = 0; i < len_2; i++) {
		if (output[i] >= 97 && output[i] <= 122) output[i] -= 32;
	}
	for (i = 0; i < len_2; i++) {
		if (keyboard[output[i]] == 0) {
			keyboard[output[i]] = 1;
		}
	}
	for (i = 0; i < len_1; i++) {
		if (keyboard[input[i]] == 0) {
			printf("%c", input[i]);
			keyboard[input[i]] = -1;
		}
	}
	printf("\n");
	return 0;
}