/*
 * 98. ��֤����������
 * ����һ���������ĸ��ڵ� root ���ж����Ƿ���һ����Ч�Ķ�����������
 * ��Ч �����������������£�
 * �ڵ��������ֻ���� С�� ��ǰ�ڵ������
 * �ڵ��������ֻ���� ���� ��ǰ�ڵ������
 * �������������������������Ҳ�Ƕ�����������
 *
 * ʾ�� 1��
 * ���룺root = [2,1,3]
 * �����true
 *
 * ʾ�� 2��
 * ���룺root = [5,1,4,null,null,3,6]
 * �����false
 * ���ͣ����ڵ��ֵ�� 5 ���������ӽڵ��ֵ�� 4 ��
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

TreeNode* BuildTree(vector<int> array){
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
            if (array[i] != NULL){
                p->left = new TreeNode(array[i]);
                q.push(p->left);
            }
            else
                p->left = nullptr;
        }
        if(++i < array.size()){
            if (array[i] != NULL){
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
    bool isBST(TreeNode* root, long long lower, long long upper){
        if(root == nullptr)
            return true;
        if(root->val <= lower || root->val >= upper)
            return false;
        else
            return isBST(root->left, lower, root->val) && isBST(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};

int main() {
    vector<int> example1 = {2,1,3};
    vector<int> example2 = {5,1,4,NULL,NULL,3,6};
    TreeNode *t1 = BuildTree(example1);
    TreeNode *t2 = BuildTree(example2);
    Solution solution;
    cout << solution.isValidBST(t1) << endl;
    cout << solution.isValidBST(t2) << endl;
    return 0;
}
