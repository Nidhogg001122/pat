//���κ�һ�������� n���������ż������ô��������һ�룻���������������ô�� (3n+1) ����һ�롣
//���ڸ���һϵ�д���֤�����֣�����ֻ��Ҫ��֤���еļ����ؼ������Ϳ��Բ������ظ���֤���µ����֡�
//�����������ҳ���Щ�ؼ����֣������Ӵ�С��˳��������ǡ�

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int num[100], result[100] = { 0 }, printTxt[100];

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int i, j, n, temp;
	cin >> n;
	for (i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n, cmp);	//���������ݴӴ�С���򣬱������
	for (i = 0; i < n; i++) {
		temp = num[i];
		while (temp != 1)
		{
			if (temp % 2)
			{
				temp = (3 * temp + 1) / 2;
				for (j = 0; j < n; j++) {
					if (temp == num[j]) {
						result[j] = 1;	//�����ɱ����������ң����ǹؼ���
						break;
					}
				}
			}
			else
			{
				temp = temp / 2;
				for (j = 0; j < n; j++) {
					if (temp == num[j]) {
						result[j] = 1;	//�����ɱ����������ң����ǹؼ���
						break;
					}
				}
			}
		}
	}
	for (i = 0, j = 0; i < n; i++) {
		if (result[i] == 0) printTxt[j++] = num[i];
	}
	for (i = 0; i < j - 1; i++) {
		cout << printTxt[i] << " ";
	}
	cout << printTxt[i] << endl;
	return 0;	//����pat�� ����Ҫ�󣬷���ֵ������0
}