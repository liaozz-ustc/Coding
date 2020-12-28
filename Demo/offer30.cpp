//
// Created by 廖洲洲 on 2020/10/4.
//

#include <bits/stdc++.h>
using namespace std;
//使用一个栈正常保存数据，使用一个辅组栈保存当前栈的最小元素，即help[i]为stack[0~i]中的最小元素，为此每次数据压入数据栈时比较栈顶
//元素和最小元素的大小，将较小值压入辅助栈，当数据弹出时，同时弹出辅助栈的一个数据
//class MinStack {
//public:
//    /** initialize your data structure here. */
//    stack<int> data,help;
//    MinStack() {
//    }
//
//    void push(int x) {
//        data.push(x);
//        if(help.empty())
//            help.push(x);
//        else{
//            if(x<help.top()){
//                help.push(x);
//            } else{
//                help.push(help.top());
//            }
//        }
//    }
//
//    void pop() {
//        if(!data.empty()) {
//            data.pop();
//            help.pop();
//        }
//        return;
//    }
//
//    int top() {
//        return data.top();
//    }
//
//    int min() {
//        return help.top();
//    }
//};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

/*******使用纯C写*******/
typedef struct MinStack{
    int val;
    int min;
    struct MinStack *next;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *head=(MinStack *)malloc(sizeof(MinStack));
    head->next=NULL;
    return head;
}

void minStackPush(MinStack* obj, int x) {
    MinStack *node=(MinStack *)malloc(sizeof(MinStack));
    node->val=x;
    if(obj->next==NULL){
        node->min=x;
        node->next=NULL;
        obj->next=node;
    }else{
        if(x<=obj->next->min){
            node->min=x;
        }else{
            node->min=obj->next->min;
        }
        node->next=obj->next;
        obj->next=node;
    }
    return;
}

void minStackPop(MinStack* obj) {
    if(obj->next==NULL)
        return;
    else{
        MinStack *tmp;
        tmp=obj->next;
        obj->next=tmp->next;
        free(tmp);
        return;
    }
}

int minStackTop(MinStack* obj) {
    if(obj->next==NULL)
        return 0;
    else{
        return obj->next->val;
    }
}

int minStackMin(MinStack* obj) {
    if(obj->next==NULL)
        return 0;
    else
        return obj->next->min;
}

void minStackFree(MinStack* obj) {
    MinStack *tmp;
    while(obj){
        tmp=obj;
        obj=obj->next;
        free(tmp);
    }
    return;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackMin(obj);

 * minStackFree(obj);
*/