/*
* 题目名称：Is It A Tree?
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiO7FyDO
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e4 + 10;

int father[MAXN];                               //父亲结点
int height[MAXN];                               //结点高度
int inDegree[MAXN];                             //入度
bool visit[MAXN];                               //标记

void Initial() {                                //初始化
    for (int i = 0; i < MAXN; i++) {
        father[i] = i;
        height[i] = 0;
        inDegree[i] = 0;
        visit[i] = false;
    }
}

int Find(int x) {                               //查找根结点
    if (x != father[x]) {
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int x, int y) {                      //合并集合
    x = Find(x);
    y = Find(y);
    if (x != y) {
        if (height[x] < height[y]) {
            father[x] = y;
        } else if (height[y] < height[x]) {
            father[y] = x;
        } else {
            father[y] = x;
            height[x]++;
        }
    }
    return ;
}

bool IsTree() {
    bool flag = true;
    int component = 0;                          //连通分量数目
    int root = 0;                               //根结点数目
    for (int i = 0; i < MAXN; ++i) {
        if (!visit[i]) {
            continue;
        }
        if (father[i] == i) {
            component++;
        }
        if (inDegree[i] == 0) {
            root++;
        } else if (inDegree[i] > 1) {           //入度不满足要求
            flag = false;
        }
    }
    if (component != 1 || root != 1) {          //不符合树定义
        flag = false;
    }
    if(component == 0 && root == 0) {           //空集也是树
        flag = true;
    }
    return flag;
}

int main() {
    int x, y;
    int caseNumber = 0;
    Initial();
    while (scanf("%d%d", &x, &y) != EOF) {
        if (x == -1 && y == -1) {
            break;
        }
        if (x == 0 && y == 0) {
            if (IsTree()) {
                printf("Case %d is a tree.\n", ++caseNumber);
            } else {
                printf("Case %d is not a tree.\n", ++caseNumber);
            }
            Initial();
        } else {
            Union(x, y);
            inDegree[y]++;
            visit[x] = true;
            visit[y] = true;
        }
    }
    return 0;
}

