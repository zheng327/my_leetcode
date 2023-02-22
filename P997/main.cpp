/*
 * 997. �ҵ�С��ķ���
 * С������ n ���ˣ����� 1 �� n ��˳���š����Գƣ���Щ������һ����������С�򷨹١�
 * ���С�򷨹���Ĵ��ڣ���ô��
 * С�򷨹ٲ��������κ��ˡ�
 * ÿ���ˣ�����С�򷨹٣���������λС�򷨹١�
 * ֻ��һ����ͬʱ�������� 1 ������ 2 ��
 * ����һ������ trust ������ trust[i] = [ai, bi] ��ʾ���Ϊ ai �������α��Ϊ bi ���ˡ�
 * ���С�򷨹ٴ��ڲ��ҿ���ȷ��������ݣ��뷵�ظ÷��ٵı�ţ����򣬷��� -1 ��
 *
 * ʾ�� 1��
 * ���룺n = 2, trust = [[1,2]]
 * �����2
 *
 * ʾ�� 2��
 * ���룺n = 3, trust = [[1,3],[2,3]]
 * �����3
 *
 * ʾ�� 3��
 * ���룺n = 3, trust = [[1,3],[2,3],[3,1]]
 * �����-1
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegrees(n+1);
        vector<int> outDegrees(n+1);
        for(auto& i : trust){
            ++inDegrees[i[1]];
            ++outDegrees[i[0]];
        }
        for(int i = 1; i <= n; i++){
            if(inDegrees[i] == n - 1 && outDegrees[i] == 0){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> example1 = {{1,2}};
    vector<vector<int>> example2 = {{1,3}, {2,3}};
    vector<vector<int>> example3 = {{1,3}, {2,3}, {3,1}};
    Solution solution;
    cout << solution.findJudge(2, example1) << endl;
    cout << solution.findJudge(3, example2) << endl;
    cout << solution.findJudge(3, example3) << endl;
    return 0;
}
