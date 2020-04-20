/*
* 题目名称：最短路径问题
* 题目来源：浙江复试上机题
* 题目链接：http://t.cn/AilPbME2
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 1000 + 10;
const int INF = INT_MAX;                        //无穷设为很大的数

struct Edge {
    int to;                                     //终点
    int length;                                 //长度
    int price;                                  //花费
    Edge(int t, int l, int p): to(t), length(l), price(p) {}
};

struct Point {
    int number;                                 //点的编号
    int distance;                               //源点到该点距离
    Point(int n, int d): number(n), distance(d) {}
    bool operator< (const Point& p) const {
        return distance > p.distance;           //距离小的优先级高
    }
};

vector<Edge> graph[MAXN];                       //邻接表实现的图
int minDistance[MAXN];                          //源点到各点最短距离
int cost[MAXN];                                 //记录花费

void Dijkstra(int start) {
    minDistance[start] = 0;
    cost[start] = 0;
    priority_queue<Point> myPriorityQueue;
    myPriorityQueue.push(Point(start, minDistance[start]));
    while (!myPriorityQueue.empty()) {
        int u = myPriorityQueue.top().number;   //离源点最近的点
        myPriorityQueue.pop();
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].to;
            int l = graph[u][i].length;
            int p = graph[u][i].price;
            if ((minDistance[v] == minDistance[u] + l && cost[v] > cost[u] + p) || minDistance[v] > minDistance[u] + l) {
                minDistance[v] = minDistance[u] + l;
                cost[v] = cost[u] + p;
                myPriorityQueue.push(Point(v, minDistance[v]));
            }
        }
    }
    return ;
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) {
            break;
        }
        memset(graph, 0, sizeof(graph));
        fill(minDistance, minDistance + n + 1, INF);
        fill(cost, cost + n + 1, INF);
        while (m--) {
            int from, to, length, price;
            scanf("%d%d%d%d", &from, &to, &length, &price);
            graph[from].push_back(Edge(to, length, price));
            graph[to].push_back(Edge(from, length, price));
        }
        int start, terminal;                    //起点与终点
        scanf("%d%d", &start, &terminal);
        Dijkstra(start);
        printf("%d %d\n", minDistance[terminal], cost[terminal]);
    }
    return 0;
}
