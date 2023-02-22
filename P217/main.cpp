/*
 * 217. �����ظ�Ԫ��
 * ����һ���������� nums �������һֵ�������г��� �������� ������ true �����������ÿ��Ԫ�ػ�����ͬ������ false ��
 *
 * ʾ�� 1��
 * ���룺nums = [1,2,3,1]
 * �����true
 *
 * ʾ�� 2��
 * ���룺nums = [1,2,3,4]
 * �����false
 *
 * ʾ�� 3��
 * ���룺nums = [1,1,1,3,3,4,3,2,4,2]
 * �����true
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
