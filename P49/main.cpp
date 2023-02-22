/*
 * 49. 字母异位词分组
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 * 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
 *
 * 示例 1:
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * 示例 2:
 * 输入: strs = [""]
 * 输出: [[""]]
 *
 * 示例 3:
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(string str:strs){
            string word = str;
            //将字符串进行排序形成源单词word
            sort(word.begin(),word.end());
            //将字母异位词str存入哈希表map[word]
            map[word].push_back(str);
        }
        vector<vector<string>> res;
        //将字母异位词map[i]->second分别存入res[i]
        for(auto i = map.begin(); i != map.end(); i++){
            res.push_back(i->second);
        }
        return res;
    }
};

int main() {
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs2 = {""};
    vector<string> strs3 = {"a"};
    Solution solution;
    vector<vector<string>> res1 = solution.groupAnagrams(strs1);
    vector<vector<string>> res2 = solution.groupAnagrams(strs2);
    vector<vector<string>> res3 = solution.groupAnagrams(strs3);
    for(vector<string> i:res1){
        for(string j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(vector<string> i:res2){
        for(string j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(vector<string> i:res3){
        for(string j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
