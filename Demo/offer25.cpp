//
// Created by 廖洲洲 on 2020/10/3.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *l3,*l3Cur,*l1Cur,*l2Cur;
        l1Cur=l1;
        l2Cur=l2;
        if(l1Cur->val<=l2Cur->val) {
            l3 = l1Cur;
            l1Cur = l1Cur->next;
        }
        else {
            l3 = l2Cur;
            l2Cur = l2Cur->next;
        }
        l3Cur=l3;
        while(l1Cur&&l2Cur){
            if(l1Cur->val<=l2Cur->val){
                l3Cur->next=l1Cur;
                l3Cur=l3Cur->next;
                l1Cur=l1Cur->next;
            }else{
                l3Cur->next=l2Cur;
                l3Cur=l3Cur->next;
                l2Cur=l2Cur->next;
            }
        }
        if(l1Cur==NULL){
            l3Cur->next=l2Cur;
        } else {
            l3Cur->next = l1Cur;
        }
        return l3;

    }
};