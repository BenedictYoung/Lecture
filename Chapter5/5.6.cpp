/*
* 题目名称：简单计算器
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/AiKoGS94
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <stack>

using namespace std;

int Priority(char c) {                      //优先级顺序 #,$,+-,*/
    if (c == '#') {
        return 0;
    } else if (c == '$') {
        return 1;
    } else if (c == '+' || c == '-') {
        return 2;
    } else {
        return 3;
    }
}

double GetNumber(string str, int& index) {  //获得下个数字
    double number = 0;
    while (isdigit(str[index])) {
        number = number * 10 + str[index] - '0';
        index++;
    }
    return number;
}

double Calculate(double x, double y, char op) {
    double result = 0;
    if (op == '+') {
        result = x + y;
    } else if (op == '-') {
        result = x - y;
    } else if (op == '*') {
        result = x * y;
    } else if (op == '/') {
        result = x / y;
    }
    return result;
}

int main() {
    string str;
    while (getline(cin, str)) {
        if (str == "0") {
            break;
        }
        stack<char> operation;              //运算符栈
        stack<double> number;               //运算数栈
        str += '$';                         //字符串尾部添加$
        operation.push('#');                //运算符栈底添加#
        int index = 0;                      //字符串下标
        while (index < str.size()) {
            if (str[index] == ' ') {
                index++;
            } else if (isdigit(str[index])) {
                number.push(GetNumber(str, index));
            } else {
                if (Priority(operation.top()) < Priority(str[index])) {
                    operation.push(str[index]);
                    index++;
                } else {
                    double y = number.top();
                    number.pop();
                    double x = number.top();
                    number.pop();
                    number.push(Calculate(x, y, operation.top()));
                    operation.pop();
                }
            }
        }
        printf("%.2f\n", number.top());
    }
    return 0;
}
