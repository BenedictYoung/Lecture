/*
* 题目名称：二叉树遍历
* 题目来源：华中科技大学复试上机题
* 题目链接：http://t.cn/AiKgDfLU
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct TreeNode {
    char data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(char c): data(c), leftChild(NULL), rightChild(NULL) {}
};

TreeNode* Build(string str1, string str2) {
    if (str1.size() == 0) {                             //返回空树
        return NULL;
    }
    char current = str1[0];                             //当前字符
    TreeNode* root = new TreeNode(current);             //创建新节点
    int position = str2.find(current);                  //寻找切分点
    root -> leftChild = Build(str1.substr(1, position), str2.substr(0, position));
    root -> rightChild = Build(str1.substr(position + 1), str2.substr(position + 1));
    return root;
}

void PostOrder(TreeNode* root) {                        //后序遍历
    if (root == NULL) {
        return;
    }
    PostOrder(root->leftChild);
    PostOrder(root->rightChild);
    printf("%c", root->data);
    return;
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        TreeNode* root = Build(str1, str2);
        PostOrder(root);
        printf("\n");
    }
    return 0;
}

