#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

const int maxn = 100000;

/*
* 对于一个问题，求无序序列中的K大数据，最常见的想法是，
* 将其排序，直接读出第K大的数
* 但此时的时间复杂度与所选排序算法有关，且并非完美
* 使用快速选择算法，可将其时间复杂度降至O(n);
*/

//回忆快排的核心，即随机选择一个数rand，使其左边的数均小于rand，右边的数均大于rand

int randPosition(int A[], int left, int right) {
	int randNum = round(1.0 * rand() / RAND_MAX * (right - left)) + left;	//随机选取一个数
	swap(A[randNum], A[left]);
	int temp = A[left];	//保存随机数，同时空出A[left]
	while (left < right) {
		while (left < right && A[right]>temp) right--;	//右边的数比选出来的数大，不变
		A[left] = A[right];	//右边的数比选出来的数小，换至左边
		while (left < right && A[left] < temp) left++;	//左边的数比选出来的数小，不变
		A[right] = A[left];	//左边的数比选出来的数大，换至右边
	}
	A[left] = temp;	//此时left=right，两者都可
	return left;
}

/*
* 快速选择算法求第K大的数
* 先使用上述算法求p=A[randNum],此时左边均小于它，右边均大于
* p就是A[left,right]中，第p-left+1大的数,设M=p-left+1
* 若K==M，则第K大的数为A[randNum]
* 若K<M,则第K大的数在p左边，递归求[left,randNum-1]
* 若K>M,则第K大的数在p右边，为第K-M大的数
*/

int quickCh(int A[], int left, int right, int K) {
	if (left == right) return left;
	int p = randPosition(A, left, right);
	int M = p - left + 1;
	if (K == M) return A[p];
	if (K < M) quickCh(A, left, p - 1, K);
	else quickCh(A, p + 1, right, K - M);
}

/*
* 快速选择算法的一个应用：
* 有一个不同整数构成的N元素集合，将其划分为两个子集
* 使两个子集的元素个数之差最小，且两个子集元素各自求和后的差最大；
* 显然，依据条件划分的子集，应当是排序后元素较大的一半，与较小的一半(奇数则元素数量相差1)
* 在使用快速选择算法解决此问题的时候，只需要去寻找第N/2大的元素
* 甚至不需要知道它是多少，在这个过程中会将集合最快的分为较大和较小两个部分
* 快速选择算法最坏的时间复杂度为O(n²),但在平均输入中都可达到O(n)
*/

int main() {
	srand((unsigned)time(NULL));
	int num[maxn] = { 0 };
	int n, result = 0, i = 0, temp = 0, sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		sum += num[i];
	}
	temp = quickCh(num, 0, n-1, n / 2);
	for (i = 0; i < n / 2; i++) result += num[i];
	printf("%d", sum - result - result);
}