/*
 * 49. ��ĸ��λ�ʷ���
 * ����һ���ַ������飬���㽫 ��ĸ��λ�� �����һ�𡣿��԰�����˳�򷵻ؽ���б�
 * ��ĸ��λ�� ������������Դ���ʵ���ĸ�õ���һ���µ��ʣ�����Դ�����е���ĸͨ��ǡ��ֻ��һ�Ρ�
 *
 * ʾ�� 1:
 * ����: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * ���: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * ʾ�� 2:
 * ����: strs = [""]
 * ���: [[""]]
 *
 * ʾ�� 3:
 * ����: strs = ["a"]
 * ���: [["a"]]
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
            //���ַ������������γ�Դ����word
            sort(word.begin(),word.end());
            //����ĸ��λ��str�����ϣ��map[word]
            map[word].push_back(str);
        }
        vector<vector<string>> res;
        //����ĸ��λ��map[i]->second�ֱ����res[i]
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
