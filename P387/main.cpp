/*
 * 387. �ַ����еĵ�һ��Ψһ�ַ�
 * ����һ���ַ��� s ���ҵ� ���ĵ�һ�����ظ����ַ����������������� ����������ڣ��򷵻� -1 ��
 *
 * ʾ�� 1��
 * ����: s = "leetcode"
 * ���: 0
 *
 * ʾ�� 2:
 * ����: s = "loveleetcode"
 * ���: 2
 *
 * ʾ�� 3:
 * ����: s = "aabb"
 * ���: -1
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> map;
        map.resize(26);
        for(char ch:s){
            map[ch-'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            if(map[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    string s1 = "leetcode";
    string s2 = "loveleetcode";
    string s3 = "aabb";
    Solution solution;
    cout << solution.firstUniqChar(s1) << endl;
    cout << solution.firstUniqChar(s2) << endl;
    cout << solution.firstUniqChar(s3) << endl;
    return 0;
}
