/*
 * 53. 最大子数组和
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 子数组 是数组中的一个连续部分。
 *
 * 示例 1：
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 *
 * 示例 2：
 * 输入：nums = [1]
 * 输出：1
 *
 * 示例 3：
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
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
            //第i位处的最大子数组和dp[i]为
            //dp[i-1]+nums[i] 和 nums[i]中较大的那个
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            //若dp[i]大于之前的最大子数组res，则res改为dp[i]
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
