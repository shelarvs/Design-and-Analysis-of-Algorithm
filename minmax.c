#include<stdio.h>
int max,min;
int a[100];
int count,cnt;
void maxmin(int i,int j)
{
	int max1,min1,mid;
	if(i==j)
	{
		max=min=a[i];
		
	}
	else
	{
		if(i==j-1)
		{
			if(a[i]<a[j])
			{
				max=a[j];
				min=a[i];
				count++;
			}
			else
			{
				max=a[i];
				min=a[j];
				count++;
			}
		}
		else
		{
			mid=(i+j)/2;
			maxmin(i,mid);
			count++;
			max1=max;
			min1=min;
			maxmin(mid+1,j);
			if(max<max1)			
			{
				max=max1;
				count++;
			}
			if(min>min1)
			{	
				min=min1;
				count++;
			}
			
		}	
	}
}
int main()
{	max=a[0];
	min=a[0];
	int i, num;
	printf("\nEnter the total number of numbers : ");
	scanf("%d",&num);
	printf("Enter the numbers : \n");
	for(i=1;i<=num;i++)
	scanf("%d",&a[i]);
	maxmin(1,num);
	printf("Minimum element in an array : %d\n", min);
	printf("Maximum element in an array : %d\n", max);
	cnt=3*(num/2)-2;
	if(count==cnt)
	{
		printf("Count is: %d \n As Number of Elements in Order of 2 algorithm anlysis is done successfully and it is 3(n/2)-2",count);
 	}
 	else 
 	{
 		printf("Anlysis is not verified%d \n Elements is not in the order of 2",count);
 	}
 	
 	return 0;
}

/*-----OUTPUT------*/
/*
itexam@c05l0313:~$ gcc 3174521.c
itexam@c05l0313:~$ ./a.out

Enter the total number of numbers : 4
Enter the numbers : 
1
2
3
4
Minimum element in an array : 1
Maximum element in an array : 4
Count is: 4 
 As Number of Elements in Order of 2 algorithm anlysis is done successfully and it is 3(n/2)-2
itexam@c05l0313:~$ 
itexam@c05l0313:~$ ./a.out

Enter the total number of numbers : 5   
Enter the numbers : 
1
2
3
4
5
Minimum element in an array : 1
Maximum element in an array : 5
Anlysis is not verified Elements is not in the order of 2

*/
