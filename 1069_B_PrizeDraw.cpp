#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, int>mp;
string name[1010];

int main() {
	int m, n, s;
	cin >> m >> n >> s;
	int i;
	for (i = 0; i < m; i++) cin >> name[i];
	if (m < s) printf("Keep going...\n");
	else {
		for (i = s-1; i < m; i += n) {
			while (mp.find(name[i]) != mp.end()) i += 1;
			if(i<m) {
				cout << name[i] << endl;
				mp.insert(make_pair<string,int>((string)name[i],1));
			}
		}
	}
	return 0;
}