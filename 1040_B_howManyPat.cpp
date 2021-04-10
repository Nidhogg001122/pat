#include<cstdio>
#include<cstring>
using namespace std;

/*
* ��������˼·��Ӧ���Ǳ����������ӣ���P��A��T����λ�ý���ͳ��
* �������ݽϴ������£��˷������ܻᳬʱ��
* ����ÿ��A�����PAT������Ϊ������ߵ�P��Ŀ�����ұߵ�A��Ŀ
*/

const int max=100000;
const int mod = 1000000007;

int main() {
	char read[max];
	char c;
	int i = 0;
	scanf("%c", &c);
	while (c != '\n') {
		read[i] = c;
		scanf("%c",&c);
		i++;
	}
	read[i] = '\0';
	// ʹ��gets��gets_sͨ�������룬û�취ֻ��һ��һ����ȡ
	// gets_s(read, max - 1);	//�����ַ�����gets������Ϊ���޶�ȡ����׼ɾ��
	int length = strlen(read);
	int numOfP[max] = { 0 };
	for (i = 0; i < length; i++) {	//����ͳ��ÿ���ַ���ߵ�P��
		if (i > 0) numOfP[i] = numOfP[i - 1];
		if (read[i] == 'P') numOfP[i]++;
	}
	int numOfT = 0;
	int result = 0;
	for (i = length - 1; i >= 0; i--) {		//�������
		if (read[i] == 'T') numOfT++;		//ͳ���ַ�T���ִ���
		else if (read[i] == 'A') {		//������Aʱ����PAT��������ĿҪ��ȡģ
			result = (result + numOfP[i] * numOfT) % mod;
		}
	}
	printf("%d", result);
	return 0;
}