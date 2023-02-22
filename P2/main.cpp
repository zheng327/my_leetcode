/*
 * 2. 两数相加
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 * 示例 1：
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 *
 * 示例 2：
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 *
 * 示例 3：
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while(l1 || l2){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            //同位的数相加，加上前一位的进位
            int sum = x + y + carry;
            //计算当前位相加产生的进位
            carry = sum / 10;
            //如果是最低位相加，则new一个新的链表节点表示两数和，其中head和tail分别指向链表的头和尾
            if(!head){
                head = tail = new ListNode(sum % 10);
            }
            //如果不是最低位相加，则将tail->next指向一个表示当前位相加之和的链表节点
            else{
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            //l1的下一位
            if(l1){
                l1 = l1->next;
            }
            //l2的下一位
            if(l2){
                l2 = l2->next;
            }
        }
        //如果最高位相加还有进位产生，则继续new一个链表节点表示最高位
        if(carry > 0){
            tail->next = new ListNode(carry);
        }
        return head;
    }
};

int main() {
    vector<int> vector1_1 = {2, 4, 3};
    vector<int> vector1_2 = {5, 6, 4};
    ListNode* example1_l1 = createListNode(vector1_1);
    ListNode* example1_l2 = createListNode(vector1_2);
    vector<int> vector2_1 = {0};
    vector<int> vector2_2 = {0};
    ListNode* example2_l1 = createListNode(vector2_1);
    ListNode* example2_l2 = createListNode(vector2_2);
    vector<int> vector3_1(7, 9);
    vector<int> vector3_2(4, 9);
    ListNode* example3_l1 = createListNode(vector3_1);
    ListNode* example3_l2 = createListNode(vector3_2);
    Solution solution;
    solution.addTwoNumbers(example1_l1, example1_l2)->printListNode();
    solution.addTwoNumbers(example2_l1, example2_l2)->printListNode();
    solution.addTwoNumbers(example3_l1, example3_l2)->printListNode();
    return 0;
}
