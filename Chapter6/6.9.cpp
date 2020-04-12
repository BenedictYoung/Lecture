/*
* 题目名称：质因子的个数
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/Aip7J0Oo
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 4e4;

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
        int answer = 0;
        for (int i = 0; i < prime.size() && prime[i] < n; ++i) {
            int factor = prime[i];
            while (n % factor == 0) {           //不断试除
                n /= factor;
                answer++;
            }
        }
        if (n > 1) {                            //还存在一个质因数
            answer++;
        }
        printf("%d\n", answer);
    }
    return 0;
}
