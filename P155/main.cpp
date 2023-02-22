/*
 * 155. ��Сջ
 * ���һ��֧�� push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
 * ʵ�� MinStack ��:
 * MinStack() ��ʼ����ջ����
 * void push(int val) ��Ԫ��val�����ջ��
 * void pop() ɾ����ջ������Ԫ�ء�
 * int top() ��ȡ��ջ������Ԫ�ء�
 * int getMin() ��ȡ��ջ�е���СԪ�ء�
 *
 * ʾ�� 1:
 * ���룺
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * �����
 * [null,null,null,null,-3,null,0,-2]
 *
 * ���ͣ�
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> ���� -3.
 * minStack.pop();
 * minStack.top();      --> ���� 0.
 * minStack.getMin();   --> ���� -2.
 */
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<pair<int,int>> st;
public:
    MinStack() {
    }

    void push(int val) {
        if(st.size() == 0)
            st.push({val, val});
        else
            st.push({val, min(val, st.top().second)});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    return 0;
}
