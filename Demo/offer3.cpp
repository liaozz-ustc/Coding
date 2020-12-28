//
// Created by 廖洲洲 on 2020/10/1.
//
#include <bits/stdc++.h>
using namespace std;
int findRepeatNumber(int* nums, int numsSize){
    int *count;
    count=(int *)malloc(numsSize*sizeof(int));
    memset(count,0, numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++)
        cout<<count[i]<<'\t';
    for(int i=0;i<numsSize;i++){
        count[nums[i]]++;
        if(count[nums[i]]>1)
            return nums[i];
    }
    return 0;
}
int main(){
    int nums[5]={1,2,2,4,0};
    cout<<endl<<findRepeatNumber(nums,5);
}