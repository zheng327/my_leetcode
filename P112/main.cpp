/*
 * 112. ·���ܺ�
 * ����������ĸ��ڵ� root ��һ����ʾĿ��͵����� targetSum ���жϸ������Ƿ���� ���ڵ㵽Ҷ�ӽڵ� ��·��������·�������нڵ�ֵ��ӵ���Ŀ��� targetSum ��������ڣ����� true �����򣬷��� false ��
 * Ҷ�ӽڵ� ��ָû���ӽڵ�Ľڵ㡣
 *
 * ʾ�� 1��
 * ���룺root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * �����true
 * ���ͣ�����Ŀ��͵ĸ��ڵ㵽Ҷ�ڵ�·������ͼ��ʾ��
 *
 * ʾ�� 2��
 * ���룺root = [1,2,3], targetSum = 5
 * �����false
 * ���ͣ����д����������ڵ㵽Ҷ�ӽڵ��·����
 * (1 --> 2): ��Ϊ 3
 * (1 --> 3): ��Ϊ 4
 * ������ sum = 5 �ĸ��ڵ㵽Ҷ�ӽڵ��·����
 *
 * ʾ�� 3��
 * ���룺root = [], targetSum = 0
 * �����false
 * ���ͣ��������ǿյģ����Բ����ڸ��ڵ㵽Ҷ�ӽڵ��·����
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        queue<TreeNode*> que_node;
        queue<int> que_val;
        que_node.push(root);
        que_val.push(root->val);
        while(!que_node.empty()){
            TreeNode* now = que_node.front();
            int temp = que_val.front();
            que_node.pop();
            que_val.pop();
            if(now->left == nullptr && now->right == nullptr){
                if(temp == targetSum){
                    return true;
                }
            }
            if(now->left != nullptr){
                que_node.push(now->left);
                que_val.push(now->left->val + temp);
            }
            if(now->right != nullptr){
                que_node.push(now->right);
                que_val.push(now->right->val + temp);
            }
        }
        return false;
    }
};

int main() {
    vector<int> example1 = {5,4,8,11,NULL,13,4,7,2,NULL,NULL,NULL,1};
    vector<int> example2 = {1,2,3};
    vector<int> example3 = {NULL};
    TreeNode *root1 = BuildTree(example1); int targetSum1 = 22;
    TreeNode *root2 = BuildTree(example2); int targetSum2 = 5;
    TreeNode *root3 = BuildTree(example3); int targetSum3 = 0;
    Solution solution;

    std::cout << "result1:" << solution.hasPathSum(root1, targetSum1) << std::endl;
    std::cout << "result2:" << solution.hasPathSum(root2, targetSum2) << std::endl;
    std::cout << "result3:" << solution.hasPathSum(root3, targetSum3) << std::endl;
    return 0;
}
