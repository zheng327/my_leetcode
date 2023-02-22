/*
 * 226. 翻转二叉树
 * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
 *
 * 示例 1：
 * 输入：root = [4,2,7,1,3,6,9]
 * 输出：[4,7,2,9,6,3,1]
 *
 * 示例 2：
 * 输入：root = [2,1,3]
 * 输出：[2,3,1]
 *
 * 示例 3：
 * 输入：root = []
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

void FloorPrint_QUEUE(TreeNode* Tree) //层序遍历_队列实现
{
    queue < TreeNode* > q;
    if (Tree != NULL)
        q.push(Tree);   //根节点进队列
    while (q.empty() == false)  //队列不为空
    {
        TreeNode* node=q.front();
        cout << node->val << " ";

        if (node->left != NULL)   //如果有左孩子，入队
            q.push(node->left);

        if (node->right != NULL)   //如果有右孩子，入队
            q.push(node->right);
        q.pop();  //已经遍历过的节点出队列
    }
    cout << endl;
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

int main() {
    vector<int> example1 = {4,2,7,1,3,6,9};
    vector<int> example2 = {2,1,3};
    vector<int> example3 = {NULL};
    TreeNode *t1 = BuildTree(example1);
    TreeNode *t2 = BuildTree(example2);
    TreeNode *t3 = BuildTree(example3);
    Solution solution;
    TreeNode *res1 = solution.invertTree(t1);
    TreeNode *res2 = solution.invertTree(t2);
    TreeNode *res3 = solution.invertTree(t3);
    FloorPrint_QUEUE(res1);
    FloorPrint_QUEUE(res2);
    FloorPrint_QUEUE(res3);
    return 0;
}
