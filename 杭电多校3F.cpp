#include <bits/stdc++.h>

using namespace std;
const int Max = 1e5 + 7;
typedef long long LL;
LL w[Max], n;
bool visit[Max];
LL ans1, ans2;

struct Node {
    int val;
    vector<int> next;
};
Node graph[Max];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, u, v;
    cin >> T;
    while (T--) {
        ans1 = ans2 = 0;
        memset(graph, 0, sizeof(graph));
        memset(visit, 0, sizeof(visit));
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> graph[i].val;
        }
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            if (u < v) {
                graph[u].next.push_back(v);
            }
        }
        bool flag = false;
        visit[1] = true;
        ans1 ^= graph[1].val;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < graph[i].next.size(); ++j) {
//                cout << graph[graph[i].next[j]].val << endl;
                if (flag) ans2 ^= graph[graph[i].next[j]].val;
                else ans1 ^= graph[graph[i].next[j]].val;
            }
            flag = !flag;
        }
//        cout << ans2 << ' ' << ans1 << endl;
        if (ans2 != ans1)
            cout << 'Q' << endl;
        else cout << 'D' << endl;
    }
    return 0;
}
