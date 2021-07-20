#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> say(N + 1);
	for (int i = 1; i <= N; i++) cin >> say[i];	//记录每个人说的话；
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			vector<int> lie, temp(N + 1, 1);
			temp[i] = -1;
			temp[j] = -1;	
			//lie用来记录说谎的人，temp为此次循环中所有人身份，1人，-1狼，假设i与j为狼，循环求解
			for (int k = 1; k <= N; k++) {
				if (say[k] * temp[abs(say[k])] < 0) {
					//第k个人说的，和我们假设的不同，则认为他说谎
					lie.push_back(k);
				}
			}
			if (lie.size() == 2 && temp[lie[0]] + temp[lie[1]] == 0) {
				//因为狼人有两个且仅有一个在说谎，所以还有一个是人
				//如果此次刚好只找到两个说谎的，且在假设中一个是狼一个是人，则求解完成
				cout << i << ' ' << j << endl;
				return 0;
			}
		}
	}
	cout << "No Solution" << endl;
	return 0;
}