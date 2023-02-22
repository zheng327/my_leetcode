/*
 * 1588. 所有奇数长度子数组的和
 * 给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。
 * 子数组 定义为原数组中的一个连续子序列。
 * 请你返回 arr 中 所有奇数长度子数组的和 。
 *
 * 示例 1：
 * 输入：arr = [1,4,2,5,3]
 * 输出：58
 * 解释：所有奇数长度子数组和它们的和为：
 * [1] = 1
 * [4] = 4
 * [2] = 2
 * [5] = 5
 * [3] = 3
 * [1,4,2] = 7
 * [4,2,5] = 11
 * [2,5,3] = 10
 * [1,4,2,5,3] = 15
 * 我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
 *
 * 示例 2：
 * 输入：arr = [1,2]
 * 输出：3
 * 解释：总共只有 2 个长度为奇数的子数组，[1] 和 [2]。它们的和为 3 。
 *
 * 示例 3：
 * 输入：arr = [10,11,12]
 * 输出：66
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        int prefixsums[n+1];
        for(int i = 0; i < n; ++i){
            prefixsums[i+1] = prefixsums[i] + arr[i];
        }
        for(int start = 0; start <= n; ++start){
            for(int length = 1; start + length <= n; length += 2){
                sum += prefixsums[start + length] - prefixsums[start];
            }
        }
        return sum;
    }
};

int main() {
    vector<int> example1 = {1,4,2,5,3};
    vector<int> example2 = {1,2};
    vector<int> example3 = {10,11,12};
    Solution solution;
    cout << solution.sumOddLengthSubarrays(example1) << endl;
    cout << solution.sumOddLengthSubarrays(example2) << endl;
    cout << solution.sumOddLengthSubarrays(example3) << endl;
    return 0;
}
