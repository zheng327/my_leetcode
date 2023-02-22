/*
 * 226. ��ת������
 * ����һ�ö������ĸ��ڵ� root ����ת��ö�����������������ڵ㡣
 *
 * ʾ�� 1��
 * ���룺root = [4,2,7,1,3,6,9]
 * �����[4,7,2,9,6,3,1]
 *
 * ʾ�� 2��
 * ���룺root = [2,1,3]
 * �����[2,3,1]
 *
 * ʾ�� 3��
 * ���룺root = []
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

void FloorPrint_QUEUE(TreeNode* Tree) //�������_����ʵ��
{
    queue < TreeNode* > q;
    if (Tree != NULL)
        q.push(Tree);   //���ڵ������
    while (q.empty() == false)  //���в�Ϊ��
    {
        TreeNode* node=q.front();
        cout << node->val << " ";

        if (node->left != NULL)   //��������ӣ����
            q.push(node->left);

        if (node->right != NULL)   //������Һ��ӣ����
            q.push(node->right);
        q.pop();  //�Ѿ��������Ľڵ������
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
