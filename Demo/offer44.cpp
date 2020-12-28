//
// Created by 廖洲洲 on 2020/10/6.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if(n<=9)
            return n;
        n=n-10;
        int len=2;//当前所在序列的位数
        int tmp;
        while(n>=len*9*pow(10,len-1)){
            n=n-len*9*pow(10,len-1);
            len++;
        }
        int a,b;
        a=n/len;
        b=n%len;
        int now=pow(10,len-1)+a;
        cout<<now<<endl;
        for(int i=len-b;i>0;i--){
            tmp=now%10;//这步可以移到循环外
            now=now/10;
        }
        return tmp;
    }
};

int main(){
    Solution s;
    cout<<s.findNthDigit(1001)<<endl;
    return 0;
}