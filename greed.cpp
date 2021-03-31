#include<cstdio>
#include<algorithm>
using namespace std;

/*
* 区间贪心：
* 例如开区间不相交问题：对于给定的多个开区间，找出最多有几个不相交；（1，3），（2，4），（3，5）
* 有两个（1，3），（3，5）
* 
* 简单考虑，若两个区间有包含关系，应当选择较小的区间，以留出更多空间选取其他区间；
* 将所有区间按左端点从大到小排列，左端点相同则右端点小的优先如：
*			L1_________R1
*		L2_______R2
*	L3______R3
*	L4_________L4
* ......
* 对于第一个，若将R2右端部分去掉，则回到简单情况，必选1，而后循环寻找R小于等于L1的区间，
* 又因为左端相同右端从小到大，必然可以顺序选出被包含的较小的区间
* 
* 当然，也可将左端点从小到大排列
*/

struct data {
	int left,right;		//定义区间结构，具有左右端点
}space[128];

bool cmp(struct data a, struct data b) {
	if (a.left == b.left) return a.right<b.right;
	else return a.left>b.left;
}
int main() {
	int n = 0,num=0;
	scanf("%d", &n);
	int result[128] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &space[i].left, &space[i].right);
	}
	//读入区间数据

	sort(space, space + n, cmp);
	result[0] = 1;
	num = 1;
	int Left = space[0].left;	//取第一个区间

	for (int i = 1; i < n; i++) {
		if (space[i].right <= Left) {
			Left = space[i].left;
			result[i] = 1;
			num++;
		}
	}

	printf("\n%d\n", num);
	for (int i = 0; i < n; i++) {
		if (result[i]) printf("(%d,%d)\n", space[i].left, space[i].right);
	}
}