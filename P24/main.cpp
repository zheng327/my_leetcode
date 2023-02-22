/*
 * 24. 两两交换链表中的节点
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 *
 * 示例 1：
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 *
 * 示例 2：
 * 输入：head = []
 * 输出：[]
 *
 * 示例 3：
 * 输入：head = [1]
 * 输出：[1]
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
        //哑节点
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *temp = dummyHead;
        //存在两个可交换的节点
        while(temp->next != nullptr && temp->next->next != nullptr){
            //node1和node2分别暂存要交换的两个节点
            ListNode *node1 = temp->next, *node2 = temp->next->next;
            //将temp的next指向node2
            temp->next = node2;
            //将node1的next指向为node2的next
            node1->next = node2->next;
            //将node2的next指向node1
            node2->next = node1;
            //令temp为node1
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
