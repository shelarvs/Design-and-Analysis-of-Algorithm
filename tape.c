#include<stdio.h>
#include<string.h>

typedef struct p
{
	char name[100];
	int l;
}p;

p pro[20];
int t[50][50];

void Bu(int n)
{
	int i,j,t,k;
	char temp[100];
	for(i = 0 ; i < n-1 ; i++)
	{
		for(j = 0 ; j < n-i-1 ; j++)
		{
			if(pro[j].l>pro[j+1].l)
			{
				t = pro[j].l;
				strcpy(temp, pro[j].name);
				pro[j].l = pro[j+1].l;
				strcpy(pro[j].name, pro[j+1].name);
				pro[j+1].l = t;
				strcpy(pro[j+1].name, temp);
			}
		}
		
	}
	
}

void store(int n, int m)
{
	int i,j,k;
	j=0;
	k=0;
	for(i = 0 ; i < n ; i++)
	{
		t[j][k] = pro[i].l;
		j = (j+1)%m;
		if(j == 0)
			k++;
	}
}

int main()
{
	int n,i,m,j=0,k=0;
	printf("\n\tEnter the number of prog:");
	scanf("%d", &n);
	printf("\n\tEnter the name and length of prog:");
	for(i = 0 ; i < n ; i++)
	{
		printf("\n\t\tEnter the name of prog %d:",i+1);
		scanf("%s",pro[i].name);
		printf("\n\t\tEnter the length of prog %d:",i+1);
		scanf("%d",&pro[i].l);
	}
	printf("\n\tEnter the number of tapes:");
	scanf("%d", &m);
	Bu(n);
	printf("\n\tSorted programs are:");
	for(i = 0 ; i < n ; i++)
	{
		printf("\n\tProg %s Length %d", pro[i].name, pro[i].l);
	}
	store(n,m);
	printf("\n\tThe Stored Programs are:\n");
	for(i = 0 ; i < m ; i++)
		printf("\tTape %d",i+1);
	printf("\n");
	for(i = 0 ; i < n ; i++)
	{
		printf("\t%d",t[j][k]);
		j = (j+1)%m;
		if(j == 0)
		{
			k++;
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}
