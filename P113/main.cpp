/*
 * 113. 路径总和 II
 * 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
 * 叶子节点 是指没有子节点的节点。
 *
 * 示例 1：
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：[[5,4,11,2],[5,8,4,5]]
 *
 * 示例 2：
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：[]
 *
 * 示例 3：
 * 输入：root = [1,2], targetSum = 0
 * 输出：[]
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

void Print_res(vector<vector<int>> res){
    for(vector<int> i:res){
        for(int j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum){
        if(root == nullptr)
            return;
        path.emplace_back(root->val);
        targetSum -= root->val;
        if(root->left == nullptr && root->right == nullptr && targetSum == 0)
            res.emplace_back(path);
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
};

int main() {
    vector<int> example1 = {5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1};
    vector<int> example2 = {1,2,3};
    vector<int> example3 = {1,2};
    TreeNode *t1 = BuildTree(example1);
    TreeNode *t2 = BuildTree(example2);
    TreeNode *t3 = BuildTree(example3);
    Solution solution1,solution2,solution3;
    vector<vector<int>> res1 = solution1.pathSum(t1, 22);
    vector<vector<int>> res2 = solution2.pathSum(t2, 5);
    vector<vector<int>> res3 = solution3.pathSum(t3, 0);
    Print_res(res1);
    Print_res(res2);
    Print_res(res3);
    return 0;
}
