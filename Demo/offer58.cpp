//
// Created by 廖洲洲 on 2020/10/8.
//

#include <bits/stdc++.h>

using namespace std;
//
//class Solution {
//public:
//    string reverseWords(string s) {
//        if (s.empty())
//            return s;
//        cout << reverseCore(s);
//        return s;
//    }
//
//    string reverseCore(string s) {
//        if (s.empty())
//            return s;
//        s = ' ' + s;
//        int len = s.length();
//        int i = len - 1;
//        while (i >= 0 && s[i] == ' ') {
//            i--;
//        }
//        if (i < 0) {
//            string s;
//            return s;
//        }
//        int j = i;
//        while (j >= 0 && s[j] != ' ') {
//            j--;
//        }
//        if (j < 0)
//            return s.substr(0, i + 1) + reverseWords(s.substr(0, len - (i + 1)));
//        return s.substr(j, i - j + 1) + reverseWords(s.substr(0, len - (i - j + 1)));
//    }
//};

char *reverseWordsCore(char *s, int len) {
    char *ans;
    ans = (char *) malloc((len+1) * sizeof(char));
    memset(ans,0,len+1);
    int left=len-1,right=len-1;
    int newlen=0;
    while (left >= 0) {
        right = left;
        while (right >= 0 && s[right] == ' ') {
            right--;
        }
        left = right;
        while (left >= 0 && s[left] != ' ') {
            left--;
        }
        int j=0;
        for(int i=left+1;i<=right;i++){
            ans[newlen+j]=s[i];
            j++;
        }
        if(left>=0){
            ans[newlen+j]=' ';
        }
        newlen=newlen+j+1;
    }
    return ans;

}

char *reverseWords(char *s) {
    if(!s)
        return NULL;
    int len = strlen(s);
    if (len == 0) {
        return "";
    }
    //首先处理前后空格
    int pre = 0;
    while (pre < len && s[pre] == ' ') {
        pre++;
    }
    if (pre >= len) {
        //都是空格
        return "";
    }
    //不都是空格
    int end = len - 1;
    while (end >= 0 && s[end] == ' ') {
        end--;
    }
    return reverseWordsCore(s + pre, end - pre + 1);
}

int main(){
    char s[]="a good  example";
    printf("%s",reverseWords(s));
    printf("@@@@@@@\n");
}