#include<cstdio>
using namespace std;

/*
* two pointers与其说是一种算法，更像是一种思想
* 在数组或链表等结构的遍历中，往往使用单个标记或指针进行操作
* two pointers如名字一样，使用两个标记或指针进行操作，为某些特定问题提供化简
*/


/*
例如，对于正整数递增序列和一个正整数M，找出序列中a+b=M的所有组合
常规做法是双重循环，遍历所有数据组合
*/

void normal(int a[],int M,int length) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (a[i] + a[j] == M) printf("%d,%d\n", a[i], a[j]);
		}
	}
}

/*
* 但是在双重循环下，时间复杂度为O(n²)，在数据较大的情况下是不可接受的
* 当我们创建两个标记，i=0，j=length-1时，a[i]+a[j]将有三种变化：
*  在严格递增序列中，使i右移，j左移，直到i>=j结束；
* 1.a[i]+a[j]==M,此时可知a[i]+a[j-1]<M，且a[i+1]+a[j]>M，所以，应该在[a+1,j-1]中
* 寻找，将i+1,j-1;
* 2.a[i]+a[j]<M,此时a[i]+a[j-1]<M,再将j左移是没有必要的，应该在[a+1,j]中寻找，
* 将i+1;
* 3.a[i]+a[j]>M,此时a[i+1]+a[j]>M,再将i右移是没有必要的，应该在[a,j-1]中寻找，
* 将j-1;
*/

void two(int a[], int M, int length) {
	int i = 0, j = length - 1;
	while (i < j) {
		if (a[i] + a[j] == M) {
			printf("%d,%d\n",a[i], a[j]);
			i++;
			j--;
		}
		else if (a[i] + a[j] < M) i++;
		else if (a[i] + a[j] > M) j--;
	}
}

//此时的时间复杂度仅为O(n)，在数据较大时提高了效率；

/*
* 另一个例子是序列归并问题，即已知两个递增序列A与B，将其合并成有序序列C
* 令i为A中第一个元素，j为B中第一个元素，current表示C中目前存放数量
* 1.A[i]==B[j],将任意一个放入C中，current+1；
* 2.A[i]<B[j],将A[i]放入C中，current+1；
* 3.A[i]>B[j],将B[j]放入C中，current+1；
*/

int insert(int a[], int b[], int c[],int length1,int length2) {
	int i = 0, j = 0, current = 0;
	
	while (i < length1 && j < length2) {
		if (a[i] == b[j]) {
			c[current] = a[i];
			i++;
			current++;
		}
		else if (a[i] < b[j]) {
			c[current] = a[i];
			i++;
			current++;
		}
		else if (a[i] > b[j]) {
			c[current] = b[j];
			j++;
			current++;
		}
	}
	while (i < length1) c[current++] = a[i++];
	while (j < length2) c[current++] = b[j++];
	return current;
}

int main() {
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int a[3] = { 1,3,5 }, b[3] = { 2,4,6 },c[64];
	int M = 7,current=0;
	//two(array, M, 10);
	current = insert(a, b, c, 3, 3);
	for (int i = 0; i < current; i++) printf("%d ", c[i]);
}