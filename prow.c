#include<stdio.h> 
#include<unistd.h>
int main() 
{ 
  int count,i,j,n,time,remain,flag=0,time_quantum=4; 
  int wait_time=0,turnaround_time=0,at[10],bt[20],rt[10],p[20],wt[20],tat[20],pr[20],total=0,pos,temp,avg_wt,avg_tat,avwt=0,avtat=0;
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter input for proces number:%d\n",count+1); 
printf("Arrival Time:");
    scanf("%d",&at[count]);
printf("Priority:");
    scanf("%d",&pr[count]);
        p[count]=count+1;  
printf("Burst Time:");
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
  } 
  //printf("Enter Time Quantum:\t"); 
 // scanf("%d",&time_quantum); 
printf("\nFor Round Robin Scheduling");
  printf("\nProcess\t\tTurnaround Time\t\tWaiting Time\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t\t\t%d\t\t\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
 // printf("Average Waiting Time= %f\n",wait_time*1.0/n); 
 // printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
 sleep(10); 
//-------------------------------------------------------------------------//
    for(count=0;count<n;count++)
    {
        pos=count;
        for(j=count+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[count];
        pr[count]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[count];
        bt[count]=bt[pos];
        bt[pos]=temp;
 
        temp=p[count];
        p[count]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;	//waiting time for first process is zero
 
    //calculate waiting time
    for(count=1;count<n;count++)
    {
        wt[count]=0;
        for(j=0;j<i;j++)
            wt[count]+=bt[j];
 
        total+=wt[count];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 printf("\nFor Priority Scheduling");
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time\n");
    for(count=0;count<n;count++)
    {
        tat[count]=bt[count]+wt[count];     //calculate turnaround time
        total+=tat[count];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[count],bt[count],wt[count],tat[count]);
    }
 
  //  avg_tat=total/n;     //average turnaround time
  //  printf("\nAverage Waiting Time=%d",avg_wt);
//    printf("\nAverage Turnaround Time=%d",avg_tat);
 sleep(10);
//------------------------------------------------------------------------------------//
    //calculating waiting time
    for(count=1;count<n;count++)
    {
        wt[count]=0;
        for(j=0;j<count;j++)
        wt[count]+=bt[j];
    }
 printf("\nFor First Come First Served (FCFS) Scheduling");
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");

    //calculating turnaround time
    for(count=0;count<n;count++)
    {
        tat[count]=bt[count]+wt[count];
        avwt+=wt[count];
        avtat+=tat[count];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",count+1,bt[count],wt[count],tat[count]);
    }
   // avwt/=count;
 //   avtat/=count;
//    printf("\nAverage Waiting Time:%d",avwt);
 //   printf("\nAverage Turnaround Time:%d\n",avtat);
    return 0;
}
