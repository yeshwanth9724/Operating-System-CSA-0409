#include <stdio.h>

int main()
{
    int n,i,time=0,remain,quantum;
    int bt[20],rt[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    remain=n;

    for(i=0;i<n;i++)
    {
        printf("Burst Time of P%d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&quantum);

    while(remain!=0)
    {
        for(i=0;i<n;i++)
        {
            if(rt[i]>0)
            {
                if(rt[i]<=quantum)
                {
                    time+=rt[i];
                    rt[i]=0;
                    remain--;
                    printf("P%d completed at %d\n",i+1,time);
                }
                else
                {
                    rt[i]-=quantum;
                    time+=quantum;
                }
            }
        }
    }

    return 0;
}
