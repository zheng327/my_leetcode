/*
 * 145. 二叉树的后序遍历
 * 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
 *示例 1：
 * 输入：root = [1,null,2,3]
 * 输出：[3,2,1]
 *
 * 示例 2：
 * 输入：root = []
 * 输出：[]
 *
 * 示例 3：
 * 输入：root = [1]
 * 输出：[1]
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
    void postorder(TreeNode* root, vector<int> &res){
        if(root == nullptr){
            return;
        }
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};

int main() {
    vector<int> example1 = {1,NULL,2,3};
    vector<int> example2 = {NULL};
    vector<int> example3 = {1};
    TreeNode *T1 = BuildTree(example1);
    TreeNode *T2 = BuildTree(example2);
    TreeNode *T3 = BuildTree(example3);
    Solution solution;
    vector<int> res1 = solution.postorderTraversal(T1);
    vector<int> res2 = solution.postorderTraversal(T2);
    vector<int> res3 = solution.postorderTraversal(T3);
    Print_res(res1);
    Print_res(res2);
    Print_res(res3);
    return 0;
}
