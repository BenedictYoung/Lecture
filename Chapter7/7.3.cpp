/*
* 题目名称：Senior's Gun
* 题目来源：HDU 5281
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=5281
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

long long gun[MAXN];
long long monster[MAXN];

bool Compare(long long x, long long y) {
    return x > y;
}

int main() {
    int caseNumber;
    scanf("%d", &caseNumber);
    while (caseNumber--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &gun[i]);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%lld", &monster[i]);
        }
        sort(gun, gun + n, Compare);        //枪从大到小排序
        sort(monster, monster + m);         //怪从小到大排序
        long long answer = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= m || gun[i] <= monster[i]) {
                break;
            }
            answer += (gun[i] - monster[i]);
        }
        printf("%lld\n", answer);
    }
    return 0;
}

