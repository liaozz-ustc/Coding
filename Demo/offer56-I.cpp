//
// Created by 廖洲洲 on 2020/10/8.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        //数组中有两个数只出现一次，其它数出现两次，寻找只出现一次的这两个数
        //将数组中所有的数一起异或，得到的数即为两个出现一次的数的异或
        //由于两个不同的数异或一定不为零，那么即异或的结果有定一位为1，即该位这两个数不一样
        //利用该位将数组分为两半，一半该位为1，一半该位为0，则出现两次的数定在同一半，出现一次的数定在不同一半
        //调用寻找单个数的函数分别寻找这两个数
        if(nums.size()==2)
            return nums;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        int bit=1;
        while (!(ans&bit)){
            bit=bit<<1;
        }
        //下面对数组进行二分
        int pos=-1;//指向bit位为1的数组的最后一位
        int tmp;
        for(int i=0;i<nums.size();i++){
            //没有必要进行二分，可以直接判断该位是否为0，然后分别和不同的数进行异或
            if(nums[i]&bit){
                //该位为1
                pos++;
                tmp=nums[i];
                nums[i]=nums[pos];
                nums[pos]=tmp;
            }
        }
        vector<int> singleNums;
        singleNums.push_back(findSingleNumber(nums,0,pos));
        singleNums.push_back(findSingleNumber(nums,pos+1,nums.size()-1));
        return singleNums;
    }
    int findSingleNumber(vector<int> &nums,int start,int end){
        //数组中只有一个数出现一次，其他数出现两次，那么将所有的数进行异或就会得到只出现一次的数
        int len=end-start+1;
        if(len==1)
            return nums[start];
        int ans=0;
        for(int i=start;i<=end;i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> singleNumbers(vector<int>& nums) {
    //优化：不必要移动数组，直接和不同的数异或即可
        if(nums.size()==2)
            return nums;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        int bit=1;
        while (!(ans&bit)){
            bit=bit<<1;
        }
        vector<int> singleNums;
        singleNums.push_back(0);singleNums.push_back(0);
        for(int n:nums){
            if(n&bit){
                singleNums[0]=singleNums[0]^n;
            }else{
                singleNums[1]=singleNums[1]^n;
            }
        }
        return singleNums;
    }
};