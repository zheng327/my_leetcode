/*
 * 56. 合并区间
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 * 示例 1：
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 *
 * 示例 2：
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(vector<int> i:intervals){
            int l_val = i[0], r_val = i[1];
            if(res.empty() || res.back()[1] < l_val)
                res.push_back({l_val, r_val});
            else
                res.back()[1] = max(r_val, res.back()[1]);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> intervals2 = {{1,4},{4,5}};
    Solution solution;
    vector<vector<int>> res1 = solution.merge(intervals1);
    vector<vector<int>> res2 = solution.merge(intervals2);
    for(vector<int> i:res1){
        for(int j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    for(vector<int> i:res2){
        for(int j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
