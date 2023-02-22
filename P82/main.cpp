/*
 * 82. 删除排序链表中的重复元素 II
 * 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
 *
 * 示例 1：
 * 输入：head = [1,2,3,3,4,4,5]
 * 输出：[1,2,5]
 *
 * 示例 2：
 * 输入：head = [1,1,1,2,3]
 * 输出：[2,3]
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *nPtr = dummyNode;
        while(nPtr->next && nPtr->next->next){
            if(nPtr->next->val == nPtr->next->next->val){
                int x = nPtr->next->val;
                while(nPtr->next && nPtr->next->val == x)
                    nPtr->next = nPtr->next->next;
            }
            else{
                nPtr = nPtr->next;
            }
        }
        return dummyNode->next;
    }
};

int main() {
    vector<int> example1 = {1,2,3,3,4,4,5};
    vector<int> example2 = {1,1,1,2,3};
    ListNode* l1 = CreatListNode(example1);
    ListNode* l2 = CreatListNode(example2);
    Solution solution;
    ListNode* res1 = solution.deleteDuplicates(l1);
    ListNode* res2 = solution.deleteDuplicates(l2);
    PrintListNode(res1);
    PrintListNode(res2);
    return 0;
}
