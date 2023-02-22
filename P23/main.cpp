/*
 * 23. �ϲ�K����������
 * ����һ���������飬ÿ�������Ѿ����������С�
 * ���㽫��������ϲ���һ�����������У����غϲ��������
 *
 * ʾ�� 1��
 * ���룺lists = [[1,4,5],[1,3,4],[2,6]]
 * �����[1,1,2,3,4,4,5,6]
 * ���ͣ������������£�
 * [1->4->5,1->3->4,2->6]
 * �����Ǻϲ���һ�����������еõ���
 * 1->1->2->3->4->4->5->6
 *
 * ʾ�� 2��
 * ���룺lists = []
 * �����[]
 *
 * ʾ�� 3��
 * ���룺lists = [[]]
 * �����[]
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
    //�ϲ�������������
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
        //ֻҪ����һ������Ϊ�գ���ֱ�ӷ�����һ������
        if(!a || !b) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while(aPtr && bPtr){
            //�Ƚ���������ǰ�ڵ��ֵ����С�ļ����������
            if(aPtr->val > bPtr->val){
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            else{
                tail->next = aPtr;
                aPtr = aPtr->next;
            }
            tail = tail->next;
        }
        //�ж����������Ƿ���������
        tail->next = (!aPtr ? bPtr : aPtr);
        return head.next;
    }
    //�ϲ�K����������
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = nullptr;
        //��ÿ���������������������кϲ�������ʵ��K������ĺϲ�
        for(int i = 0; i < lists.size(); i++){
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }
};

int main() {
    vector<int> example1_1 = {1, 4, 5}, example1_2 = {1, 3, 4}, example1_3 = {2, 6};
    ListNode *l1_1 = createListNode(example1_1), *l1_2 = createListNode(example1_2), *l1_3 = createListNode(example1_1);
    ListNode *l3 = nullptr;
    vector<ListNode*> lists1 = {l1_1, l1_2, l1_3};
    vector<ListNode*> lists2 = {};
    vector<ListNode*> lists3 = {l3};
    Solution solution;
    solution.mergeKLists(lists1)->printListNode();
    //solution.mergeKLists(lists2)->printListNode();
    //solution.mergeKLists(lists3)->printListNode();
    return 0;
}
