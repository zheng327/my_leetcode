/*
 * 290. ���ʹ���
 * ����һ�ֹ��� pattern ��һ���ַ��� s ���ж� s �Ƿ���ѭ��ͬ�Ĺ��ɡ�
 * ����� ��ѭ ָ��ȫƥ�䣬���磬 pattern ���ÿ����ĸ���ַ��� s �е�ÿ���ǿյ���֮�������˫�����ӵĶ�Ӧ���ɡ�
 *
 * ʾ��1:
 * ����: pattern = "abba", s = "dog cat cat dog"
 * ���: true
 *
 * ʾ�� 2:
 * ����:pattern = "abba", s = "dog cat cat fish"
 * ���: false
 *
 * ʾ�� 3:
 * ����: pattern = "aaaa", s = "dog cat cat dog"
 * ���: false
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> str2ch;
        unordered_map<char,string> ch2str;
        int m = s.length();
        int i = 0;
        for(char ch:pattern){
            if(i >= m){
                return false;
            }
            int j = i;
            while(j < m && s[j] != ' '){
                ++j;
            }
            string tmp = s.substr(i, j - i);
            if(str2ch.count(tmp) && str2ch[tmp] != ch){
                return false;
            }
            if(ch2str.count(ch) && ch2str[ch] != tmp){
                return false;
            }
            str2ch[tmp] = ch;
            ch2str[ch] = tmp;
            i = j + 1;
        }
        return i >= m;
    }
};

int main() {
    string pattern1 = "abba", s1 = "dog cat cat dog";
    string pattern2 = "abba", s2 = "dog cat cat fish";
    string pattern3 = "aaaa", s3 = "dog cat cat dog";
    Solution solution;
    cout << solution.wordPattern(pattern1, s1) << endl;
    cout << solution.wordPattern(pattern2, s2) << endl;
    cout << solution.wordPattern(pattern3, s3) << endl;
    return 0;
}
