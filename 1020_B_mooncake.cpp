#include<cstdio>
#include<algorithm>
using namespace std;

struct data {
	double num;		//库存
	double total;	//总售价
	double price;	//单价
}mooncake[1600];		//定义结构数组存储

bool cmp(struct data a, struct data b) {
	return a.price > b.price;		//以单价从高到低排序
}

int main() {
	double result=0, need;
	int kind;
	scanf("%d%lf", &kind, &need);
	int i = 0;
	for (i = 0; i < kind; i++) {
		scanf("%lf", &mooncake[i].num);
	}
	for (i = 0; i < kind; i++) {
		scanf("%lf", &mooncake[i].total);
	}
	for (i = 0; i < kind; i++) {
		mooncake[i].price = mooncake[i].total / mooncake[i].num;
	}
	//输入信息存储
	sort(mooncake, mooncake + kind, cmp);	//排序

	for (i = 0; i < kind; i++) {
		if (need <= mooncake[i].num) {
			result += need * mooncake[i].price;		//如果需求小于此种月饼数目,仅卖出需求数，退出
			break;
		}
		else {
			result += mooncake[i].total;		//如果需求大于此种月饼数目,卖出所有此月饼
			need -= mooncake[i].num;			//需求减少
		}
	}

	printf("%.2lf", result);
}