/*
* 题目名称：手机键盘
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9ulcIc
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int keyTable[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main() {
    string str;
    while (cin >> str) {
        int time = 0;
        for (int i = 0; i < str.size(); ++i) {
            time += keyTable[str[i] - 'a'];         //按键时间
            if (i != 0 && str[i] - str[i - 1] == keyTable[str[i] - 'a'] - keyTable[str[i - 1] - 'a']) {
                time += 2;                          //等待时间
            }
        }
        printf("%d\n", time);
    }
    return 0;
}

