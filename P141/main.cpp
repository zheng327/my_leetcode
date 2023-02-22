/*
 * 141. ��������
 * ����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
 * �����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����
 * ע�⣺pos ����Ϊ�������д��� ��������Ϊ�˱�ʶ�����ʵ�������
 * ��������д��ڻ� ���򷵻� true �� ���򣬷��� false ��
 *
 * ʾ�� 1��
 * ���룺head = [3,2,0,-4], pos = 1
 * �����true
 * ���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣
 *
 * ʾ�� 2��
 * ���룺head = [1,2], pos = 0
 * �����true
 * ���ͣ���������һ��������β�����ӵ���һ���ڵ㡣
 *
 * ʾ�� 3��
 * ���룺head = [1], pos = -1
 * �����false
 * ���ͣ�������û�л���
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
