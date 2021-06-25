#include <iostream>
#include<string>
using namespace std;

int main() {
	string password, input;
	int n, count = 0;
	cin >> password >> n;
	getchar();
	while (1) {
		getline(cin, input);
		if (input == "#") break;
		count++;
		if (count <= n && input == password) {
			cout << "Welcome in" << endl;
			return 0;
		}
		else if (count <= n && input != password) {
			cout << "Wrong password: " << input << endl;
			if (count == n) {
				cout << "Account locked" << endl;
				return 0;
			}
		}
	}
	return 0;
}