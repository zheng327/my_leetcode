/*
 * 383. �����
 * ���������ַ�����ransomNote �� magazine ���ж� ransomNote �ܲ����� magazine ������ַ����ɡ�
 * ������ԣ����� true �����򷵻� false ��
 * magazine �е�ÿ���ַ�ֻ���� ransomNote ��ʹ��һ�Ρ�
 *
 * ʾ�� 1��
 * ���룺ransomNote = "a", magazine = "b"
 * �����false
 *
 * ʾ�� 2��
 * ���룺ransomNote = "aa", magazine = "ab"
 * �����false
 *
 * ʾ�� 3��
 * ���룺ransomNote = "aa", magazine = "aab"
 * �����true
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
