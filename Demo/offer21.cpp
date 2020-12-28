//
// Created by 廖洲洲 on 2020/10/3.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size()==1){
            return nums;
        }
        int tmp;
        int p=0,q=nums.size()-1;
        while(p<nums.size()&&(nums[p]&1)){
            //当p所指位置为奇数,直到指向偶数
            p++;
        }
        while(q>=0&&!(nums[q]&1)){
            //当q所指位置为偶数，直到指向奇数
            q--;
        }
        while(p<q){
            tmp=nums[p];
            nums[p]=nums[q];
            nums[q]=tmp;
            while(p<nums.size()&&(nums[p]&1)){
                //当p所指位置为奇数,直到指向偶数
                p++;
            }
            while(q>=0&&!(nums[q]&1)){
                //当q所指位置为偶数，直到指向奇数
                q--;
            }
        }
        return nums;
    }
};