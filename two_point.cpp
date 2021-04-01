#include<cstdio>
#include<algorithm>
using namespace std;

/*
* 对于顺序排列的数据，若想查找其中某个元素，最常见的方法是遍历整个数组，若查找到
* 值相同的元素，返回其下标，时间复杂度为O(n);
* 
* 二分查找用于顺序排列元素的查找；对于[L,R]区间内元素，每次将位置mid=(L+R)/2的元素
* 与需查找的x进行比较
* 1. array[mid]==x,找到元素，返回mid;
* 2. array[mid]>x,x在[L,mid-1]内，使R=mid-1;
* 3. array[mid]<x,x在[mid+1,R]内，使L=mid+1;
* 若最终,L>R,则x不在元素中；
* 时间复杂度为O(logn)；
* 如果在数据较大的情况下，计算L+R溢出，可以使用mid=L+(R-L)/2;
* 当数组元素从大到小排列时，只需改变比较条件即可；
*/

int binarySearch(int array[],int x,int n) {
	int mid = 0;
	int L = 0, R = n;		//求元素个数并给R赋初值；
	while (L <= R) {
		mid = (L + R) / 2;
		if (array[mid] == x) return mid;		//找到元素
		else if (array[mid] > x) R = mid - 1;	//改变R；
		else if (array[mid] < x) L = mid + 1;	//改变L；
	}
	return -1;		//未找到，返回-1；
}

/*
* 对于上一个版本，数组中元素有序排列且需要不重复，若元素可重复出现时
* 需要对L，R的处理做出改变
* 如将求出序列中，第一个大于等于x的元素位置s，和第一个大于x的元素位置e
* 若两者相等，则x不在其中，若不等，则[s,e)为x存在区间；
* 例如{1，2，3，3，3，5}，查找x=3,有s=2,e=5,故[2,5)
* 查找x=4， s=e=5，即x不在其中；
*/

int findStart(int array[], int x, int n) {
	int mid = 0;
	int L = 0, R = n;
	while (L < R) {		//L=R即找到x所在第一个位置，或者没有x时假想的它应该在的位置
		mid = (L + R) / 2;
		if (array[mid] >= x) R = mid;	//此时即使等于x也不能停止搜索，因为数据是重复的，目的是找到第一个,所以R=mid而非mid+1
		else L = mid + 1;
	}
	return L;	//L与R其实此时都一样
}

int findEnd(int array[], int x, int n) {
	int mid = 0;
	int L = 0, R = n;
	while (L < R) {		//L=R即找到大于第一个位置，或者没有时假想的它应该在的位置
		mid = (L + R) / 2;
		if (array[mid] <= x) L = mid+1;	//此时即使等于x也不能停止搜索，所求为大于
		else R = mid;
	}
	return L;	//L与R其实此时都一样
}

//上面两个函数解决了大部分问题，但缺少了最大边界条件，
//R理论上只能到元素数量n，若查找的元素刚好能到最后一个元素，则会发生错误

/*
* 二分查找不仅仅只用于排列元素的搜索，还可以用以解决特殊的问题
* 例如：查找根号2（2½）的值；
* 对于f(x)=x²,在[1,2]内f(x)随x单增，使得二分查找得以实现；
* 对于精度eps=le-5,即10的-5次方，当R-L>eps时：
* f(mid)>2时，R=mid;
* f(mid)<2时，L=mid;
*/

double newSqrt(double eps) {
	double L = 1, R = 2, mid = 0;
	while (R - L > eps) {
		mid = (L + R) / 2;
		if (mid * mid > 2) R = mid;
		else L = mid;
	}
	return mid;
}

/*
* 分木棒问题，对于给定长度的n根木棒，分为长度相同的K根完整木棍，求木棍最大长度；
* 3根木棒：10，24，15，设K=7，最大长度6，第一个1，第二根4，第三根2；
* 所求为分木棒数num>=K时最大长度，可利用二分查找,不妨查找第一个num<K时更简易；
*/


int cutWood(int a[],int n, int K) {
	int i=0,num = 0, L = 0, R = a[0], mid = 0;	//R为所有木棒最长长度
	while (L<R) {
		mid = (L + R) / 2;
		for (num =0, i = 0; i < n; i++) {
			int j = a[i] / mid;
			num += j;
		}
		if (num >= K) L = mid+1;		//此时求出的是第一个大于K时的数据，最后返回的结果应当减一；
		else R = mid;
	}
	return L-1;
}

bool cmp(int a,int b) {
	return a > b;
}

int main() {
	int n, a[100], K;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &K);
	sort(a, a + n, cmp);
	printf("\n%d", cutWood(a, n, K));
}
