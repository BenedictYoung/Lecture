/*
* 题目名称：10进制 VS 2进制
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/AiCuoHKg
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

string Multiple(string str, int x) {                //字符串乘法
    int carry = 0;                                  //保存进位
    for (int i = str.size() - 1; i >= 0; --i) {
        int current = x * (str[i] - '0') + carry;
        str[i] = current % 10 + '0';
        carry = current / 10;
    }
    if (carry != 0) {                               //仍有进位
        str = to_string(carry) + str;
    }
    return str;
}

string Add(string str, int x) {                     //字符串加法
    int carry = x;
    for (int i = str.size() - 1; i >= 0; --i) {
        int current = (str[i] - '0') + carry;
        str[i] = current % 10 + '0';
        carry = current / 10;
    }
    if (carry != 0) {                               //仍有进位
        str = to_string(carry) + str;
    }
    return str;
}

int main() {
    string str;
    while (cin >> str) {
        vector<int> binary;
        while (str.size() != 0) {
            int last = str[str.size() - 1] - '0';   //最低位的值
            binary.push_back(last % 2);
            str = Divide(str, 2);                   //字符串除2
        }
        string answer = "0";
        for (int i = 0; i < binary.size(); ++i) {
            answer = Multiple(answer, 2);           //字符串乘2
            answer = Add(answer, binary[i]);        //加数位值
        }
        cout << answer << endl;
    }
    return 0;
}
