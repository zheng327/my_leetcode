/*
 * 2. �������
 * �������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
 * ���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
 * ����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
 *
 * ʾ�� 1��
 * ���룺l1 = [2,4,3], l2 = [5,6,4]
 * �����[7,0,8]
 * ���ͣ�342 + 465 = 807.
 *
 * ʾ�� 2��
 * ���룺l1 = [0], l2 = [0]
 * �����[0]
 *
 * ʾ�� 3��
 * ���룺l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * �����[8,9,9,9,0,0,0,1]
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
            //ͬλ������ӣ�����ǰһλ�Ľ�λ
            int sum = x + y + carry;
            //���㵱ǰλ��Ӳ����Ľ�λ
            carry = sum / 10;
            //��������λ��ӣ���newһ���µ�����ڵ��ʾ�����ͣ�����head��tail�ֱ�ָ�������ͷ��β
            if(!head){
                head = tail = new ListNode(sum % 10);
            }
            //����������λ��ӣ���tail->nextָ��һ����ʾ��ǰλ���֮�͵�����ڵ�
            else{
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            //l1����һλ
            if(l1){
                l1 = l1->next;
            }
            //l2����һλ
            if(l2){
                l2 = l2->next;
            }
        }
        //������λ��ӻ��н�λ�����������newһ������ڵ��ʾ���λ
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
