/*
3
3 6
2999 3000 1
3001 3000 1
3000 2999 1
1 2999 3000 1
4 2999 2999 1
2 2995 2996
3 2995 2995 1 1
4 2995 2995 1
4 3000 3000 1
3 6
2999 3000 1
3001 3000 1
3000 2999 1
1 2999 3000 1
4 2999 2999 1
2 2995 2996
3 2995 2995 1 1
4 2995 2995 1
4 3000 3000 1
3 6
2999 3000 1
3001 3000 1
3000 2999 1
1 2999 3000 1
4 2999 2999 1
2 2995 2996
3 2995 2995 1 1
4 2995 2995 1
4 3000 3000 1
*/
#define LOCAL
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define maxn 3000000
#define inf 40000000
#define LL long long
vector<pair<int,int> > kk[10000005];
vector<pair<int,int> > tot;
int G[6005][6005];
int Gt[6006][6006];
int dir[4][2]={{1,-1},{1,1},{-1,1},{-1,-1}};
int ca=0;
set<pair<int,int > >s;
void inti()
{
	for(int i=0;i<=3163;i++)
	for(int j=0;j<=3163;j++)
	{
		if(i*i+j*j<=10000000)
		{
			kk[i*i+j*j].push_back(make_pair(i,j));
		}
	}
}
bool judge(int x,int y)
{
	if(x<=6000&&x>=1&&y>=1&&y<=6000&&Gt[x][y]) return 1;
	return 0;
}
//inline void scan_d(int  &ret) 
//{
//  char c; 
//  ret = 0;
//  while ((c = getchar()) < '0' || c > '9');
//  while (c >= '0' && c <= '9')
//  { 
//  ret = ret * 10 + (c - '0'), c = getchar();
//  }
//}
//inline void print_d(int x)
//{
//  if (x > 9)
//  {
//  print_d(x / 10);
//  }
//  putchar(x % 10 + '0');
//  
//}
int main()
{
	#ifdef LOCAL
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	#endif
	inti();
	int t;scanf("%d",&t);
	for(ca=1;ca<=t;ca++)
	{
//		memset(G,0,sizeof(G));
		printf("Case #%d:\n",ca); 
		int n,m;
		scanf("%d%d",&n,&m);
		tot.clear();
		for(int i=0;i<n;i++)
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);
			G[x][y]=w;
			Gt[x][y]=1;
			tot.push_back(make_pair(x,y));
		}
		int lastans=0;
		while(m--)
		{
			int op,x,y,k,w;
			scanf("%d%d%d",&op,&x,&y);
			x=(x+lastans)%6000+1;
			y=(y+lastans)%6000+1;
			if(op==1){
				scanf("%d",&w);
				G[x][y]=w;
				Gt[x][y]=1;
				tot.push_back(make_pair(x,y));
			}else if(op==2){
				G[x][y]=0;
				Gt[x][y]=ca;
			}else if(op==3){
				scanf("%d%d",&k,&w);
				s.clear();
				for(auto it : kk[k]){
					int xx=it.first;
					int yy=it.second;
					for(int z=0;z<4;z++)
					{
						int xxx=x-dir[z][0]*xx;
						int yyy=y-dir[z][1]*yy;
						if(judge(xxx,yyy))
							s.insert(make_pair(xxx,yyy));
					}
				}
				for(auto &it : s) G[it.first][it.second] += w;
			}else{
				scanf("%d",&k);
				LL ans=0;
				s.clear();
				for(auto it : kk[k]){
					int xx=it.first;
					int yy=it.second;
					for(int z=0;z<4;z++)
					{
						int xxx=x-dir[z][0]*xx;
						int yyy=y-dir[z][1]*yy;
						if(judge(xxx,yyy))
						{
							s.insert(make_pair(xxx,yyy));
						}
					}
				}
				for(auto it : s) ans+=G[it.first][it.second];
				printf("%lld\n",ans);
				lastans=ans;
			}
		}
		for(auto it : tot)
        {
            G[it.first][it.second] = Gt[it.first][it.second] = 0;
        }
	}
	return 0;
}
