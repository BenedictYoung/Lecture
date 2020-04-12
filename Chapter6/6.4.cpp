/*
* 题目名称：进制转换2
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/AiCuKG7E
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

char IntToChar(int x) {                             //数字变成字符
    if (x < 10) {
        return x + '0';
    } else {
        return x - 10 + 'a';
    }
}

int CharToInt(char c) {                             //字符变成数字
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return c - 'A' + 10;
    }
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    string str;
    cin >> str;
    long long number = 0;
    for (int i = 0; i < str.size(); ++i) {          //从m进制变成十进制
        number *= m;
        number += CharToInt(str[i]);
    }
    vector<char> answer;
    if (number == 0) {
        answer.push_back('0');
    } else {
        while (number != 0) {                       //从十进制变成n进制
            answer.push_back(IntToChar(number % n));
            number /= n;
        }
    }
    for (int i = answer.size() - 1; i >= 0; --i) {  //逆序输出
        printf("%c", answer[i]);
    }
    printf("\n");
    return 0;
}
