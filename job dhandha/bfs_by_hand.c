#include<stdio.h>
#include<stdlib.h>

int edge[500][500];
int queue[500];
int front,end;
int check[500];
int label[500];

void add(int value)
{
    queue[end]=value;
    end++;
}

void bfs(int start)
{
    int i,j,k,l,m,n,u;
    add(start);
    label[start]=0;
    while(front<=end)
    {
        u=queue[front];
        printf("u===%d\n",u);
        front++;
        for(i=0; i<500; i++)
        {
            if(edge[u][i]==1 && check[i]==0)
            {
                if((label[u]+1)<label[i])
                    label[i]=label[u]+1;
                add(i);
                check[i]=1;
            }

        }
    }
}

int main()
{
    int i,j,k,l,m,n,u,v,start,dest;
    while(scanf("%d",&n)==1)
    {
        for(i=0; i<500; i++)
        {
            check[i]=0;
            label[i]=99999999;
        }
        for(i=0; i<500; i++)
        {
            for(j=0; j<500; j++)
            {
                edge[i][j]=0;
            }
        }
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            edge[u][v]=1;
            edge[v][u]=1;
        }
        front=0,end=0;
        scanf("%d%d",&start,&dest);
        bfs(start);
        for(i=1;i<=10;i++)
        printf("i==%d %d\n",i,label[i]);
    }
}
