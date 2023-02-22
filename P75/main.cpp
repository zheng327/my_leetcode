/*
 * 75. ��ɫ����
 * ����һ��������ɫ����ɫ����ɫ���� n ��Ԫ�ص����� nums ��ԭ�ض����ǽ�������ʹ����ͬ��ɫ��Ԫ�����ڣ������պ�ɫ����ɫ����ɫ˳�����С�
 * ����ʹ������ 0�� 1 �� 2 �ֱ��ʾ��ɫ����ɫ����ɫ��
 * �����ڲ�ʹ�ÿ����õ� sort ����������½��������⡣
 *
 * ʾ�� 1��
 * ���룺nums = [2,0,2,1,1,0]
 * �����[0,0,1,1,2,2]
 *
 * ʾ�� 2��
 * ���룺nums = [2,0,1]
 * �����[0,1,2]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) {
                swap(nums[i], nums[ptr]);
                ptr++;
            }
        }
        for(int i = ptr; i < nums.size(); i++){
            if(nums[i] == 1){
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
    }
};

int main() {
    vector<int> nums1 = {2,0,2,1,1,0};
    vector<int> nums2 = {2,0,1};
    Solution solution;
    solution.sortColors(nums1);
    solution.sortColors(nums2);
    for(int i:nums1)
        cout << i << " ";
    cout << endl;
    for(int i:nums2)
        cout << i << " ";
    return 0;
}
