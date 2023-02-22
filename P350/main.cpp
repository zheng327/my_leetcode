/*
 * 350. ��������Ľ��� II
 * ���������������� nums1 �� nums2 ��������������ʽ����������Ľ��������ؽ����ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������ж����ֵĴ���һ�£�������ִ�����һ�£�����ȡ��Сֵ�������Բ�������������˳��
 * ʾ�� 1��
 * ���룺nums1 = [1,2,2,1], nums2 = [2,2]
 * �����[2,2]
 *
 * ʾ�� 2:
 * ���룺nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * �����[4,9]
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hashmap;
        vector<int> res;
        if(nums1.size() < nums2.size()){
            return intersect(nums2,nums1);
        }
        for(int num:nums1){
            hashmap[num]++;
        }
        for(int num:nums2){
            if(hashmap[num] > 0){
                hashmap[num]--;
                res.push_back(num);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums1_1 = {1,2,2,1}, nums2_1 = {2,2};
    vector<int> nums1_2 = {4,9,5}, nums2_2 = {9,4,9,8,4};
    Solution solution;
    vector<int> res1 = solution.intersect(nums1_1, nums2_1);
    vector<int> res2 = solution.intersect(nums1_2, nums2_2);
    for(int x : res1){
        cout << x << " ";
    }
    cout << endl;
    for(int x : res2){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
