//
// Created by 廖洲洲 on 2020/10/6.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        if (num <= 9)
            return 1;
        string num2str;
        num2str = to_string(num);
        int *f = (int *) malloc(num2str.length() * sizeof(int));
        int i = num2str.length() - 1;
        f[i] = 1;
        i--;
        if (num2str[i] == '1' || (num2str[i] == '2' && num2str[i + 1] <= '5'))
            f[i] = 2;
        else
            f[i] = 1;
        i--;
        for (; i >= 0; i--) {
            if (num2str[i] == '1' || (num2str[i] == '2' && num2str[i + 1] <= '5'))
                f[i] = f[i + 1] + f[i + 2];
            else
                f[i] = f[i + 1];
        }
//        for(int i=0;i<num2str.length();i++)
//            cout<<f[i];
        return f[0];
    }
};

int main() {
    Solution s;
    cout << s.translateNum(12258);
}

class Solution2 {
public:
    int translateNum(int num) {
        //对于动态规划，空间复杂度大都是可以优化的，将f数组永几个变量代替
        if (num <= 9)
            return 1;
        string num2str;
        num2str = to_string(num);
        int i = num2str.length() - 1;
        i--;
        int fi, fip1, fip2;
        fip2 = 1;
        if (num2str[i] == '1' || (num2str[i] == '2' && num2str[i + 1] <= '5'))
            fip1 = 2;
        else
            fip1 = 1;
        i--;
        fi = fip1;
        for (; i >= 0; i--) {
            if (num2str[i] == '1' || (num2str[i] == '2' && num2str[i + 1] <= '5'))
                fi = fip1 + fip2;
            else
                fi=fip1;
            fip2=fip1;
            fip1=fi;
        }
        return fi;
    }
};