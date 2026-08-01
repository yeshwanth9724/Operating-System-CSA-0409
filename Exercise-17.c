#include <stdio.h>

int main()
{
    int n, m, i, j;
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10] = {0}, safe[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Maximum Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("Enter Available Resources:\n");
    for(j=0;j<m;j++)
        scanf("%d",&avail[j]);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j]=max[i][j]-alloc[i][j];

    int count=0;

    while(count<n)
    {
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                int flag=1;
                for(j=0;j<m;j++)
                    if(need[i][j]>avail[j])
                        flag=0;

                if(flag)
                {
                    safe[count++]=i;
                    finish[i]=1;

                    for(j=0;j<m;j++)
                        avail[j]+=alloc[i][j];
                }
            }
        }
    }

    printf("Safe Sequence: ");
    for(i=0;i<n;i++)
        printf("P%d ",safe[i]);

    return 0;
}
