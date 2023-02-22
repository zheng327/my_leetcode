/*
 * 101. �Գƶ�����
 * ����һ���������ĸ��ڵ� root �� ������Ƿ���Գơ�
 *
 * ʾ�� 1��
 * ���룺root = [1,2,2,3,4,4,3]
 * �����true
 *
 * ʾ�� 2��
 * ���룺root = [1,2,2,null,3,null,3]
 * �����false
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
    bool check(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr){
            return true;
        }
        else if(p == nullptr || q == nullptr){
            return false;
        }
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

int main() {
    vector<int> example1 = {1,2,2,3,4,4,3};
    vector<int> example2 = {1,2,2,NULL,3,NULL,3};
    TreeNode *root1 = BuildTree(example1);
    TreeNode *root2 = BuildTree(example2);
    Solution solution;
    cout << "result1 : " << solution.isSymmetric(root1) << endl;
    cout << "result2 : " << solution.isSymmetric(root2) << endl;
    return 0;
}
