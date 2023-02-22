/*
 * 112. 路径总和
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
 * 叶子节点 是指没有子节点的节点。
 *
 * 示例 1：
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * 输出：true
 * 解释：等于目标和的根节点到叶节点路径如上图所示。
 *
 * 示例 2：
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：false
 * 解释：树中存在两条根节点到叶子节点的路径：
 * (1 --> 2): 和为 3
 * (1 --> 3): 和为 4
 * 不存在 sum = 5 的根节点到叶子节点的路径。
 *
 * 示例 3：
 * 输入：root = [], targetSum = 0
 * 输出：false
 * 解释：由于树是空的，所以不存在根节点到叶子节点的路径。
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
