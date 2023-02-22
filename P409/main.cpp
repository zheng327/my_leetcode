/*
 * 409. ����Ĵ�
 * ����һ��������д��ĸ��Сд��ĸ���ַ��� s ������ ͨ����Щ��ĸ����ɵ� ��Ļ��Ĵ� ��
 * �ڹ�������У���ע�� ���ִ�Сд ������ "Aa" ���ܵ���һ�������ַ�����
 *
 * ʾ�� 1:
 * ����:s = "abccccdd"
 * ���:7
 * ����:���ǿ��Թ������Ļ��Ĵ���"dccaccd", ���ĳ����� 7��
 *
 * ʾ�� 2:
 * ����:s = "a"
 * ����:1
 *
 * ʾ�� 3��
 * ����:s = "aaaaaccc"
 * ����:7
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        int sum = 0;
        for(char ch:s){
            if(++map[ch] == 2){
                sum += 2;
                map[ch] = 0;
            }
        }
        for(char ch = 'A'; ch <= 'z'; ch++){
            if(map[ch] == 1){
                return sum + 1;
            }
        }
        return sum;
    }
};
int main() {
    string s1 = "abccccdd";
    string s2 = "a";
    string s3 = "aaaaaccc";
    Solution solution;
    cout << solution.longestPalindrome(s1) << endl;
    cout << solution.longestPalindrome(s2) << endl;
    cout << solution.longestPalindrome(s3) << endl;
    return 0;
}
