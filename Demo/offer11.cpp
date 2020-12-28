//
// Created by 廖洲洲 on 2020/10/2.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        for(int i=1;i<numbers.size();i++){
            if(numbers[i]<numbers[i-1])
                return numbers[i];
        }
        return numbers[0];
    }
};