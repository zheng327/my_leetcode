/*
 * 94. ���������������
 * ����һ���������ĸ��ڵ� root ������ ���� ���� ���� ��
 *
 * ʾ�� 1��
 * ���룺root = [1,null,2,3]
 * �����[1,3,2]
 *
 * ʾ�� 2��
 * ���룺root = []
 * �����[]
 *
 * ʾ�� 3��
 * ���룺root = [1]
 * �����[1]
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

TreeNode* buildtree(vector<int> array)
{
    TreeNode *p,*root;
    queue<TreeNode*> q;
    int i = 0;
    if(array[0] == NULL)
    {
        root = nullptr;
    }
    else
    {
        root = new TreeNode(array[0]);
        q.push(root);
    }
    while (!q.empty())//������в�Ϊ�վ�ѭ��
    {
        p = q.front();//����ͷ
        q.pop();
        if(++i < array.size())
        {
            if (array[i] != NULL)
            {//��Ϊ�գ�˵�������ӣ������
                p->left = new TreeNode(array[i]);
                q.push(p->left);
            }
            else
            {
                p->left = nullptr;//Ϊ�վͲ����
            }
        }
        if(++i < array.size())
        {
            if (array[i] != NULL)
            {//ͬ���Һ���

                p->right = new TreeNode(array[i]);
                q.push(p->right);
            }
            else
            {
                p->right = nullptr;
            }
        }
    }
    return root;
}

class Solution {
public:
    void inorder(TreeNode* root,vector<int>& res){
        if(root == nullptr){
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};

int main() {
    vector<int> example1 = {1, NULL, 2, 3};
    vector<int> example2 = {NULL};
    vector<int> example3 = {1};
    TreeNode* root1 = buildtree(example1);
    TreeNode* root2 = buildtree(example2);
    TreeNode* root3 = buildtree(example3);
    vector<int> result1,result2,result3;
    Solution solution;
    result1 = solution.inorderTraversal(root1);
    result2 = solution.inorderTraversal(root2);
    result3 = solution.inorderTraversal(root3);
    for(int x:result1){
        cout << x << " ";
    }
    cout << endl;
    for(int x:result2){
        cout << x << " ";
    }
    cout << endl;
    for(int x:result3){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
