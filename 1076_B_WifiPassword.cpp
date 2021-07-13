#include<iostream>
using namespace std;

void password(char a) {
	if (a == 'A') cout << 1;
	else if (a == 'B') cout << 2;
	else if (a == 'C') cout << 3;
	else if (a == 'D') cout << 4;
}

int main() {
	int N, i;
	char line[36];
	cin >> N;
	getchar();
	for (i = 0; i < N; i++) {
		cin.getline(line, 36);
		if (line[2] == 'T') password(line[0]);
		else if (line[6] == 'T') password(line[4]);
		else if (line[10] == 'T') password(line[8]);
		else if (line[14] == 'T') password(line[12]);
	}
	cout << endl;
	return 0;
}