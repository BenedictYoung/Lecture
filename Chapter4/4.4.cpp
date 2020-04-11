/*
* 题目名称：统计字符
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/Ai8fvq4I
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 256;

int number[MAXN];

int main() {
    string str1, str2;
    while (getline(cin, str1)) {
        if (str1 == "#") {
            break;
        }
        getline(cin, str2);
        memset(number, 0, sizeof(number));
        for (int i = 0; i < str2.size(); ++i) {
            number[str2[i]]++;
        }
        for (int i = 0; i < str1.size(); ++i) {
            printf("%c %d\n", str1[i], number[str1[i]]);
        }
    }
    return 0;
}
