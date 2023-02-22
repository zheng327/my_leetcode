/*
 * 104. ��������������
 * ����һ�����������ҳ��������ȡ�
 * �����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
 * ˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
 *
 * ʾ����
 * ���������� [3,9,20,null,null,15,7]��
 *
    3
   / \
  9  20
    /  \
   15   7
 * �������������� 3 ��
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* BuildTree(vector<int> array)
{
    TreeNode *p,*root;
    queue<TreeNode*> q;
    int i = 0;
    if(array[0] == NULL)
        root = nullptr;
    else{
        root = new TreeNode(array[0]);
        q.push(root);
    }
    while (!q.empty()){
        p = q.front();
        q.pop();
        if(++i < array.size()){
            if (array[i] != NULL)
            {
                p->left = new TreeNode(array[i]);
                q.push(p->left);
            }
            else
                p->left = nullptr;
        }
        if(++i < array.size()){
            if (array[i] != NULL)
            {

                p->right = new TreeNode(array[i]);
                q.push(p->right);
            }
            else
                p->right = nullptr;
        }
    }
    return root;
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {
    vector<int> example1 = {3,9,20,NULL,NULL,15,7};
    TreeNode *root1 = BuildTree(example1);
    Solution solution;
    cout << "ʾ��1��������Ϊ��" << solution.maxDepth(root1) << endl;
    return 0;
}
