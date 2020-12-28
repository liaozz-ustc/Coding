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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head==NULL||k<=0)
            return NULL;
        ListNode *now,*kPre;
        now=head;
        kPre=head;
        for(int j=k;j>0;j--){
            now=now->next;
            if(now==NULL&&j>=2)
                return NULL;
        }
        while(now){
            now=now->next;
            kPre=kPre->next;
        }
        return kPre;
    }
};