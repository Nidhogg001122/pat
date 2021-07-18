#include<map>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
* ���ȣ��ϸ��ǰ������̷�����С��200��ֻ�豣���ⲿ��ѧ���ɼ�����
* Ȼ�����������ʱ�ж��ܷ��Ƿ�ﵽ60��
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
	map<string, int> mp;	//�洢ѧ�Ŷ�Ӧ�ɼ���vector���±�;
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
		if (mp[stu]) {	//��map�洢ʱ��1��ʼ����֮ǰ��̷ִﵽ200.����ҵ�vector�±�
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