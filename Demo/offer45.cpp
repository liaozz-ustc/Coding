//
// Created by 廖洲洲 on 2020/10/6.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minNumber(vector<int> &nums) {
        //对于两个数m、n来说，它们的组合为mn和nm，mn和nm的位数一定相同
        //则mn和nm谁更小就将其第一个数放在前方
        //即按此种方法排序的最小值放在开头
        vector<string> nums2str;
        string ans;
        for (int i = 0; i < nums.size(); i++)
            nums2str.push_back(to_string(nums[i]));
        sort(nums2str.begin(), nums2str.end(), [](string &s1, string &s2) { return s1 + s2 < s2 + s1; });
        for (int i = 0; i < nums.size(); i++) {
            ans += nums2str[i];
        }
        return ans;
    }
};