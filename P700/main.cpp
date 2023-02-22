/*
 * 700. �����������е�����
 * ����������������BST���ĸ��ڵ� root ��һ������ֵ val��
 * ����Ҫ�� BST ���ҵ��ڵ�ֵ���� val �Ľڵ㡣 �����Ըýڵ�Ϊ���������� ����ڵ㲻���ڣ��򷵻� null ��
 *
 * ʾ�� 1:
 * ���룺root = [4,2,7,1,3], val = 2
 * �����[2,1,3]
 *
 * ʾ�� 2:
 * ���룺root = [4,2,7,1,3], val = 5
 * �����[]
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(val == root->val){
                return root;
            }
            root = root->val < val ? root->right : root->left;
        }
        return nullptr;
    }
};

int main() {
    vector<int> example = {4,2,7,1,3};
    TreeNode *t1 = BuildTree(example);
    TreeNode *t2 = BuildTree(example);
    Solution solution;
    TreeNode *res1 = solution.searchBST(t1, 2);
    TreeNode *res2 = solution.searchBST(t1, 2);
    return 0;
}
