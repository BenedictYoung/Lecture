/*
* 题目名称：Legal or Not
* 题目来源：HDU 3342
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=3342
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 500 + 10;

vector<int> graph[MAXN];
int inDegree[MAXN];                         //入度

bool TopologicalSort(int n) {
    queue<int> node;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            node.push(i);
        }
    }
    int number = 0;                         //拓扑序列结点个数
    while (!node.empty()) {
        int u = node.front();
        node.pop();
        number++;                           //拓扑序列结点加一
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i];
            inDegree[v]--;                  //后继结点入度减一
            if (inDegree[v] == 0) {
                node.push(v);
            }
        }
    }
    return n == number;                     //判断能否产生拓扑排序
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) {
            break;
        }
        memset(graph, 0, sizeof(graph));
        memset(inDegree, 0, sizeof(inDegree));
        while (m--) {
            int from, to;
            scanf("%d%d", &from, &to);
            graph[from].push_back(to);
            inDegree[to]++;
        }
        if (TopologicalSort(n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
