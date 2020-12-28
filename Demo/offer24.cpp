//
// Created by 廖洲洲 on 2020/10/3.
//

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        stack<int> listVal;
        ListNode *now=head;
        while(now){
            listVal.push(now->val);
            now=now->next;
        }
        now=head;
        while(now){
            now->val=listVal.top();
            now=now->next;
            listVal.pop();
        }
        return head;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode *pre,*now,*next;
        pre=NULL;
        now=head;
        next=now->next;
        if(next==NULL)
            return now;
        while (next){
            now->next=pre;
            pre=now;
            now=next;
            next=now->next;
        }
        now->next=pre;
        return now;
    }
};