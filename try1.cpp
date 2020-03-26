#include<stdio.h>
#include<stdlib.h>
main()
{
	int p[100],at[100],bt[100],wt[100],tat[100],start[100],end[100],n,i,j,temp,swt=0,stat=0;
	float awt,atat;
	printf("enter the number of processes\t");
	scanf("%d",&n);
	if(n<0 || n>100)
	{
		printf("Invalid value for number of process \n Please again for value within  1 to 100");
		exit(0);
	}
	for(int i=0;i<n;i++)
	{
		printf("enter the arrival time of process%d\t",(i+1));
		scanf("%d",&at[i]);	
		if(at[i]<0|| at[i]>100)
		{
			printf("ERROR \n Try for value within range of 0 to 100");
			exit(0);
			
		}	
		bt[i]=2*at[i];
		p[i]=(i+1);
		start[i]=0;
		
				
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(at[j]<at[j+1])
			{
				temp=at[j];
				at[j]=at[j+1];
				at[j+1]=temp;
				
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	if(at[0]==0)
	{
		start[0]=0;
		end[0]=0+bt[0];
	}
	else
	{
		start[0]=at[0];
		end[0]=at[0]+bt[0];
	}
	
	for(i=1;i<n;i++)
	{
		if(at[i]>=end[i-1])
		{
			start[i]=at[i];
			end[i]=start[i]+bt[i];
		}
		else
		{
			start[i]=end[i-1];
			end[i]=start[i]+bt[i];
			
		}	
			
	}
	
	
	for(i=0;i<n;i++)
	{
		tat[i]=end[i]-at[i];
	}
	
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
	
	for(i=0;i<n;i++)
	{
		swt+=wt[i];
		stat+=tat[i];
	}
	awt=swt/n;
	atat=stat/n;
	
	printf("therefore the solution is:\n");
	printf("process\t arrival time\t burst time\t end time \t turn around time\t waiting time\n");
	for(i=0;i<n;i++)
	{
		printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],at[i],bt[i],end[i],tat[i],wt[i]);
	}
	
	printf("\n Average waiting time: %f",awt);
	printf("\n Average turn around time: %f",atat);

}   

