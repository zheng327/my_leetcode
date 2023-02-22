/*
 * 56. �ϲ�����
 * ������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi] ������ϲ������ص������䣬������ һ�����ص����������飬��������ǡ�ø��������е��������� ��
 * ʾ�� 1��
 * ���룺intervals = [[1,3],[2,6],[8,10],[15,18]]
 * �����[[1,6],[8,10],[15,18]]
 * ���ͣ����� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
 *
 * ʾ�� 2��
 * ���룺intervals = [[1,4],[4,5]]
 * �����[[1,5]]
 * ���ͣ����� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣
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
