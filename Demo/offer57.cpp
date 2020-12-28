//
// Created by 廖洲洲 on 2020/10/8.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //start指向第一个元素，end指向最后一个元素
        //当两个元素和大于目标值时，end向左移，会使得和减小
        //当两个元素和小于目标值时，start向右移，会使得和增大
        vector<int> number;
        if(nums.size()<2)
            return number;
        int start=0,end =nums.size()-1;
        while(start<end){
            int sum=nums[start]+nums[end];
            if(sum==target){
                number.push_back(nums[start]);
                number.push_back(nums[end]);
                return number;
            }else if(sum>target){
                end--;
            }else{
                start++;
            }
        }
        return number;
    }
};
