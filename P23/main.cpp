/*
 * 23. 合并K个升序链表
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 *
 * 示例 1：
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [1->4->5,1->3->4,2->6]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 *
 * 示例 2：
 * 输入：lists = []
 * 输出：[]
 *
 * 示例 3：
 * 输入：lists = [[]]
 * 输出：[]
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
    //合并两个升序链表
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
        //只要其中一个链表为空，就直接返回另一个链表
        if(!a || !b) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while(aPtr && bPtr){
            //比较两个链表当前节点的值，较小的加入输出链表
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
        //判断两个链表是否都完整遍历
        tail->next = (!aPtr ? bPtr : aPtr);
        return head.next;
    }
    //合并K个升序链表
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = nullptr;
        //将每个输入链表都和输出链表进行合并，就能实现K个链表的合并
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
