#include<map>
#include<iostream>
#include<set>
using namespace std;

int people[10010];

int main() {
	int n, m, i;
	map<int, int>mp; //�洢����
	set<int> s;	//�洢������ʹ��set���Ա����ظ�����
	cin >> n;
	int a, b;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		mp.insert(make_pair(a, b));	//����������һ�˶���һ�˵�ӳ��
		mp.insert(make_pair(b, a)); //����˫��ӳ��
	}
	cin >> m;
	for (i = 0; i < m; i++) cin >> people[i];
	int single, temp, j, count = 0;
	for (i = 0; i < m; i++) {
		single = 1;
		if (mp.find(people[i]) != mp.end()) {	//���������ҵ���
			single = 0;
			temp = mp[(people[i])];	//��ӳ���ϵ�ҵ�����Ӧ����һ��
		}
		if (single == 1) {
			s.insert(people[i]);	//��������û�ҵ������뵥������
			count++;
			continue;
		}
		else {
			for (j = 0; j < m; j++) {
				if (people[j] == temp) {
					single = 1;	//����Ⱥ���ҵ�������һ��
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