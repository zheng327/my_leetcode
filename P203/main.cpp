/*
 * 203. �Ƴ�����Ԫ��
 * ����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
 *
 * ʾ�� 1��
 * ���룺head = [1,2,6,3,4,5,6], val = 6
 * �����[1,2,3,4,5]
 *
 * ʾ�� 2��
 * ���룺head = [], val = 1
 * �����[]
 *
 * ʾ�� 3��
 * ���룺head = [7,7,7,7], val = 7
 * �����[]
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void printListNode()
    {
        cout << val << " ";
        ListNode* head = next;
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

ListNode* createListNode(vector<int> data)
{
    ListNode* head;
    head = new ListNode(data[0]);

    ListNode* tempPtr;
    tempPtr = head;

    for (unsigned int i = 1; i < data.size(); ++i)
    {
        ListNode* tempNode;
        tempNode = new ListNode(data[i]);
        tempPtr->next = tempNode;
        tempPtr = tempPtr->next;
    }
    return head;
}

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        ListNode* curr = prev;
        while(curr->next){
            if(curr->next->val == val){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }
        }
        return prev->next;
    }
};

int main() {
    vector<int> example1 = {1,2,6,3,4,5,6};
    vector<int> example2 = {NULL};
    vector<int> example3 = {7,7,7,7};

    return 0;
}
