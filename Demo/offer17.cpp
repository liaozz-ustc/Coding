//
// Created by 廖洲洲 on 2020/10/3.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> result;
        result.push_back(1);
        if(n<=0)
            return result;
        int fin=pow(10,n);
        for(int i=2;i<fin;i++)
            result.push_back(i);
        return result;
    }
};
