//
// Created by 廖洲洲 on 2020/10/7.
//

#include <bits/stdc++.h>
using namespace std;

int missingNumber(int* nums, int numsSize){
    int start=0;
    int end=numsSize-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(nums[mid]>mid){
            if(mid==0||nums[mid-1]==mid-1)
                return mid;
            else
                end=mid-1;
        }else{
            start=mid+1;
        }
        mid=(start+end)/2;
    }
    return start;
}