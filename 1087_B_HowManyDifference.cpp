#include<iostream>
using namespace std;

int result[100000] = { 0 };	//��˵NС�ڵ���10000�����õ��Ĳ�ͬ��ֵ�ᳬ��������Χ������һЩ��

int main() {
	int N;
	cin >> N;
	int count = 0, temp;
	for (int i = 1; i <= N; i++) {
		temp = i / 2 + i / 3 + i / 5;
		if (result[temp] == 0) {
			count++;
			result[temp]++;
		}
	}
	cout << count << endl;
	return 0;
}