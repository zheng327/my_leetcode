/*
 * 141. 环形链表
 * 给你一个链表的头节点 head ，判断链表中是否有环。
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
 * 注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
 * 如果链表中存在环 ，则返回 true 。 否则，返回 false 。
 *
 * 示例 1：
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 *
 * 示例 2：
 * 输入：head = [1,2], pos = 0
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 *
 * 示例 3：
 * 输入：head = [1], pos = -1
 * 输出：false
 * 解释：链表中没有环。
 */
#include <iostream>
#include <vector>
#include <unordered_set>
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

ListNode* createListNode(vector<int> data, int pos)
{
    ListNode* head;
    head = new ListNode(data[0]);

    ListNode* tempPtr;
    ListNode* posPtr = nullptr;
    tempPtr = head;

    for (unsigned int i = 1; i < data.size(); ++i)
    {
        ListNode* tempNode;
        tempNode = new ListNode(data[i]);
        if(i == pos){
            posPtr = tempNode;
        }
        tempPtr->next = tempNode;
        tempPtr = tempPtr->next;
    }
    if(pos == 0)
        tempPtr->next = head;
    else if(pos != -1 && pos < data.size())
        tempPtr->next = posPtr;
    return head;
}

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        while(head != nullptr){
            if(seen.count(head)){
                return true;
            }
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};

int main() {
    vector<int> example1 = {3,2,0,-4};
    vector<int> example2 = {1,2};
    vector<int> example3 = {1};
    ListNode *list1 = createListNode(example1, 1);
    ListNode *list2 = createListNode(example2, 0);
    ListNode *list3 = createListNode(example3, -1);
    //list1->next->next->next->next = list1->next;
    //list2->next->next = list2->next;

    Solution solution;
    cout << "result1:" << solution.hasCycle(list1) << endl;
    cout << "result2:" << solution.hasCycle(list2) << endl;
    cout << "result3:" << solution.hasCycle(list3) << endl;
    return 0;
}
