#include<iostream>
#include<string>
using namespace std;

int main() {
	string broken, input;
	getline(cin, broken);	//���ڿ���û�л�������һ��Ϊ�գ�ʹ�ô�ͳ��ʽ��ȡ����
	cin >> input;
	
	bool up = (broken.find('+') == string::npos) ? false : true; //�ڻ������Ҳ���+Ϊfalse;

	int i;
	for (i = 0; i < input.length(); i++) {
		if (broken.find(toupper(input[i])) != string::npos) continue;	//�ڻ������ҵ��������
		if (isupper(input[i]) && up) continue;	//����Ϊ��д��+���ˣ������
		cout << input[i];
	}
	cout << endl;
	return 0;
}