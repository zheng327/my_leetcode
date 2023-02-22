/*
 * 144. 二叉树的前序遍历
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 *
 * 示例 1：
 * 输入：root = [1,null,2,3]
 * 输出：[1,2,3]
 *
 * 示例 2：
 * 输入：root = []
 * 输出：[]
 *
 * 示例 3：
 * 输入：root = [1]
 * 输出：[1]
 *
 * 示例 4：
 * 输入：root = [1,2]
 * 输出：[1,2]
 *
 * 示例 5：
 * 输入：root = [1,null,2]
 * 输出：[1,2]
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

void Print_res(vector<int> res){
    for(int x:res){
        cout << x << " ";
    }
    cout << endl;
}

class Solution {
public:
    void preorder(TreeNode* root, vector<int> &res){
        if(root == nullptr){
            return;
        }
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};

int main() {
    vector<int> example1 = {1,NULL,2,3};
    vector<int> example2 = {NULL};
    vector<int> example3 = {1};
    vector<int> example4 = {1,2};
    vector<int> example5 = {1,NULL,2};
    TreeNode *T1 = BuildTree(example1);
    TreeNode *T2 = BuildTree(example2);
    TreeNode *T3 = BuildTree(example3);
    TreeNode *T4 = BuildTree(example4);
    TreeNode *T5 = BuildTree(example5);
    Solution solution;
    vector<int> result1 = solution.preorderTraversal(T1);
    vector<int> result2 = solution.preorderTraversal(T2);
    vector<int> result3 = solution.preorderTraversal(T3);
    vector<int> result4 = solution.preorderTraversal(T4);
    vector<int> result5 = solution.preorderTraversal(T5);
    Print_res(result1);
    Print_res(result2);
    Print_res(result3);
    Print_res(result4);
    Print_res(result5);
    return 0;
}
