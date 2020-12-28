//
// Created by 廖洲洲 on 2020/10/6.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //时间和空间复杂度为O(N)
        if(nums.empty())
            return 0;
        int *f=(int *)malloc(nums.size()*sizeof(int));
        f[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            if(f[i-1]<=0){
                f[i]=nums[i];
            }else{
                f[i]=f[i-1]+nums[i];
            }
        }
        int max=f[0];
        for(int i=0;i<nums.size();i++){
            if(f[i]>max)
                max=f[i];
        }
        free(f);
        return  max;
    }
};

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        //时间复杂度为O(N)，利用nums只在求f[i]时有用，以后没用了，可以使用nums数组代替f数组，将空间复杂度降为O(1)
        if(nums.empty())
            return 0;
        int max=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>0)
                nums[i] = nums[i - 1] + nums[i];
            if(nums[i]>max)
                max=nums[i];
        }
        return  max;
    }
};
class Solution3 {
public:
    int maxSubArray(vector<int>& nums) {
        //时间复杂度为O(N)，利用nums只在求f[i]时有用，以后没用了，可以使用nums数组代替f数组，将空间复杂度降为O(1)
        //为了再次降低空间复杂度，使用nums[0]保存最大值,但是这样应该会使程序运行时间上升，因为数组寻址时间更久？
        if(nums.empty())
            return 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>0)
                nums[i] = nums[i - 1] + nums[i];
            if(nums[i]>nums[0])
                nums[0]=nums[i];
        }
        return  nums[0];
    }
};