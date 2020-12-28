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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        ListNode *prior,*now;
        prior=head;now=head;
        while(now&&now->val!=val){
            prior=now;
            now=now->next;
        }
        if(!now)
            return NULL;
        if(now==head){
            head=now->next;
            return head;
        }else{
            prior->next=now->next;
            return head;
        }

    }
};