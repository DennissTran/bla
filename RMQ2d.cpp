#include<bits/stdc++.h>
using namespace std;
#define maxn 501
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define hm(x) (1<<x)
long long n,m,f[10][10][maxn][maxn];
void input()
{
	cin>>m>>n;
	fo(i,1,m)
	 fo(j,1,n)cin>>f[0][0][i][j];
}
void build()
{
	//base
	fo(j , 1 , 9)
	 fo(u , 1 , m)
	  fo(v , 1 , n-hm(j)+1)
		f[0][j][u][v]=min(f[0][j-1][u][v] , f[0][j-1][u][v+hm(j-1)]);
    //build
	fo(i , 1 , 9)fo(j , 0 , 9)
	 fo(u, 1 , m+1-hm(i))
	   fo(v , 1 , n+1-hm(j))
	    f[i][j][u][v]=min( f[i-1][j][u][v] , f[i-1][j][u+hm(i-1)][v]);			
}
int get(int u, int v, int p, int q)
{
    int k = log2(p-u+1);
    int l = log2(q-v+1);
    int r = p - hm(k) + 1;
    int s = q - hm(l) + 1;
    int m1 = min(f[k][l][u][v], f[k][l][u][s]);
    int m2 = min(f[k][l][r][v], f[k][l][r][s]);
    //cout << m1 << " " << m2 << "\n";
    return min(m1, m2);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	input();
	build();
	int q;
	cin>>q;
	while(q--)
	{
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<get(x1,y1,x2,y2)<<"\n";
	}
	return 0;
}
