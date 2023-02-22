/*
 * 1588. ������������������ĺ�
 * ����һ������������ arr ������������п��ܵ���������������ĺ͡�
 * ������ ����Ϊԭ�����е�һ�����������С�
 * ���㷵�� arr �� ������������������ĺ� ��
 *
 * ʾ�� 1��
 * ���룺arr = [1,4,2,5,3]
 * �����58
 * ���ͣ�����������������������ǵĺ�Ϊ��
 * [1] = 1
 * [4] = 4
 * [2] = 2
 * [5] = 5
 * [3] = 3
 * [1,4,2] = 7
 * [4,2,5] = 11
 * [2,5,3] = 10
 * [1,4,2,5,3] = 15
 * ���ǽ�����ֵ��͵õ� 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
 *
 * ʾ�� 2��
 * ���룺arr = [1,2]
 * �����3
 * ���ͣ��ܹ�ֻ�� 2 ������Ϊ�����������飬[1] �� [2]�����ǵĺ�Ϊ 3 ��
 *
 * ʾ�� 3��
 * ���룺arr = [10,11,12]
 * �����66
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
