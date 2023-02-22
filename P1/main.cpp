/*
 * 1. 两数之和
 * 给定一个整数数组 nums 和一个整数目标值 target，
 * 请你在该数组中找出 和为目标值 target 的那两个整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 *
 * 示例 1：
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 *
 * 示例 2：
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 *
 * 示例 3：
 * 输入：nums = [3,3], target = 6
 * 输出：[0,1]
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //创建一个哈希表
        unordered_map<int, int> hashtable;
        for(int i = 0; i < nums.size(); ++i){
            //寻找与当前数组元素nums[i] 之和为 target 的元素是否存在哈希表中
            auto it = hashtable.find(target - nums[i]);
            if(it != hashtable.end()){
                return {i, it->second};
            }
            //将数组元素加入哈希表
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> example1 = {2, 7, 11, 15};
    vector<int> example2 = {3, 2, 4};
    vector<int> example3 = {3, 3};
    int target1 = 9;
    int target2 = 6;
    int target3 = 6;
    Solution solution;
    vector<int> result1 = solution.twoSum(example1, target1);
    vector<int> result2 = solution.twoSum(example2, target2);
    vector<int> result3 = solution.twoSum(example3, target3);
    std::cout << "result1 = {" << result1[0] << "," << result1[1] << "}" << std::endl;
    std::cout << "result2 = {" << result2[0] << "," << result2[1] << "}" << std::endl;
    std::cout << "result3 = {" << result3[0] << "," << result3[1] << "}" << std::endl;
    return 0;
}