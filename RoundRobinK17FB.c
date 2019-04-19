#include<stdio.h>
#include<conio.h>
void main()
{
 	int a,pro[10],want[10],wait[10],turn[10],i,j,n,n1;
 	int BT[10],flag[10],ttat=0,twt=0;
 	float tw,tt; 
	printf("Enter the number of Processors : ");
 	scanf("%d",&n);
 	n1=n;
 	printf("\n Enter the Time quantum : ");
 	scanf("%d",&a);
 	for(i=1;i<=n;i++)
	{
		printf("\n Enter the (%d)-process ID  : ",i);
		scanf("%d",&pro[i]);
		printf("\n Enter the Burst Time for the process : ");
		scanf("%d",&BT[i]);
		want[i]=BT[i];
	}
	for(i=1;i<=n;i++)
	{
  		flag[i]=1;
  		wait[i]=0;
 	}
	while(n!=0)
	{
   		for(i=1;i<=n;i++)
   		{
     		if(want[i]>=a)
     		{
	 			for(j=1;j<=n;j++)
       			{
	  				if((i!=j)&&(flag[i]==1)&&(want[j]!=0))
	  				wait[j]+=a;
       			}
 				want[i]-=a;
 				if(want[i]==0)
				{
					flag[i]=0;
					n--;
				}
			}
			else
			{
  				for(j=1;j<=n;j++)
      			{
	  				if((i!=j)&&(flag[i]==1)&&(want[j]!=0))
	  				wait[j]+=want[i];
      	 		}
				want[i]=0;
				n--;
				flag[i]=0;
			}
 		}			
	}
	for(i=1;i<=n1;i++)
	{
		turn[i]=wait[i]+BT[i];
		twt=twt+wait[i];
		ttat=ttat+turn[i];
	}
	tw=(float)twt/n1;
	tt=(float)ttat/n1;
	
	printf("\n\n Process\tProcess ID  \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
	for(i=1;i<=n1;i++)
	{
		printf("\n %5d \t     %5d \t\t %5d \t\t %5d \t\t %5d \n", i,pro[i],BT[i],wait[i],turn[i]);
	}
	printf("\n The average Waiting Time = %f",tw);
	printf("\n The average Turn around Time = %f",tt);
	getch();
}         



