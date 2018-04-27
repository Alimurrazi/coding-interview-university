#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int color[1000];
vector<int>edge[1000];
bool check[1000];

int bfs(int start)
{
    int i,j,k,l,u,v;
    queue<int>q;
    q.push(start);
    color[start]=0;
    check[start]=true;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0; i<edge[u].size(); i++)
        {
            v=edge[u][i];
            if(color[u]==color[v])
                return 0;

            if(color[u]==0)
                color[v]=1;
            else if(color[u]==1)
                color[v]=0;

            if(check[v]==false)
            {
                check[v]=true;
                q.push(v);
            }
        }
    }
    return 1;
}

int main()
{
    int i,j,k,l,m,n,t,u,v;
    //scanf("%d",&m);
    while(scanf("%d",&m)!=EOF)
    {
        if(m==0)
            break;
        for(i=0; i<m; i++)
        {
            color[i]=-1;
            check[i]=false;
        }
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
        }
        k=bfs(0);
        if(k==0)
            printf("NOT BICOLORABLE.\n");
        else
            printf("BICOLORABLE.\n");
        for(i=0; i<m; i++)
        {
            edge[i].clear();
        }
    }
}
