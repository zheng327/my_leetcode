/*
 * 15. ����֮��
 * ����һ���������� nums ���ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] ���� i != j��i != k �� j != k ��
 * ͬʱ������ nums[i] + nums[j] + nums[k] == 0 ��
 * ���㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣
 * ע�⣺���в����԰����ظ�����Ԫ�顣
 *
 * ʾ�� 1��
 * ���룺nums = [-1,0,1,2,-1,-4]
 * �����[[-1,-1,2],[-1,0,1]]
 * ���ͣ�
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 ��
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 ��
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 ��
 * ��ͬ����Ԫ���� [-1,0,1] �� [-1,-1,2] ��
 * ע�⣬�����˳�����Ԫ���˳�򲢲���Ҫ��
 *
 * ʾ�� 2��
 * ���룺nums = [0,1,1]
 * �����[]
 * ���ͣ�Ψһ���ܵ���Ԫ��Ͳ�Ϊ 0 ��
 *
 * ʾ�� 3��
 * ���룺nums = [0,0,0]
 * �����[[0,0,0]]
 * ���ͣ�Ψһ���ܵ���Ԫ���Ϊ 0 ��
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        //���������������
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                return ans;
            }
            //�����i��Ԫ�����i-1��Ԫ����ͬ��������i��Ԫ��
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            //��Ԫ��ĵڶ����͵�����Ԫ�ش�����ĵ�i+1����n-1��ȡ��
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                //�����͹����ұ߽�����
                if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }
                //�����͹�С����߽�����
                else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }
                else{
                    //������Ϊ0��������Ԫ��������������
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    //����Ѱ�����������Ҳ��ظ��ĺ���λԪ��
                    left++;
                    right--;
                    while(left < right && nums[right] == nums[right+1]){
                        right--;
                    }
                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};

void print_res(vector<vector<int>>& res)
{
    if(!res[0].size())
        cout << "[]" << endl;
    else
    {
        cout << "[";
        for(int i = 0; i < res.size(); i++){
            cout << "[";
            for(int j = 0; j < res[i].size(); j++){
                if(j < res[i].size() - 1)
                    cout << res[i][j] << ",";
                else
                    cout << res[i][j] << "]";
            }
            if(i < res.size() - 1)
                cout << ",";
            else
                cout << "]" << endl;
        }
    }
}

int main() {
    vector<int> example1 = {-1, 0, 1, 2, -1, -4};
    vector<int> example2 = {0, 1, 1};
    vector<int> example3 = {0, 0, 0};
    Solution solution;
    vector<vector<int>> result1 = solution.threeSum(example1);
    vector<vector<int>> result2 = solution.threeSum(example2);
    vector<vector<int>> result3 = solution.threeSum(example3);
    print_res(result1);
    //print_res(result2);
    //print_res(result3);
    return 0;
}
