/*
 * 88. �ϲ�������������
 * ���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��
 * ���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�
 * ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n������ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��
 * ʾ�� 1��
 * ���룺nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * �����[1,2,2,3,5,6]
 * ���ͣ���Ҫ�ϲ� [1,2,3] �� [2,5,6] ��
 * �ϲ������ [1,2,2,3,5,6] ������б��Ӵֱ�ע��Ϊ nums1 �е�Ԫ�ء�
 *
 * ʾ�� 2��
 * ���룺nums1 = [1], m = 1, nums2 = [], n = 0
 * �����[1]
 * ���ͣ���Ҫ�ϲ� [1] �� [] ��
 * �ϲ������ [1] ��
 *
 * ʾ�� 3��
 * ���룺nums1 = [0], m = 0, nums2 = [1], n = 1
 * �����[1]
 * ���ͣ���Ҫ�ϲ��������� [] �� [1] ��
 * �ϲ������ [1] ��
 * ע�⣬��Ϊ m = 0 ������ nums1 ��û��Ԫ�ء�nums1 �н���� 0 ������Ϊ��ȷ���ϲ��������˳����ŵ� nums1 �С�
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n -1;
        int cur;
        while(p1 >= 0 || p2 >= 0){
            if(p2 == -1){
                cur = nums1[p1--];
            }
            else if(p1 == -1){
                cur = nums2[p2--];
            }
            else if(nums1[p1] > nums2[p2]){
                cur = nums1[p1--];
            }
            else{
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};
int main() {
    vector<int> nums1_1 = {1, 2, 3, 0, 0, 0}, nums1_2 ={2, 5, 6};
    int m1 = 3, n1 = 3;
    vector<int> nums2_1 = {1}, nums2_2;
    int m2 = 1, n2 = 0;
    vector<int> nums3_1 = {0}, nums3_2 ={1};
    int m3 = 0, n3 = 1;
    Solution solution;
    solution.merge(nums1_1, m1, nums1_2, n1);
    for(int x:nums1_1){
        cout << x << " ";
    }
    cout << endl;
    solution.merge(nums2_1, m2, nums2_2, n2);
    for(int x:nums2_1){
        cout << x << " ";
    }
    cout << endl;
    solution.merge(nums3_1, m3, nums3_2, n3);
    for(int x:nums3_1){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
