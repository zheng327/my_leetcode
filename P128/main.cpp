/*
 * 128. ���������
 * ����һ��δ������������� nums ���ҳ���������������У���Ҫ������Ԫ����ԭ�������������ĳ��ȡ�
 * ������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣
 *
 * ʾ�� 1��
 * ���룺nums = [100,4,200,1,3,2]
 * �����4
 * ���ͣ���������������� [1, 2, 3, 4]�����ĳ���Ϊ 4��
 *
 * ʾ�� 2��
 * ���룺nums = [0,3,7,2,5,8,4,6,0,1]
 * �����9
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(int num:nums){
            num_set.insert(num);
        }
        int longest = 0;
        for(int num:nums){
            if(num_set.count(num-1) == false){
                int cur_num = num;
                int cur_long = 1;
                while(num_set.count(cur_num+1) == true){
                    cur_num++;
                    cur_long++;
                }
                longest = max(cur_long, longest);
            }
        }
        return longest;
    }
};

int main() {
    vector<int> nums1 = {100,4,200,1,3,2};
    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    Solution solution;
    cout << solution.longestConsecutive(nums1) << endl;
    cout << solution.longestConsecutive(nums2) << endl;
    return 0;
}
