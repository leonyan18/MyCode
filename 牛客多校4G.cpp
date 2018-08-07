#include<bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
const int N = 100050;
struct ss{
    int x, cnt, y;
}f[N];
bool cmp(ss p, ss q) {
    if(p.cnt == q.cnt) {
        return p.x > q.x;
    }
    return p.cnt > q.cnt;
}
int tmp[N];
map<int, int> myMap;
int main(){
    IO;
    int n, m, t;
    cin>>t;
    while(t--) {
        memset(f, 0, sizeof(f));
        memset(tmp, 0, sizeof(tmp));
        myMap.clear();
         
        cin>>n>>m;
         
        for (int i = 0; i < n; i++) {
            int x;
            cin>>x;
            myMap[x]++;
        }
         
        int cnt = 0;
        for (map<int, int>::iterator it = myMap.begin(); it != myMap.end(); it++) {
            f[cnt].x = it->first;
            f[cnt++].cnt = it->second;
        }
         
        sort(f, f + cnt, cmp);
         
//      tmp[i] 出现次数为 i 的数的个数
//      for(int i = 0; i < cnt; i++) {
//          tmp[f[i].cnt]++;
//      }
         
//      f[i] 成为出现次数最多需要删掉的数目
        int sum = 0;
        for (int i = 0; i < cnt; i++) {
            tmp[f[i].cnt]++;
            if(f[i].cnt != f[i-1].cnt || i == 0) {
                f[i].y = sum - (i) * (f[i].cnt-1);
            } else {
                f[i].y = f[i-1].y;
            }
//          f[i].y = sum;
            sum += f[i].cnt;
        }
         
//      myMap[i] 和 i 出现次数相同的数的个数 
        myMap.clear();
        for (int i = 0; i < cnt; i++) {
            myMap[f[i].x] = tmp[f[i].cnt];
        }
 
//     
//      for (int i = 0; i < cnt; i++) {
//          printf("x = %d cnt = %d y = %d map = %d\n", f[i].x, f[i].cnt, f[i].y, myMap[f[i].x]);
////            cout<<f[i].x <<" "<<f[i].cnt<<" "<<f[i].y<<endl;
//      }
 
        int M = -1;
        for (int i = 0; i < cnt; i++) {
            int val = f[i].x;
            if(m >= (myMap[val]-1 + f[i].y) ) {
                M = max(M, val);
            }
        }
         
        cout<<M<<endl;
    }
     
    return 0;
 
}
