/*
 * 383. 赎金信
 * 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
 * 如果可以，返回 true ；否则返回 false 。
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
 *
 * 示例 1：
 * 输入：ransomNote = "a", magazine = "b"
 * 输出：false
 *
 * 示例 2：
 * 输入：ransomNote = "aa", magazine = "ab"
 * 输出：false
 *
 * 示例 3：
 * 输入：ransomNote = "aa", magazine = "aab"
 * 输出：true
 */
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> hashmap;
        for(char ch:magazine){
            hashmap[ch]++;
        }
        for(char ch:ransomNote){
            if(--hashmap[ch] < 0){
                return false;
            }
        }
        return true;
    }
};

int main() {
    string ransomNote_1 = "a", magazine_1 = "b";
    string ransomNote_2 = "aa", magazine_2 = "ab";
    string ransomNote_3 = "aa", magazine_3 = "aab";
    Solution solution;
    cout << solution.canConstruct(ransomNote_1, magazine_1) << endl;
    cout << solution.canConstruct(ransomNote_2, magazine_2) << endl;
    cout << solution.canConstruct(ransomNote_3, magazine_3) << endl;
    return 0;
}
