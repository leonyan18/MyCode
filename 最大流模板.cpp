#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
 
#define N 16
int capacity[N][N];//����
int flow[N];//��������
int pre[N];//ǰ��
 
int n, m;
queue<int> Q;
 
int BFS(int src, int des) {
    //��ʼ��
    while (!Q.empty()) {
        Q.pop();
    }
    for (int i = 1; i < n + 1; i++) {
        pre[i] = -1;
    }
    pre[src] = 0;
    flow[src] = INT_MAX;//��ʼ��Դ�������Ϊ����� 
    Q.push(src);
    while (!Q.empty()) {
        int index = Q.front();
        Q.pop();
        if (index == des) {//�ҵ�������·�� 
            break;
        }
        for (int i = 1; i < n + 1; i++) {
            if (i != src && capacity[index][i] > 0 && pre[i] == -1) {
                pre[i] = index;
                //����·��������
                flow[i] = min(capacity[index][i], flow[index]);
                Q.push(i);
            }
        }
    }//while
    if (pre[des] == -1) {
        return -1;  //����ͼ�в���������·��
    } else {
        return flow[des];
    }
}
 
int MaxFlow(int src, int des) {
        int aug = 0;
        int sumflow = 0;
        while ((aug = BFS (src, des)) != -1) {
            int k = des;  //����ǰ��Ѱ��·�� 
            while (k != src) {
                int last = pre[k];
                capacity[last][k] -= aug;
                capacity[k][last] += aug;
                k = last;
            }
            sumflow += aug;
        }
        return sumflow;
}
             
int main() {
    int cas, cases = 1;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &m);
        memset(capacity, 0, sizeof(capacity));
        memset(flow, 0, sizeof(flow));
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            if (u == v) {//����յ���ͬ
                continue;
            }
            capacity[u][v] += w;
        }
        printf("Case %d: ", cases++);
        printf("%d\n", MaxFlow(1, n));
    }
    return 0;
}
