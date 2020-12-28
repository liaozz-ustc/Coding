//
// Created by 廖洲洲 on 2020/10/8.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //第一种方法，对于每一位来说，所有数字的该位的1的个数要么为3的整数个（即唯一的数该位为0）
        // 要么为3的整数个多1（即唯一的数的该位为1）
        //所以使用自动状态机two-one表示当前1的个数，使用two和num的相应位组成自动状态机
        int two=0,one=0;
        for(int n:nums){
            one=(~two)&(one^n);
            two=(~one)&(two^n);
        }
        return one;
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        //第二种方法，通用方法
        //数每一位的1有多少个，当是3的整数倍时该位为0，不是3的整数倍时该位为1
        int bitCount[32]={0};
        for(int n:nums){
            int bitMask=1;
            for(int i=0;i<32;i++){
                if(n&bitMask){
                    bitCount[i]++;
                }
                bitMask=bitMask<<1;
            }
        }
        int ans=0;
        for(int i=31;i>=0;i--){
            ans=ans<<1;
            ans+=bitCount[i]%=3;

        }
        return ans;
    }
};
