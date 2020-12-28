//
// Created by 廖洲洲 on 2020/10/2.
//
#include <bits/stdc++.h>
using namespace std;

class CQueue {
    stack<int> stack1;
    stack<int> stack2;
public:
    CQueue() {
        while(!stack1.empty()){
            stack1.pop();
        }
        while(!stack2.empty()){
            stack2.pop();
        }
    }

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if(stack2.empty()){
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(!stack2.empty()){
            int result=stack2.top();
            stack2.pop();
            return result;
        }
        return -1;
    }
};
