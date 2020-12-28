//
// Created by 廖洲洲 on 2020/10/6.
//

#include <bits/stdc++.h>
using namespace std;

char firstUniqChar(char* s){
    if(!s)
        return ' ';
    int len=strlen(s);
    if(len==0)
        return  ' ';
    int hashMap[26];
    memset(hashMap,0, sizeof(hashMap));
    for(int i=0;i<len;i++)
        hashMap[s[i]-'a']++;
    for(int i=0;i<len;i++)
        if(hashMap[s[i]-'a']==1)
            return s[i];
    return ' ';
}
