########################macthing##############
int X[MAXN],Y[MAXN];
int m,n,res=0;
vector<int> g[MAXN];
int x[MAXN],y[MAXN],d[MAXN], q[MAXN];

/*#####Starting code#####*/

bool FindPath()
{
    int L=1, R=0;

    for(int u=1; u<=n; u++)
        if (x[u]==0)
        {

            d[u]=0;

            q[++R]=u;

        }
        else d[u]=INF;
    d[0]=INF;
    while (L<=R)
    {
        int u=q[L++];
        tr(i,g[u])
        {
            int v=i;

            if (d[y[v]]==INF)
            {

                d[y[v]]=d[u]+1;

                if (y[v]) q[++R]=y[v];

            }

        }

    }

    return (d[0]!=INF);

}

bool dfs(int u)
{

//if (u==0) return(true);
    tr(i,g[u])
    {
        int v=i;

        if (y[v]==0)
        {

            x[u]=v;
            y[v]=u;
            d[u]=INF;
            return true;

        }

        if (d[y[v]]==d[u]+1)

            if (dfs(y[v]))
            {

                x[u]=v;
                y[v]=u;
                d[u]=INF;
                return true;

            }

    }
    d[u]=INF;
    return false;

}
void GhepMax()
{
    while (FindPath())
    {
        for(int u=1; u<=n; u++) if (x[u]==0)
                if (dfs(u)) res++;

    }

    cout<<res;

}
