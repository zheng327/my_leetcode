/*
 * 83. ɾ�����������е��ظ�Ԫ��
 * ����һ��������������ͷ head �� ɾ�������ظ���Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�� ������ ����������� ��
 * ʾ�� 1��
 * ���룺head = [1,1,2]
 * �����[1,2]
 *
 * ʾ�� 2��
 * ���룺head = [1,1,2,3,3]
 * �����[1,2,3]
*/
#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* cur = head;
        while(cur->next != nullptr){
            if(cur->val == cur->next->val){
                cur->next = cur->next->next;
            }
            else{
                cur = cur->next;
            }
        }
        return head;
    }
};
int main() {
    vector<int> example1 = {1, 1, 2}, example2 = {1, 1, 2, 3, 3};
    ListNode* l1 = createListNode(example1);
    ListNode* l2 = createListNode(example2);
    Solution solution;
    solution.deleteDuplicates(l1)->printListNode();
    solution.deleteDuplicates(l2)->printListNode();
    return 0;
}
