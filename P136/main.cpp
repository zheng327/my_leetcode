/*
 * 136. ֻ����һ�ε�����
 * ����һ�� �ǿ� �������� nums ������ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
 * �������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨����������⣬�Ҹ��㷨ֻʹ�ó�������ռ䡣
 * ʾ�� 1 ��
 * ���룺nums = [2,2,1]
 * �����1
 *
 * ʾ�� 2 ��
 * ���룺nums = [4,1,2,1,2]
 * �����4
 *
 * ʾ�� 3 ��
 * ���룺nums = [1]
 * �����1
 */


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int num:nums){
            map[num]++;
        }
        for(int num:nums){
            if(map[num] == 1){
                return num;
            }
        }
        return 0;
    }
};

int main() {
    vector<int> example1 = {2,2,1};
    vector<int> example2 = {4,1,2,1,2};
    vector<int> example3 = {1};
    Solution solution;
    int result1 = solution.singleNumber(example1);
    int result2 = solution.singleNumber(example2);
    int result3 = solution.singleNumber(example3);
    std::cout << "result1:" << result1 << std::endl;
    std::cout << "result2:" << result2 << std::endl;
    std::cout << "result3:" << result3 << std::endl;
    return 0;
}
