/*
 * 448. �ҵ�������������ʧ������
 * ����һ���� n ������������ nums ������ nums[i] ������ [1, n] �ڡ������ҳ������� [1, n] ��Χ�ڵ�û�г����� nums �е����֣������������ʽ���ؽ����
 *
 * ʾ�� 1��
 * ���룺nums = [4,3,2,7,8,2,3,1]
 * �����[5,6]
 *
 * ʾ�� 2��
 * ���룺nums = [1,1]
 * �����[2]
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int num:nums){
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(nums[i] <= n){
                res.push_back(i+1);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {4,3,2,7,8,2,3,1};
    vector<int> nums2 = {1,1};
    Solution solution;
    vector<int> res1 = solution.findDisappearedNumbers(nums1);
    vector<int> res2 = solution.findDisappearedNumbers(nums2);
    for(int x:res1){
        cout << x << " ";
    }
    cout << endl;
    for(int x:res2){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
