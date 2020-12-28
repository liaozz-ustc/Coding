//
// Created by 廖洲洲 on 2020/10/6.
//

#include <bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstring(char* s){
    int len=strlen(s);
    if(!s||len==0)
        return 0;
    int hashMap[256];//记录每个字符最新的位置,如果该字符出现了，且原来位置在start后面，则窗口后移
    for(int i=0;i<256;i++)
        hashMap[i]=-1;
    int start=0,pos=0;
    int max=1;
    for(;pos<len;pos++){
        if(hashMap[s[pos]]>=start){
            if(pos-start>max){
                max=pos-start;
            }
            start=hashMap[s[pos]]+1;
        }
        hashMap[s[pos]]=pos;
    }

    return max>pos-start?max:pos-start;
}