/*
 * 21. 合并两个有序链表
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 *
 * 示例 1：
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 *
 * 示例 2：
 * 输入：l1 = [], l2 = []
 * 输出：[]
 *
 * 示例 3：
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //哑节点
        ListNode* preHead = new ListNode(-1);
        ListNode* prev = preHead;
        while(list1 != nullptr && list2 != nullptr){
            //比较list1和list2当前节点的值，较小的加入到输出链表
            if(list1->val < list2->val){
                prev->next = list1;
                list1 = list1->next;
            }
            else{
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        //当其中一个链表的节点遍历完后，判断另一个链表节点是否完整遍历
        prev->next = list1 == nullptr ? list2 : list1;
        return preHead->next;
    }
};
int main() {
    vector<int> example1_1 = {1, 2, 4}, example1_2 = {1, 3, 4};
    vector<int> example2_1, example2_2;
    vector<int> example3_1, example3_2 = {0};
    ListNode* l1_1 = createListNode(example1_1);
    ListNode* l1_2 = createListNode(example1_2);
    ListNode* l2_1 = nullptr;
    ListNode* l2_2 = nullptr;
    ListNode* l3_1 = nullptr;
    ListNode* l3_2 = createListNode(example3_2);
    Solution solution;
    ListNode* result1 = solution.mergeTwoLists(l1_1, l1_2);
    ListNode* result2 = solution.mergeTwoLists(l2_1, l2_2);
    ListNode* result3 = solution.mergeTwoLists(l3_1, l3_2);
    result1->printListNode();
    result2->printListNode();
    result3->printListNode();
    return 0;
}
