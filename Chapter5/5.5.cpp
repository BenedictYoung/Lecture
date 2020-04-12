/*
* 题目名称：扩号匹配问题
* 题目来源：OpenJudge 1978
* 题目链接：http://ccnu.openjudge.cn/practice/1978/
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        stack<int> brackets;
        string answer(str.size(), ' ');         //初始化为输入长度个空格
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '(') {
                brackets.push(i);               //压入左括号下标
            } else if (str[i] == ')') {
                if (!brackets.empty()) {
                    brackets.pop();
                } else {
                    answer[i] = '?';            //右括号不匹配
                }
            }
        }
        while (!brackets.empty()) {
            answer[brackets.top()] = '$';       //左括号不匹配
            brackets.pop();
        }
        cout << str << endl;
        cout << answer << endl;
    }
    return 0;
}
