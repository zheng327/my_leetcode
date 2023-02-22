/*
 * 53. ����������
 * ����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
 * ������ �������е�һ���������֡�
 *
 * ʾ�� 1��
 * ���룺nums = [-2,1,-3,4,-1,2,1,-5,4]
 * �����6
 * ���ͣ����������� [4,-1,2,1] �ĺ����Ϊ 6 ��
 *
 * ʾ�� 2��
 * ���룺nums = [1]
 * �����1
 *
 * ʾ�� 3��
 * ���룺nums = [5,4,-1,7,8]
 * �����23
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1; i < nums.size(); i++){
            //��iλ��������������dp[i]Ϊ
            //dp[i-1]+nums[i] �� nums[i]�нϴ���Ǹ�
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            //��dp[i]����֮ǰ�����������res����res��Ϊdp[i]
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums2 = {1};
    vector<int> nums3 = {5,4,-1,7,8};
    Solution solution;
    cout << solution.maxSubArray(nums1) << endl;
    cout << solution.maxSubArray(nums2) << endl;
    cout << solution.maxSubArray(nums3) << endl;
    return 0;
}
