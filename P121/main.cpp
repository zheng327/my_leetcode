/*
 * 121. ������Ʊ�����ʱ��
 * ����һ������ prices �����ĵ� i ��Ԫ�� prices[i] ��ʾһ֧������Ʊ�� i ��ļ۸�
 * ��ֻ��ѡ�� ĳһ�� ������ֻ��Ʊ����ѡ���� δ����ĳһ����ͬ������ �����ù�Ʊ�����һ���㷨�����������ܻ�ȡ���������
 * ��������Դ���ʽ����л�ȡ�������������㲻�ܻ�ȡ�κ����󣬷��� 0 ��
 *
 * ʾ�� 1��
 * ���룺[7,1,5,3,6,4]
 * �����5
 * ���ͣ��ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
 * ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�ͬʱ���㲻��������ǰ������Ʊ��
 *
 * ʾ�� 2��
 * ���룺prices = [7,6,4,3,1]
 * �����0
 * ���ͣ������������, û�н������, �����������Ϊ 0��
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = 1e4;
        for(int price:prices){
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(minprice, price);
        }
        return maxprofit;
    }
};

int main() {
    vector<int> example1 = {7,1,5,3,6,4};
    vector<int> example2 = {7,6,4,3,1};
    Solution solution;
    int result1 = solution.maxProfit(example1);
    int result2 = solution.maxProfit(example2);
    std::cout << "result1:" << result1 << std::endl;
    std::cout << "result2:" << result2 << std::endl;
    return 0;
}
