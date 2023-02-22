/*
 * 653. ����֮�� IV - �������������
 * ����һ������������ root ��һ��Ŀ���� k����������������д�������Ԫ�������ǵĺ͵��ڸ�����Ŀ�������򷵻� true��
 *
 * ʾ�� 1��
 * ����: root = [5,3,6,2,4,null,7], k = 9
 * ���: true
 *
 * ʾ�� 2��
 * ����: root = [5,3,6,2,4,null,7], k = 28
 * ���: false
 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
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

class Solution {
public:
    unordered_set<int> hashTable;
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr){
            return false;
        }
        if(hashTable.count(k - root->val)){
            return true;
        }
        hashTable.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};

int main() {
    vector<int> example1 = {5,3,6,2,4,NULL,7};
    vector<int> example2 = {5,3,6,2,4,NULL,7};
    TreeNode *t1 = BuildTree(example1);
    TreeNode *t2 = BuildTree(example2);
    Solution solution;
    cout << solution.findTarget(t1, 9) << endl;
    cout << solution.findTarget(t2, 28) << endl;
    return 0;
}
