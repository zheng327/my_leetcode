/*
 * 448. 找到所有数组中消失的数字
 * 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
 *
 * 示例 1：
 * 输入：nums = [4,3,2,7,8,2,3,1]
 * 输出：[5,6]
 *
 * 示例 2：
 * 输入：nums = [1,1]
 * 输出：[2]
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int num:nums){
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(nums[i] <= n){
                res.push_back(i+1);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {4,3,2,7,8,2,3,1};
    vector<int> nums2 = {1,1};
    Solution solution;
    vector<int> res1 = solution.findDisappearedNumbers(nums1);
    vector<int> res2 = solution.findDisappearedNumbers(nums2);
    for(int x:res1){
        cout << x << " ";
    }
    cout << endl;
    for(int x:res2){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
