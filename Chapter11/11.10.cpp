/*
* 题目名称：Instrction Arrangement
* 题目来源：HDU 4109
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=4109
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

const int MAXN = 1000 + 10;
const int INF = INT_MAX;

struct Edge {
    int to;                                     //终点
    int length;                                 //长度
    Edge(int t, int l): to(t), length(l) {}
};

vector<Edge> graph[MAXN];
int earliest[MAXN];                             //最早完成时间
int latest[MAXN];                               //最晚完成时间
int inDegree[MAXN];                             //入度

int CriticalPath(int n) {
    vector<int> topology;                       //拓扑序列
    queue<int> node;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            node.push(i);
            earliest[i] = 1;                    //初始化为1
        }
    }
    int totalTime = 0;                          //总耗时
    while (!node.empty()) {
        int u = node.front();
        topology.push_back(u);
        node.pop();
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].to;
            int l = graph[u][i].length;
            earliest[v] = max(earliest[v], earliest[u] + l);
            inDegree[v]--;
            if (inDegree[v] == 0) {
                node.push(v);
                totalTime = max(totalTime, earliest[v]);
            }
        }
    }
    for (int i = topology.size() - 1; i >= 0; --i) {
        int u = topology[i];
        if (graph[u].size() == 0) {
            latest[u] = earliest[u];            //汇点的最晚完成时间初始化
        } else {
            latest[u] = INF;                    //非汇点的最晚完成时间初始化
        }
        for (int j = 0; j < graph[u].size(); ++j) {
            int v = graph[u][j].to;
            int l = graph[u][j].length;
            latest[u] = min(latest[u], latest[v] - l);
        }
    }
    return totalTime;
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(graph, 0, sizeof(graph));
        memset(earliest, 0, sizeof(earliest));
        memset(latest, 0, sizeof(latest));
        memset(inDegree, 0, sizeof(inDegree));
        while (m--) {
            int from, to, length;
            scanf("%d%d%d", &from, &to, &length);
            graph[from].push_back(Edge(to, length));
            inDegree[to]++;
        }
        int answer = CriticalPath(n);
        printf("%d\n", answer);
    }
    return 0;
}

