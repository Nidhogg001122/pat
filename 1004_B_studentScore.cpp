#include <iostream>
#include <cstring>

//���ⲻ�ѣ�����PAT��scanf����ֵ��Ҫ���ϸ񣬿���ʹ��cin��cout

using namespace std;
struct stuData {
	string name;
	string id;
	int score;
}student[1010];

int main()
{
	int n, i, min = 0, max = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> student[i].name >> student[i].id >> student[i].score;
	}
	for (i = 0; i < n; i++) {
		if (student[max].score < student[i].score) max = i;
		if (student[min].score > student[i].score) min = i;
	}
	cout << student[max].name << " " << student[max].id << endl;
	cout << student[min].name << " " << student[min].id << endl;
	return 0;
}
