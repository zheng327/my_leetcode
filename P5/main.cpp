/*
 * 5. ������Ӵ�
 * ����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
 * ����ַ����ķ�����ԭʼ�ַ�����ͬ������ַ�����Ϊ�����ַ�����
 * ʾ�� 1��
 * ���룺s = "babad"
 * �����"bab"
 * ���ͣ�"aba" ͬ���Ƿ�������Ĵ𰸡�
 *
 * ʾ�� 2��
 * ���룺s = "cbbd"
 * �����"bb"
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int MaxLen = 1;
        int begin = 0;
        //����Ϊ1���ַ�����ֱ�ӷ���
        if(n <= 1)
            return s;
        //dp[i][j]��ʾ�����ַ���s�ĵ�iλ����jλ���Ӵ����Ƿ��ǻ����Ӵ�
        vector<vector<bool>> dp(n, vector<bool>(n));
        //ÿһλ�ϵ��ַ�������ǻ����Ӵ�
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        for(int len = 2; len <= n; len++){
            for(int i = 0; i < n; i++){
                int j = i + len - 1;
                //ͷβ���ַ�����ͬ����ʾ���Ӵ����ǻ����Ӵ�
                if(s[i] != s[j])
                    dp[i][j] = false;
                else{
                    //���ͷβ�ַ���ͬ���ҳ���Ϊ2�������ֱ����Ϊ���Ӵ��ǻ����Ӵ�
                    if(len == 2)
                        dp[i][j] = true;
                    //���ȴ���2�������ȥͷȥβ���Ӵ��Ƿ�Ϊ���Ĵ������жϸ��Ӵ��Ƿ�Ϊ�����Ӵ�
                    else
                        dp[i][j] = dp[i+1][j-1];
                }
                //������Ӵ�Ϊ�����Ӵ����ҳ��ȴ���֮ǰ������������Ӵ�������Ӵ�Ϊ������Ӵ�
                if(dp[i][j] == true && len > MaxLen){
                    MaxLen = len;
                    begin = i;
                }
            }
        }
        return s.substr(begin, MaxLen);
    }
};

int main() {
    string s1 = "babad", s2 = "cbbd";
    Solution solution;
    cout << solution.longestPalindrome(s1) << endl;
    cout << solution.longestPalindrome(s2) << endl;
    return 0;
}
