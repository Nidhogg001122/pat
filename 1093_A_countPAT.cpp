#include<cstdio>
#include<cstring>
using namespace std;

/*
* 对于正常思路，应该是遍历整个句子，对P，A，T各个位置进行统计
* 但在数据较大的情况下，此方法可能会超时；
* 对于每个A，组成PAT的数量为，其左边的P数目乘以右边的A数目
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
	// 使用gets和gets_s通不过编译，没办法只能一个一个读取
	// gets_s(read, max - 1);	//读入字符串，gets函数因为无限读取被标准删除
	int length = strlen(read);
	int numOfP[max] = { 0 };
	for (i = 0; i < length; i++) {	//遍历统计每个字符左边的P数
		if (i > 0) numOfP[i] = numOfP[i - 1];
		if (read[i] == 'P') numOfP[i]++;
	}
	int numOfT = 0;
	int result = 0;
	for (i = length - 1; i >= 0; i--) {		//遍历求解
		if (read[i] == 'T') numOfT++;		//统计字符T出现次数
		else if (read[i] == 'A') {		//当读到A时，求PAT数，按题目要求取模
			result = (result + numOfP[i] * numOfT) % mod;
		}
	}
	printf("%d", result);
	return 0;
}