#include<stdio.h>
struct PCB
{
    int pid,arrival,burst,turnaround,wait,completion;
};
void pline(int x);
void main()
{
    int i,num,j,n,a[10],c,l;
    float avg=0.0,sum=0.0,avg1=0.0,sum1=0.0,avg2=0.0,sum2=0.0;
    struct PCB p[10],temp;
    printf("enter total no. of process");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("enter arrival time and burst time of the processor");
        scanf("%d %d",&p[i].arrival,&p[i].burst);
        p[i].pid=i+1;
    }
        for(i=0;i<num-1;i++)
        {
            for(j=0;j<num-i-1;j++)
            {
                if(p[j].arrival>p[j+1].arrival)
                {
                    temp=p[j];
                    p[j]=p[j+1];
                    p[j+1]=temp;
                }
            }
        }
    for(i=0;i<num;i++)
    {
        sum=sum+p[i].burst;
        p[i].completion=sum;
        p[i].turnaround=p[i].completion-p[i].arrival;
        p[i].wait=p[i].turnaround-p[i].burst;
        sum1=sum1+p[i].wait;
        sum2=sum2+p[i].turnaround;
    }
    pline(64);
    printf("PID\tArrival\tBurst\tcompletion waiting  turnaround\n");
    pline(64);
    for(i=0;i<num;i++)
    {
        printf("%d\t%d\t%d\t%d\t   %d\t\t%d\n",p[i].pid,p[i].arrival,p[i].burst,p[i].completion,p[i].wait,p[i].turnaround);
    }
    pline(64);
    avg1=sum1/(float)num;
    avg2=sum2/(float)num;
    printf("\n total waiting time :%f.",sum1);
    printf("\n average waiting time :%.3f.",avg1);
    printf("\n total turnaround time :%f.",sum2);
    printf("\n average turnaround time :%.3f.",avg2);
    l=p[0].arrival;
    for(i=0;i<num;i++)
    {
        if(l>p[i].arrival)
        l=p[i].arrival;
    }
    printf("\nGantt Chart :\n");
    printf("\t+");
    for(i=0;i<num;i++)
    printf("-------+");
    printf("\n");
    printf("\t|");
    for(i=0;i<num;i++)
    printf("   %d   |",p[i].pid);
    printf("\n");
    printf("\t+");
    for(i=0;i<num;i++)
    printf("-------+");
    printf("\n\t%d",l);
    c=l;
    for(i=0;i<num;i++)
    {
        c=c+p[i].burst;
        printf("\t%d",c);
    }
    printf("\n\n");

}
void pline(int x)
{
    int i;
    for(i=0;i<x;i++)
    {
    printf("-");
    }
    printf("\n");
}

