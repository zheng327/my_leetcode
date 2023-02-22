/*
 * 387. 字符串中的第一个唯一字符
 * 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
 *
 * 示例 1：
 * 输入: s = "leetcode"
 * 输出: 0
 *
 * 示例 2:
 * 输入: s = "loveleetcode"
 * 输出: 2
 *
 * 示例 3:
 * 输入: s = "aabb"
 * 输出: -1
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
