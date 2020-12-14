#include<stdio.h>
#include<string.h>

struct node
{
    unsigned dist[20];
    unsigned from[20];
    
}router[10];

int main()
{
    int cost_matrix[20][20];
    int nodes, i, j, k, count=0;
    char *via[20][20];

    printf("\nEnter the number of nodes : ");

    scanf("%d",&nodes);//Enter the nodes
    printf("\nEnter the cost matrix :\n");

    for(i=0; i<nodes; i++)
    {
        for(j=0; j<nodes; j++)
        {
            scanf("%d",&cost_matrix[i][j]);
            router[i].dist[j]=cost_matrix[i][j];
            router[i].from[j]=j;
        }
        cost_matrix[i][i]=0;
    }

    do
    {
        count=0;

        for(i=0; i<nodes; i++) // updating routing table of Node i
        {
            for(j=0; j<nodes; j++) // updating each row of routing table of i - row value is j
            {
                for(k=0; k<nodes; k++) // comparing with routing tables of k
                {
                    if(router[i].dist[j] > cost_matrix[i][k] + router[k].dist[j])
                    {
                        router[i].dist[j] = router[i].dist[k] + router[k].dist[j];
                        router[i].from[j] = k;
                        
                        char z = (char)k;
                        strncat(router[i].via, &z, 1);
                        count++;
                    }
                }
            }
        }
    }
    while(count != 0);
        
    for(i=0; i<nodes; i++)
    {
        printf("\n\n For router %d\n",i+1);
        for(j=0; j<nodes; j++)
        {
            printf("\t\nnode %d via %d %s Distance %d ", j+1, router[i].from[j]+1, via[i][j], router[i].dist[j]);
        }
    }

    printf("\n\n\n");
    
}