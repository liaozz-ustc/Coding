//
// Created by 廖洲洲 on 2020/10/8.
//

//输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
//
//序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        //使用start=1和end=2开始，对start和end之间的数求和，若和为目标值则输出，若和小于目标值则end加大
        //若和大于目标值则start加大
        //对于求和可以使用之前的和进行相加相减
        //由于至少两个数，因此start最大为(target+1)/2;
        vector<vector<int> > ans;
        if(target<3)
            return ans;
        int start=1,end=2,sum=3;
        int max=(target+1)/2;
        while(start<=max){
            if(sum==target){
                vectorPushback(ans,start,end);
                sum=sum-start+end+1;
                start++;
                end++;
            }else if(sum>target){
                sum-=start;
                start++;
            }else{
                sum+=end+1;
                end++;
            }
            if(start==end){
                sum++;
                end++;
            }
        }
        return ans;
    }
    void vectorPushback(vector<vector<int>>& ans,int start,int end){
        vector<int> sequence;
        for(int i=start;i<=end;i++){
            sequence.push_back(i);
        }
        ans.push_back(sequence);
    }
};