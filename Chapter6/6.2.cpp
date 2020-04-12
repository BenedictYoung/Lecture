/*
* 题目名称：进制转换
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/AiCuoPRO
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

string Divide(string str, int x) {                  //字符串除法
    int remainder = 0;                              //保存余数
    for (int i = 0; i < str.size(); ++i) {
        int current = remainder * 10 + str[i] - '0';
        str[i] = current / x + '0';
        remainder = current % x;
    }
    int position = 0;
    while (str[position] == '0') {                  //寻找首个非0下标
        position++;
    }
    return str.substr(position);                    //删除前置多余的0
}

int main() {
    string str;
    while (cin >> str) {
        vector<int> binary;
        while (str.size() != 0) {
            int last = str[str.size() - 1] - '0';   //最低位的值
            binary.push_back(last % 2);             //取模运算
            str = Divide(str, 2);                   //整除运算
        }
        for (int i = binary.size() - 1; i >= 0; --i) {
            printf("%d", binary[i]);
        }
        printf("\n");
    }
    return 0;
}
