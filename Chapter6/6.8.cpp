/*
* 题目名称：素数
* 题目来源：北京航天航空大学复试上机题
* 题目链接：http://t.cn/AiCulqtW
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 10000 + 10;

vector<int> prime;                       		//保存质数
bool isPrime[MAXN];                  			//标记数组

void Initial() {
    for (int i = 0; i < MAXN; ++i) {			//初始化
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i < MAXN; ++i) {
        if (!isPrime[i]) {             			//非质数则跳过
            continue;
        }
        prime.push_back(i);
        if (i > MAXN / i) {                     //过大的数提前跳出
            continue;
        }
        for (int j = i * i; j < MAXN; j += i) {
            isPrime[j] = false;        			//质数的倍数为非质数
        }
    }
    return ;
}

int main() {
    Initial();
    int n;
    while (scanf("%d", &n) != EOF) {
        bool isOutput = false;        			//判断是否有输出
        for (int i = 0; i < prime.size() && prime[i] < n; ++i) {
            if (prime[i] % 10 == 1) {
                isOutput = true;
                printf("%d ", prime[i]);
            }
        }
        if (!isOutput) {
            printf("-1");
        }
        printf("\n");
    }
    return 0;
}

