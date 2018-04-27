#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

vector<int>edge[100005];
queue<int>q;
int label[100005];
bool check[100005];
bool check1[100005];
int ara[100005];

void bfs(int start)
{
    int i,j,k,l,m,n,u,v,t;
    queue<int>p;
    p.push(start);
    check1[start]=true;
    label[start]=0;
    while(!p.empty())
    {
        u=p.front();
        p.pop();
        for(i=0; i<edge[u].size(); i++)
        {
            v=edge[u][i];
            if(check1[v]==false)
            {
                p.push(v);
                check1[v]=true;
                if((label[u]+1)<label[v])
                {
                    label[v]=label[u]+1;
                }
            }
        }
    }
}

int main()
{
    int i,j,k,l,m,n,t,u,v,start,distance,index;
    t=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            return 0;

        for(i=0; i<100005; i++)
        {
            check[i]=false;
            label[i]=9999999;
        }
        index=0;
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            if(check[u]==false)
            {
                check[u]=true;
                ara[index]=u;
                index++;
            }
            if(check[v]==false)
            {
                check[v]=true;
                ara[index]=v;
                index++;
            }
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        while(1)
        {
            scanf("%d%d",&start,&distance);
            if(start==0 && distance==0)
                break;
            for(i=0; i<100005; i++)
            {
                check1[i]=false;
                label[i]=9999999;
            }

            bfs(start);
            k=0;
            for(i=0; i<index; i++)
            {
                //  printf("%d\n",ara[i]);
                u=ara[i];
                if(label[u]>distance)
                    k++;
            }
            //Case 1: 5 nodes not reachable from node 35 with TTL = 2.
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",t,k,start,distance);
            t=t+1;
            //printf("%d nodes not reachable\n",k);
        }
        for(i=0; i<index; i++)
            edge[i].clear();
    }
}
