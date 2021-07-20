#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> say(N + 1);
	for (int i = 1; i <= N; i++) cin >> say[i];	//��¼ÿ����˵�Ļ���
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			vector<int> lie, temp(N + 1, 1);
			temp[i] = -1;
			temp[j] = -1;	
			//lie������¼˵�ѵ��ˣ�tempΪ�˴�ѭ������������ݣ�1�ˣ�-1�ǣ�����i��jΪ�ǣ�ѭ�����
			for (int k = 1; k <= N; k++) {
				if (say[k] * temp[abs(say[k])] < 0) {
					//��k����˵�ģ������Ǽ���Ĳ�ͬ������Ϊ��˵��
					lie.push_back(k);
				}
			}
			if (lie.size() == 2 && temp[lie[0]] + temp[lie[1]] == 0) {
				//��Ϊ�����������ҽ���һ����˵�ѣ����Ի���һ������
				//����˴θպ�ֻ�ҵ�����˵�ѵģ����ڼ�����һ������һ�����ˣ���������
				cout << i << ' ' << j << endl;
				return 0;
			}
		}
	}
	cout << "No Solution" << endl;
	return 0;
}