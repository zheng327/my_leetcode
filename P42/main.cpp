/*
 * 42. 接雨水
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 * 示例 1：
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 *
 * 示例 2：
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0)
            return 0;
        vector<int> leftMax(n);
        //最左边柱子，其左边的最大高度为它自己
        leftMax[0] = height[0];
        //第i位的柱子左边最大高度
        //为它左边即i-1位的柱子左边的最大高度
        //和第i位柱子中较大的那个
        for(int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i-1], height[i]);
        vector<int> rightMax(n);
        //最右边柱子，其右边的最大高度位它自己
        rightMax[n-1] = height[n-1];
        //第i位的柱子右边最大高度
        //为它右边即i+1位的柱子右边的最大高度
        //和第i位柱子中较大的那个
        for(int i = n-2; i >= 0; i--)
            rightMax[i] = max(rightMax[i+1], height[i]);
        int res = 0;
        //第i位的柱子能接的最大雨水高度
        //为它左右的最高高度中较小的那个
        //减它本身的高度
        for(int i = 0; i < n; i++)
            res += min(leftMax[i], rightMax[i]) - height[i];
        return res;
    }
};

int main() {
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height2 = {4,2,0,3,2,5};
    Solution solution;
    cout << solution.trap(height1) << endl;
    cout << solution.trap(height2) << endl;
    return 0;
}
