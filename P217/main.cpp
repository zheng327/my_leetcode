/*
 * 217. 存在重复元素
 * 给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
 *
 * 示例 1：
 * 输入：nums = [1,2,3,1]
 * 输出：true
 *
 * 示例 2：
 * 输入：nums = [1,2,3,4]
 * 输出：false
 *
 * 示例 3：
 * 输入：nums = [1,1,1,3,3,4,3,2,4,2]
 * 输出：true
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int num:nums){
            if(s.find(num) != s.end()){
                return true;
            }
            s.insert(num);
        }
        return false;
    }
};

int main() {
    vector<int> example1 = {1,2,3,1};
    vector<int> example2 = {1,2,3,4};
    vector<int> example3 = {1,1,1,3,3,4,3,2,4,2};
    Solution solution;
    cout << "result1:" << solution.containsDuplicate(example1) << endl;
    cout << "result2:" << solution.containsDuplicate(example2) << endl;
    cout << "result3:" << solution.containsDuplicate(example3) << endl;
    return 0;
}
