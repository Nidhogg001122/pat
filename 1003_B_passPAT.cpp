#include<cstdio>
#include<cstring>
using namespace std;

/*
* ������Ŀ����
*1 �ַ����б������ P�� A�� T�������ַ��������԰��������ַ���
*2 �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
*3 ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a�� b�� c �������ǿ��ַ�����
*  �����ǽ�����ĸ A ��ɵ��ַ�����
* ����һָ���ַ�������PAT���ߣ���������������Ӧ�úϲ����
* ��PǰA����Ŀ����P��T��A����Ŀ����T��A����Ŀ
* xPATx����ȷ�ģ�x*1=x
* aPbTc����ȷ�ģ�a*b=c
* aPbATca,�̺���a*(b+1)=(c+a)
*/

int main() {
	int num, i = 0, length = 0, j = 0;
	int result[11] = { 0 };
	char c, line[101];
	scanf("%d", &num);
	scanf("%c", &c);	//�Ե��س�����
	while (i < num) {
		int beforeP = 0, betweenPT = 0, afterT = 0, status = 0;	//��¼����λ��A����Ŀ
		int p = 0, a = 0, t = 0;	//��¼�����ַ�������
		scanf("%c", &c);
		while (c != '\n') {
			if (c == 'P') {
				status = 1;		//��ʼ����P~T
				p++;
			}
			else if (c == 'A') a++;
			else if (c == 'T') {
				status = 2;		//��ʼ����T֮��
				t++;
			}
			else result[i] = 1;	//���������ַ���������
			switch (status) {
			case 0:beforeP++; break;
			case 1:if (c == 'A') betweenPT++; break;	//��ȥP
			case 2:if (c == 'A') afterT++; break;	//��ȥT
			}
			scanf("%c", &c);
		}
		if (!result[i] && p == 1 && t == 1 && a != 0 && (beforeP * betweenPT == afterT)) result[i] = 2;
		i++;
	}
	for (i = 0; i < num; i++) {
		if (result[i] == 2) printf("YES\n");
		else printf("NO\n");
	}
}