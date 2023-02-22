/*
 * 103. 二叉树的锯齿形层序遍历
 * 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 *
 * 示例 1：
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[20,9],[15,7]]
 *
 * 示例 2：
 * 输入：root = [1]
 * 输出：[[1]]
 *
 * 示例 3：
 * 输入：root = []
 * 输出：[]
 */

#include <iostream>
#include <queue>
#include <vector>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool order = 0;
        while(!q.empty()){
            deque<int> lev_list;
            int lev_size = q.size();
            for(int i = 0; i < lev_size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(order == 0)
                    lev_list.push_back(node->val);
                else
                    lev_list.push_front(node->val);
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
            res.push_back(vector<int>{lev_list.begin(),lev_list.end()});
            order = !order;
        }
        return res;
    }
};

int main() {
    vector<int> example1 = {3,9,20,NULL,NULL,15,7};
    vector<int> example2 = {1};
    vector<int> example3 = {NULL};
    TreeNode *t1 = BuildTree(example1);
    TreeNode *t2 = BuildTree(example2);
    TreeNode *t3 = BuildTree(example3);
    Solution solution;
    vector<vector<int>> res1 = solution.zigzagLevelOrder(t1);
    vector<vector<int>> res2 = solution.zigzagLevelOrder(t2);
    vector<vector<int>> res3 = solution.zigzagLevelOrder(t3);
    Print_res(res1);
    Print_res(res2);
    Print_res(res3);
    return 0;
}
