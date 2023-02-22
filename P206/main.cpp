/*
 * 206. ��ת����
 * ���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
 *
 * ʾ�� 1��
 * ���룺head = [1,2,3,4,5]
 * �����[5,4,3,2,1]
 *
 * ʾ�� 2��
 * ���룺head = [1,2]
 * �����[2,1]
 *
 * ʾ�� 3��
 * ���룺head = []
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main() {
    vector<int> example1 = {1,2,3,4,5};
    vector<int> example2 = {1,2};
    vector<int> example3 = {NULL};
    ListNode *l1 = createListNode(example1);
    ListNode *l2 = createListNode(example2);
    ListNode *l3 = createListNode(example3);
    Solution solution;
    ListNode *res1 = solution.reverseList(l1);
    ListNode *res2 = solution.reverseList(l2);
    ListNode *res3 = solution.reverseList(l3);
    res1->printListNode();
    res2->printListNode();
    res3->printListNode();
    return 0;
}
