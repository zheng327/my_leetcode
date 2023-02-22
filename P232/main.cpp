/*
 * 232. ��ջʵ�ֶ���
 * �����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
 * ʵ�� MyQueue �ࣺ
 * void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
 * int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
 * int peek() ���ض��п�ͷ��Ԫ��
 * boolean empty() �������Ϊ�գ����� true �����򣬷��� false
 *
 * ˵����
 * �� ֻ�� ʹ�ñ�׼��ջ���� ���� Ҳ����ֻ�� push to top, peek/pop from top, size, �� is empty �����ǺϷ��ġ�
 * ����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
 *
 * ʾ�� 1��
 * ���룺
 * ["MyQueue", "push", "push", "peek", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * �����
 * [null, null, null, 1, 1, false]
 * ���ͣ�
 * MyQueue myQueue = new MyQueue();
 * myQueue.push(1); // queue is: [1]
 * myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
 * myQueue.peek(); // return 1
 * myQueue.pop(); // return 1, queue is [2]
 * myQueue.empty(); // return false
 */
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> instack,outstack;

    void in2out(){
        while(!instack.empty()){
            outstack.push(instack.top());
            instack.pop();
        }
    }

public:
    MyQueue() {

    }

    void push(int x) {
        instack.push(x);
    }

    int pop() {
        if(outstack.empty()){
            in2out();
        }
        int x = outstack.top();
        outstack.pop();
        return x;
    }

    int peek() {
        if(outstack.empty()){
            in2out();
        }
        return outstack.top();
    }

    bool empty() {
        return instack.empty() && outstack.empty();
    }
};

int main() {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    cout << myQueue.peek() << " ";
    cout << myQueue.pop() << " ";
    cout << myQueue.empty() << endl;
    return 0;
}
