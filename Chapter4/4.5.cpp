/*
* 题目名称：字母统计
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/Ai8VB72e
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 26

int number[MAXN];

int main() {
    string str;
    while (cin >> str) {
        memset(number, 0, sizeof(number));
        for (int i = 0; i < str.size(); ++i) {
            if ('A' <= str[i] && str[i] <= 'Z') {
                number[str[i] - 'A']++;
            }
        }
        for (int i = 0; i < 26; ++i) {
            printf("%c:%d\n", 'A' + i, number[i]);
        }
    }
    return 0;
}
