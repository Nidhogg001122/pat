#include<map>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 首先，合格的前提必须编程分数不小于200，只需保存这部分学生成绩即可
* 然后再排序，输出时判断总分是否达到60；
*/

struct score {
	string id;
	int p, m, n, G;
};

bool cmp(score a, score b) {
	return a.G != b.G ? a.G > b.G:a.id < b.id;
}

int main() {
	vector<score> student;
	map<string, int> mp;	//存储学号对应成绩在vector中下标;
	int P, M, N, i, temp, count = 1;
	string stu;
	cin >> P >> M >> N;
	for (i = 0; i < P; i++) {
		cin >> stu >> temp;
		if (temp >= 200) {
			student.push_back(score{ stu,temp,-1,-1,-1 });
			mp.insert(make_pair(stu, count));
			count++;
		}
	}
	for (i = 0; i < M; i++) {
		cin >> stu >> temp;
		if (mp[stu]) {	//在map存储时从1开始，若之前编程分达到200.则会找到vector下标
			student[mp[stu] - 1].m = temp;
		}
	}
	for (i = 0; i < N; i++) {
		cin >> stu >> temp;
		if (mp[stu]) {
			student[mp[stu] - 1].n = temp;
			if (temp < student[mp[stu] - 1].m) student[mp[stu] - 1].G = (int)(temp * 0.6 + student[mp[stu] - 1].m * 0.4 + 0.5);
			else student[mp[stu] - 1].G = temp;
		}
	}
	sort(student.begin(), student.end(), cmp);
	for (vector<score>::iterator it = student.begin(); it != student.end(); it++) {
		if ((*it).G >= 60) cout << (*it).id << ' ' << (*it).p << ' ' << (*it).m << ' ' << (*it).n << ' ' << (*it).G << endl;
	}
	return 0;
}