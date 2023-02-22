/*
 * 15. 三数之和
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
 * 同时还满足 nums[i] + nums[j] + nums[k] == 0 。
 * 请你返回所有和为 0 且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 *
 * 示例 1：
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 解释：
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
 * 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 * 注意，输出的顺序和三元组的顺序并不重要。
 *
 * 示例 2：
 * 输入：nums = [0,1,1]
 * 输出：[]
 * 解释：唯一可能的三元组和不为 0 。
 *
 * 示例 3：
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * 解释：唯一可能的三元组和为 0 。
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        //将无序的数组排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                return ans;
            }
            //如果第i个元素与第i-1个元素相同则跳过第i个元素
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            //三元组的第二个和第三个元素从数组的第i+1到第n-1中取得
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                //三数和过大，右边界收缩
                if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }
                //三数和过小，左边界收缩
                else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }
                else{
                    //三数和为0，将该三元组存入输出数组中
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    //继续寻找满足条件且不重复的后两位元素
                    left++;
                    right--;
                    while(left < right && nums[right] == nums[right+1]){
                        right--;
                    }
                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};

void print_res(vector<vector<int>>& res)
{
    if(!res[0].size())
        cout << "[]" << endl;
    else
    {
        cout << "[";
        for(int i = 0; i < res.size(); i++){
            cout << "[";
            for(int j = 0; j < res[i].size(); j++){
                if(j < res[i].size() - 1)
                    cout << res[i][j] << ",";
                else
                    cout << res[i][j] << "]";
            }
            if(i < res.size() - 1)
                cout << ",";
            else
                cout << "]" << endl;
        }
    }
}

int main() {
    vector<int> example1 = {-1, 0, 1, 2, -1, -4};
    vector<int> example2 = {0, 1, 1};
    vector<int> example3 = {0, 0, 0};
    Solution solution;
    vector<vector<int>> result1 = solution.threeSum(example1);
    vector<vector<int>> result2 = solution.threeSum(example2);
    vector<vector<int>> result3 = solution.threeSum(example3);
    print_res(result1);
    //print_res(result2);
    //print_res(result3);
    return 0;
}
