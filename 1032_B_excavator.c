#include <stdio.h>
int main()
{
	int All_score[100000]={0};
	int school=0,score=0,num=0,i=0;
	scanf("%d",&num);
	i=num;
	while(i)
	{
		scanf("%d %d",&school,&score);
		All_score[school]+=score;
		i--;
	}
	int id=0,max=0;
	for(i=1;i<=num;i++)
	{
		if(max<All_score[i])
		{
			max=All_score[i];
			id=i;
		}
	}
	printf("%d %d",id,max);
	return 0;
}