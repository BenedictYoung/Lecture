/*
* 题目名称：二叉树遍历
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/AiKuUTlX
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

TreeNode* Build(int& position, string str) {
    char current = str[position++];                     //当前字符
    if (current== '#') {                                //返回空树
        return NULL;
    }
    TreeNode* root = new TreeNode(current);             //创建新节点
    root -> leftChild = Build(position, str);           //创建左子树
    root -> rightChild = Build(position, str);          //创建右子树
    return root;
}

void InOrder(TreeNode* root) {                          //中序遍历
    if (root == NULL) {
        return;
    }
    InOrder(root->leftChild);
    printf("%c ", root->data);
    InOrder(root->rightChild);
    return ;
}

int main() {
    string str;
    while (cin >> str) {
        int position = 0;                               //标记字符串处理位置
        TreeNode* root = Build(position, str);
        InOrder(root);
        printf("\n");
    }
    return 0;
}
