/*
 * 42. ����ˮ
 * ���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
 *
 * ʾ�� 1��
 * ���룺height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * �����6
 * ���ͣ������������� [0,1,0,2,1,0,1,3,2,1,2,1] ��ʾ�ĸ߶�ͼ������������£����Խ� 6 ����λ����ˮ����ɫ���ֱ�ʾ��ˮ����
 *
 * ʾ�� 2��
 * ���룺height = [4,2,0,3,2,5]
 * �����9
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0)
            return 0;
        vector<int> leftMax(n);
        //��������ӣ�����ߵ����߶�Ϊ���Լ�
        leftMax[0] = height[0];
        //��iλ������������߶�
        //Ϊ����߼�i-1λ��������ߵ����߶�
        //�͵�iλ�����нϴ���Ǹ�
        for(int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i-1], height[i]);
        vector<int> rightMax(n);
        //���ұ����ӣ����ұߵ����߶�λ���Լ�
        rightMax[n-1] = height[n-1];
        //��iλ�������ұ����߶�
        //Ϊ���ұ߼�i+1λ�������ұߵ����߶�
        //�͵�iλ�����нϴ���Ǹ�
        for(int i = n-2; i >= 0; i--)
            rightMax[i] = max(rightMax[i+1], height[i]);
        int res = 0;
        //��iλ�������ܽӵ������ˮ�߶�
        //Ϊ�����ҵ���߸߶��н�С���Ǹ�
        //��������ĸ߶�
        for(int i = 0; i < n; i++)
            res += min(leftMax[i], rightMax[i]) - height[i];
        return res;
    }
};

int main() {
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height2 = {4,2,0,3,2,5};
    Solution solution;
    cout << solution.trap(height1) << endl;
    cout << solution.trap(height2) << endl;
    return 0;
}
