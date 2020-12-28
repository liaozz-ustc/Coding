//
// Created by 廖洲洲 on 2020/10/5.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int keyValue[2];
        if(nums.empty())
            return 0;
        keyValue[0]=nums[0];keyValue[1]=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==keyValue[0])
                keyValue[1]++;
            else{
                if(keyValue[1]==0){
                    keyValue[0]=nums[i];
                    keyValue[1]=1;
                }else{
                    keyValue[1]--;
                }
            }
        }
        return keyValue[0];
    }
};
