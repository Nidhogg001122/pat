#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

struct data {
	char name[8];
	int num;
	vector<int>things;
}stu[1010];

int main() {
	int m, n;
	cin >> m >> n;
	vector<int>illegal;
	int i, j, temp;
	for (i = 0; i < n; i++) {
		cin >> temp;
		illegal.push_back(temp);
	}
	for (i = 0; i < m; i++) {
		cin >> stu[i].name >> stu[i].num;
		for (j = 0; j < stu[i].num; j++) {
			cin >> temp;
			stu[i].things.push_back(temp);
		}
	}
	int judge, stuNum = 0, thingNum = 0;
	vector<int>::iterator iter,check;
	for (i = 0; i < m; i++) {
		judge = 0;
		for (iter = stu[i].things.begin(); iter != stu[i].things.end(); iter++) {
			check = find(illegal.begin(), illegal.end(), *iter);
			if (check != illegal.end()) {
				thingNum++;
				if (judge == 0) {
					cout << stu[i].name << ":";
					judge = 1;
				}
				printf(" %04d", *check);
			}
		}
		if (judge == 1) {
			cout << endl;
			stuNum++;
		}
	}
	cout << stuNum << ' ' << thingNum << endl;
	return 0;
}