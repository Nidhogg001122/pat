#include<cstdio>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;

/*
* 选择排序：
* 用i从0~n-1遍历整个序列。将最小的元素与目前i所在元素交换，i++
* 进行n次操作，其时间复杂度为O(n²);
*/

void selectSort(int a[],int length) {
	int i = 0, j = 0, temp = 0, k = 0;
	for (; i < length - 1; i++) {
		k = i;
		for (j = i + 1; j < length; j++) {
			if (a[k] > a[j]) {
				k = j;
			}
		}
		temp = a[k];
		a[k] = a[i];
		a[i] = temp;
	}
}

/*
* 插入排序：
* 在序列中，将第i个元素插入到0~i中的某个位置，使0~i依旧有序，i++；
* 最坏为n²,最好为n,时间复杂度为O(n²);
*/

void insertSort(int a[], int length) {
	int i = 0, temp = 0, j = 0;
	for (i = 1; i < length ; i++) {
		temp = a[i];
		j = i;
		while (j > 0 && temp < a[j - 1]) {
			a[j] = a[j - 1];	//使比a[j]大的元素后移，达到插入有序的效果
			j--;
		}
		a[j] = temp;
	}
}

/*
* 在two pointers中，提及一个将两个递增序列A，B合并成一个有序序列C的方法；
* 即分别从A，B起始位置开始比较，将较小的加入C中，相应标记点后移；
*/

int merge(int a[], int b[], int c[], int length1, int length2) {
	int i = 0, j = 0,current=0;
	while (i < length1 && j < length2) {
		if (a[i] <= b[j]) c[current++] = a[i++];
		else c[current++] = b[j++];
	}
	while (i < length1) c[current++] = a[i++];
	while (j < length2) c[current++] = b[j++];
	return current;
}

/*
* 归并排序/2-路归并排序：
* 2-路归并排序即将序列分为n/2组，组内单独排序；合并成有序序列后
* ，得到n/4组，再排序合并......一直到最终使序列有序
* 例如{1，3，4，2，5}
* 分组 {1，3}，{4，2}，{5}
* 排序 {1，3}，{2，4}，{5}
* 分组 {1，3，2，4}，{5}
* 排序 {1，2，3，4}，{5}
* 合并 {1，2，3，4，5}
*/

//使two pointers中的合并函数能够用于排序,不传入两个数组，而是将一个数组看成两部分
void Merge(int a[],int L1,int R1,int L2,int R2) {
	int temp[64],current=0;
	int i = L1, j = L2;
	while (i <= R1 && j <= R2) {
		if (a[i] <= a[j]) temp[current++] = a[i++];
		else temp[current++] = a[j++];
	}
	while (i <= R1) temp[current++] = a[i++];
	while (j <= R1) temp[current++] = a[j++];
	for (i = 0; i < current; i++) {
		a[L1+i] = temp[i];
	}
}

//归并排序递归实现

void mergeSort(int a[], int L, int R) {
	if (L < R) {
		int mid = (L + R) / 2;		//取中点将分组
		mergeSort(a, L, mid);		//[L~mid]归并
		mergeSort(a,mid + 1, R);	//[mid+1,R]归并
		Merge(a, L, mid, mid + 1, R);	//合并
	}
}

/*
* 其非递归实现，在开始时选择step=2,将step内的元素排序(step/2,分为左右两组)，
* 将step右移，重复此过程，注意末尾处,若小于step/2,不合并
* 然后将step*2,重复所有过程，直至最终step/2>n;
*/

void mergeSortCircle(int a[],int length) {
	for (int step = 2; step / 2 < length; step *= 2) {
		for (int i = 0; i < length; i += step) {	//对每一组操作
			int mid = i + step / 2 ;		//[i+(i+step)]/2
			if (mid  < length) {	//右半边有数据
				Merge(a, i, mid - 1, mid, min(i + step-1, length-1));
			}			//在时间允许时 sort(a+i,a+min(i+step-1,length-1))
		}
	}
}


/*
* 快速排列：
* 主要内容就是选则元素，操作使其左边均小于它，右边均大于它
* 快排的思想还是two pointers
* 1.temp=a[1],L=1,R=n
* 2.若a[R]大于temp,R右移，直到a[R]小于temp, a[L]=a[R];
* 3.若a[L]小于temp,L左移，直到a[L]大于temp, a[R]=a[L];
* 4.重复2，3直到L==R，此处放入temp；
*/

int quike(int a[],int L,int R) {
	int i = L, j = R;
	int p = rand()%(R-L+1)+L;
	swap(a[p], a[L]);
	int temp = a[L];
	while (i < j) {
		while (i<j && a[j] >= temp) j--;
		a[i] = a[j];
		while (i < j && a[i] <= temp) i++;
		a[j] = a[i];
	}
	a[i] = temp;
	return i;
}
/*
* 此时若元素是较有序时，时间复杂度将达到O(n²)，若随机选取，最坏依然是O(n²)，但平均为O(nlogn)
* 生成随机数：
* srand((unsigned)time(NULL));以时间为种子计算
* rand();产生0~RAND_MAX随机数
* 只需rand()%(b-a+1)+a即可产生[a,b]中随机数，rand()%(b-a+1)产生[0,b-a],再加a就行了
*/

//，对一个元素快排，再不断递归调用对其左右两边快排，直到长度为1
void quikeSort(int a[], int L, int R) {
	if (L < R) {
		int current = quike(a, L, R);
		quikeSort(a, L, current - 1);
		quikeSort(a, current + 1, R);
	}
}

int main() {
	srand((unsigned)time(NULL));
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int b[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int c[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int d[10] = { 10,9,8,7,6,5,4,3,2,1 };
	selectSort(a, 10);
	insertSort(b, 10);
	mergeSort(c, 0, 9);
	quikeSort(d, 0, 9);
	for (int i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", c[i]);
	}
	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", d[i]);
	}
}