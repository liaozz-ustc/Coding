//
// Created by 廖洲洲 on 2020/10/3.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty() && s.empty())//都空，则匹配
            return true;
        if (p.empty())//只有模式空，则定不匹配
            return false;
        if (s.empty())//只有s空，则可以为".*.*.*"模式
            return p.size() >= 2 && p[1] == '*' && isMatch(s, p.substr(2));
        //若都不空，p开头定不能为"*"
        if (p[0] == '*')
            return false;
        while (p[1] == '*' && p[3] == '*' && p[0] == p[2]) {
            p = p.substr(2);
        }
//        if (s.size() == 1) {
//            return (p.size() == 1 && (p[0] == s[0] || p[0] == '.')) ||
//                   (p.size() == 2 && p[1] == '*' && (p[0] == s[0] || p[0] == '.')) ||
//                   (p.size() > 2 && isMatch(s, p.substr(2)));
//        }
        //p的大小大于2，慢慢将s缩短，p的首位不会为"*"
        if (p.size() >= 2) {
            if (p[0] == '.') {
                if (p[1] != '*')
                    return isMatch(s.substr(1), p.substr(1));
                else
                    return isMatch(s.substr(1), p.substr(2))
                           || isMatch(s, p.substr(2))
                           || isMatch(s.substr(1), p);
            } else {
                if (p[1] != '*')
                    return p[0] == s[0] && isMatch(s.substr(1), p.substr(1));
                else {
                    return (p[0] == s[0] && (isMatch(s.substr(1), p.substr(2)) || isMatch(s.substr(1), p)))
                           || isMatch(s, p.substr(2));
                }
            }
        }
        //p的大小小于2
        if (s[0] == p[0] || p[0] == '.')
            return isMatch(s.substr(1), p.substr(1));
        return false;
    }
};


class Solution2 {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        bool **dp = (bool **) malloc((n + 1) * sizeof(bool *));
        for (int i = 0; i <= n; i++)
            dp[i] = (bool *) malloc((m + 1) * sizeof(bool));
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                dp[i][j] = false;
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
            dp[i][0] = false;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] != '*') {
                    //分为最后一个字符是否为'*'
                    if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = false;
                } else {
                    //最后的字符为'*"
                    if (i > 0) {
                        if (p[j - 2] == '.' || s[i - 1] == p[j - 2]) {
                            dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];//'.'当一个、零个和多个字符
                        } else {//正常字符
                            dp[i][j] = dp[i][j - 2];
                        }
                    } else {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        bool result = dp[n][m];
        for (int i = 0; i <= n; i++)
            free(dp[i]);
        free(dp);
        return result;
    }
};


int main() {
    Solution2 s;
    cout << s.isMatch("aaaaaaaaaaaaab",
                      "a*a*a*a*a*a*a*a*a*a*c");
}
