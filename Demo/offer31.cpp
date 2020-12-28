//
// Created by 廖洲洲 on 2020/10/4.
//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty()||popped.empty())
            return true;
        stack<int> myStack;
        int i=0,j=0;
        for(i=0;i<pushed.size();i++){
            if(pushed[i]!=popped[j]){
                myStack.push(pushed[i]);
            }else{
                j++;
                while(!myStack.empty()&&j<popped.size()&&myStack.top()==popped[j]){
                    myStack.pop();
                    j++;
                }
            }
        }
        return myStack.empty();
    }
};
int main(){
    Solution s;
    vector<int> pushed={1,2,3,4,5};
    vector<int> poped={4,5,3,2,1};
    if(s.validateStackSequences(pushed,poped))
        cout<<'1'<<endl;
    else
        cout<<"0"<<endl;
}