/*
* 题目名称：魔咒词典
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/AiCufczt
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

map<string, string> dictionary;

int main() {
    string str;
    while (getline(cin, str)) {
        if (str == "@END@") {
            break;
        }
        int position = str.find(']');               //分界点
        string key = str.substr(0, position + 1);   //魔咒
        string value = str.substr(position + 2);    //功能
        dictionary[key] = value;
        dictionary[value] = key;
    }
    int n;
    scanf("%d", &n);
    getchar();                                      //吃掉回车
    while (n--) {
        string key;
        getline(cin, key);
        string answer = dictionary[key];
        if (answer == "") {                         //魔咒或者功能找不到
            answer = "what?";
        } else if (answer[0] == '[') {              //魔咒需要删除方括号
            answer = answer.substr(1, answer.size() - 2);
        }
        cout << answer << endl;
    }
    return 0;
}
