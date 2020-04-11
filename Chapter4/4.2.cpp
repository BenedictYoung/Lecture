/*
* 题目名称：密码翻译
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/Ai8bGaIx
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        for (int i = 0; i < str.size(); ++i) {
            if (('A' <= str[i] && str[i] <= 'Y') || ('a' <= str[i] && str[i] <= 'y')) {
                str[i]++;
            } else if (str[i] == 'z' || str[i] == 'Z') {
                str[i] -= 25;
            }
        }
        cout << str << endl;
        return 0;
    }
}
