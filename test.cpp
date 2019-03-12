#include <algorithm>
 #include <iostream>
 #include <cstring>
 #include <climits>
 #include <cstdio>
 #include <vector>
 #include <cstdlib>
 #include <ctime>
 #include <cmath>
 #include <queue>
 #include <stack>
 #include <map>
 #include <set>
 #define fi first
 #define lc (x<<1)
 #define se second
 #define U unsigned
 #define rc (x<<1|1)
 #define Re register
 #define LL long long
 #define MP std::make_pair
 #define CLR(i,a) memset(i,a,sizeof(i))
 #define FOR(i,a,b) for(Re int i = a;i <= b;++i)
 #define ROF(i,a,b) for(Re int i = a;i >= b;--i)
 #define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
 #define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
 #define DEBUG(x) std::cerr << #x << '=' << x << std::endl
 const int MAXN = 1000000+5;
 int N,maxL;
 std::set<std::pair<int,int> > L;
 inline int calc(){
     // 返回 set 中所有线段的并长度。(每个 pair 表示一个线段[first,second]
 }
 int main(){
     scanf("%d%d",&N,&maxL);
     while(N--){
         int opt,x,y;
         scanf("%d%d%d",&opt,&x,&y);
         if(opt == 1){
             if(L.find(MP(x,y)) != L.end()) continue;
             L.insert(MP(x,y));
         }
         if(opt == 2){
             if(L.find(MP(x,y)) == L.end()) continue;
             L.erase(MP(x,y));
         }
         if(opt == 3){
             printf("%d\n",calc());
         }
     }
     return 0;
 }
