/*
 * 242. ��Ч����ĸ��λ��
 * ���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�
 * ע�⣺�� s �� t ��ÿ���ַ����ֵĴ�������ͬ����� s �� t ��Ϊ��ĸ��λ�ʡ�
 *
 * ʾ�� 1:
 * ����: s = "anagram", t = "nagaram"
 * ���: true
 *
 * ʾ�� 2:
 * ����: s = "rat", t = "car"
 * ���: false
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> counts_s,counts_t;
        for(char c:s){
            counts_s[c]++;
        }
        for(char c:t){
            counts_t[c]++;
        }
        if(counts_s == counts_t){
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
    string s1 = "anagram", t1 = "nagaram";
    string s2 = "rat", t2 = "car";
    Solution solution;
    cout << solution.isAnagram(s1, t1) << endl;
    cout << solution.isAnagram(s2, t2) << endl;
    return 0;
}
