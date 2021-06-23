#include<map>
#include<iostream>
#include<set>
using namespace std;

int people[10010];

int main() {
	int n, m, i;
	map<int, int>mp; //存储情侣
	set<int> s;	//存储单身狗，使用set可以避免重复插入
	cin >> n;
	int a, b;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		mp.insert(make_pair(a, b));	//建立情侣中一人对另一人的映射
		mp.insert(make_pair(b, a)); //建立双向映射
	}
	cin >> m;
	for (i = 0; i < m; i++) cin >> people[i];
	int single, temp, j, count = 0;
	for (i = 0; i < m; i++) {
		single = 1;
		if (mp.find(people[i]) != mp.end()) {	//在情侣中找到它
			single = 0;
			temp = mp[(people[i])];	//由映射关系找到它对应的另一半
		}
		if (single == 1) {
			s.insert(people[i]);	//在情侣中没找到，插入单身狗队列
			count++;
			continue;
		}
		else {
			for (j = 0; j < m; j++) {
				if (people[j] == temp) {
					single = 1;	//在人群中找到它的另一半
					break;
				}
			}
			if (single == 0) {
				s.insert(people[i]);
				count++;
			}
		}
	}
	cout << count << endl;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		if (it == s.begin()) printf("%05d", *it);
		else printf(" %05d", *it);
	}
	if (count != 0) printf("\n");
	return 0;
}