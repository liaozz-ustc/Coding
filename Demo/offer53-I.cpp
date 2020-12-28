/*
 * @Author: Liaozz
 * @Date: 2020-10-07 15:24:51
 * @LastEditTime: 2020-12-24 17:09:20
 * @LastEditors: Liaozz
 * @FilePath: \Offer\offer53-I.cpp
 */
//
// Created by 廖洲洲 on 2020/10/7.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int low=0,high=nums.size()-1;
        int mid=(low+high)/2;
        while(low<high){
            if(nums[mid]==target)
                break;
            else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
            mid=(low+high)/2;
        }
        if(nums[mid]!=target)
            return 0;
        high=mid+1;
        low=mid-1;
        int len=nums.size();
        while(high<len&&nums[high]==target){
            high++;
        }
        while(low>=0&&nums[low]==target){
            low--;
        }
        return high-low-1;
    }
};
int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(5);nums.push_back(7);
    nums.push_back(7);nums.push_back(8);
    nums.push_back(8);nums.push_back(10);
    cout<<s.search(nums,8);
}

int searchFirst(int *nums,int numsSize,int start,int end,int target){
    if(start>end)
        return -1;
    int mid=(start+end)/2;
    int midData=nums[mid];
    if(midData==target){
        if(mid==0||(nums[mid-1]!=target))
            return mid;
        else
            end=mid-1;
    }
    else if(midData>target)
        end=mid-1;
    else
        start=mid+1;
    return searchFirst(nums,numsSize,start,end,target);
}
int searchLast(int *nums,int numsSize,int start,int end,int target){
    if(start>end)
        return -1;
    int mid=(start+end)/2;
    int midData=nums[mid];
    if(midData==target){
        if(mid==numsSize-1||nums[mid+1]!=target)
            return mid;
        else
            start=mid+1;
    }else if(midData<target)
        start=mid+1;
    else
        end=mid-1;
    return searchLast(nums,numsSize,start,end,target);
}

int search(int* nums, int numsSize, int target){
    //单纯使用二分查找当查找的数字重复次数过多时会使得时间复杂度变为O(n)
    //为此，使用两次二分查找，第一次查找目标值的最小位置，第二次查找目标值的最大位置
    int number=0;
    if(nums&&numsSize>0){
        int first=searchFirst(nums,numsSize,0,numsSize-1,target);
        if(first>-1) {
            int last = searchLast(nums, numsSize, 0, numsSize - 1, target);
            number = last - first + 1;
        }
    }
    return number;
}