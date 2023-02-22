/*
 * 24. �������������еĽڵ�
 * ����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣������ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻������
 *
 * ʾ�� 1��
 * ���룺head = [1,2,3,4]
 * �����[2,1,4,3]
 *
 * ʾ�� 2��
 * ���룺head = []
 * �����[]
 *
 * ʾ�� 3��
 * ���룺head = [1]
 * �����[1]
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
};

ListNode* CreatListNode(vector<int> data) {
    if(data[0] == NULL){
        return nullptr;
    }
    ListNode *head = new ListNode(data[0]);
    ListNode *tempPtr = head;
    for(int i = 1; i < data.size(); i++){
        ListNode *tempNode = new ListNode(data[i]);
        tempPtr->next = tempNode;
        tempPtr = tempPtr->next;
    }
    return head;
}

void PrintListNode(ListNode* head){
    ListNode *temp = head;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        //�ƽڵ�
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *temp = dummyHead;
        //���������ɽ����Ľڵ�
        while(temp->next != nullptr && temp->next->next != nullptr){
            //node1��node2�ֱ��ݴ�Ҫ�����������ڵ�
            ListNode *node1 = temp->next, *node2 = temp->next->next;
            //��temp��nextָ��node2
            temp->next = node2;
            //��node1��nextָ��Ϊnode2��next
            node1->next = node2->next;
            //��node2��nextָ��node1
            node2->next = node1;
            //��tempΪnode1
            temp = node1;
        }
        return dummyHead->next;
    }
};

int main() {
    vector<int> example1 = {1,2,3,4};
    vector<int> example2 = {NULL};
    vector<int> example3 = {1};
    ListNode *l1 = CreatListNode(example1);
    ListNode *l2 = CreatListNode(example2);
    ListNode *l3 = CreatListNode(example3);
    Solution solution;
    ListNode *res1 = solution.swapPairs(l1);
    ListNode *res2 = solution.swapPairs(l2);
    ListNode *res3 = solution.swapPairs(l3);
    PrintListNode(res1);
    PrintListNode(res2);
    PrintListNode(res3);
    return 0;
}
