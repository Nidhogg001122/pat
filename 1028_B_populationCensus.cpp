#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct data {
	char name[6];
	int  year, month, day;
}people[100010];

bool cmp(struct data a, struct data b) {
	if (a.year < b.year) return true;
	else if (a.year > b.year) return false;
	else {
		if (a.month < b.month) return true;
		else if (a.month > b.month) return false;
		else {
			if (a.day < b.day) return true;
			else return false;
		}
	}
}

int main() {
	int num, i, count = 0, y, m, d;
	char tempname[8];
	cin >> num;
	for (i = 0; i < num; i++) {
		scanf("%s %d/%d/%d", &tempname, &y,&m,&d);
		if ((y == 1814 && m == 9 && d < 6) || (y == 2014 && m == 9 && d > 6) || (y < 1814) || (y > 2014) || (y == 1814 && m < 9) || (y == 2014 && m > 9)) continue;
		else {
			strcpy(people[count].name, tempname);
			people[count].year = y;
			people[count].month = m;
			people[count++].day = d;
		}
	}
	if (count == 0) {	//虽然保证输入数据，但输入的生日不一定有合理的，可能全被过滤了
		printf("0\n");
		return 0;
	}
	sort(people, people + count, cmp);
	printf("%d %s %s\n", count,people[0].name,people[count-1].name);
	return 0;
}