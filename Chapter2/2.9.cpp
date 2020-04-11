/*
* 题目名称：剩下的树
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9ufYo5
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10000 + 10;

bool tree[MAXN];

int main() {
    int length;
    int caseNumber;
    while (scanf("%d%d", &length, &caseNumber) != EOF) {
        for (int i = 0; i <= length; ++i) {
            tree[i] = true;
        }
        int number = length + 1;                //树的数量
        while (caseNumber--) {
            int left, right;
            scanf("%d%d", &left, &right);
            for (int i = left; i <= right; ++i) {
                if (tree[i]) {
                    tree[i] = false;            //移除该树
                    number--;
                }
            }
        }
        printf("%d\n", number);
    }
    return 0;
}

