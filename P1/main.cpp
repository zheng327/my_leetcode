/*
 * 1. ����֮��
 * ����һ���������� nums ��һ������Ŀ��ֵ target��
 * �����ڸ��������ҳ� ��ΪĿ��ֵ target �����������������������ǵ������±ꡣ
 * ����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
 * ����԰�����˳�򷵻ش𰸡�
 *
 * ʾ�� 1��
 * ���룺nums = [2,7,11,15], target = 9
 * �����[0,1]
 * ���ͣ���Ϊ nums[0] + nums[1] == 9 ������ [0, 1] ��
 *
 * ʾ�� 2��
 * ���룺nums = [3,2,4], target = 6
 * �����[1,2]
 *
 * ʾ�� 3��
 * ���룺nums = [3,3], target = 6
 * �����[0,1]
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //����һ����ϣ��
        unordered_map<int, int> hashtable;
        for(int i = 0; i < nums.size(); ++i){
            //Ѱ���뵱ǰ����Ԫ��nums[i] ֮��Ϊ target ��Ԫ���Ƿ���ڹ�ϣ����
            auto it = hashtable.find(target - nums[i]);
            if(it != hashtable.end()){
                return {i, it->second};
            }
            //������Ԫ�ؼ����ϣ��
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