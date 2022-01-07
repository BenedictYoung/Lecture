/*
* 题目名称：A Knight's Journey
* 题目来源：POJ 2488
* 题目链接：http://poj.org/problem?id=2488
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 30;                            //棋盘参数

int direction[8][2] = {
    {-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}
};

bool visit[MAXN][MAXN];                         //标记矩阵

bool DFS(int x, int y, int step, string answer, int p, int q) {
    if (step == p * q) {                        //搜索成功
        cout << answer << endl << endl;
        return true;
    }
    for (int i = 0; i < 8; ++i) {           //遍历邻居结点
        int nx = x + direction[i][0];       //扩展状态坐标
        int ny = y + direction[i][1];
        if (nx < 0 || nx >= p || ny < 0 || ny >= q || visit[nx][ny]) {
            continue;
        }
        char col = ny + 'A';                //该点编号
        char row = nx + '1';
        visit[nx][ny] = true;               //标记该点
        if (DFS(nx, ny, step + 1, answer + col + row, p, q)) {
            return true;
        }
        visit[nx][ny] = false;              //取消标记
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    int caseNumber = 0;
    while (n--) {
        int p, q;
        scanf("%d%d", &p, &q);
        memset(visit, false, sizeof(visit));
        cout << "Scenario #" << ++caseNumber << ":" << endl;
        visit[0][0] = true;                       //标记A1点
        if (!DFS(0, 0, 1, "A1", p, q)) {
            cout << "impossible" << endl << endl;
        }
    }
    return 0;
}
