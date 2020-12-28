//
// Created by 廖洲洲 on 2020/10/2.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(int n){

        if(n==0||n==1)
            return 1;
        return numWays(n-1)+numWays(n-2);
    }
};
