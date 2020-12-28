//
// Created by 廖洲洲 on 2020/10/7.
//

#include <bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)
            return NULL;
        int lenA=0,lenB=0;
        ListNode *posA=headA,*posB=headB;
        while(posA){
            lenA++;
            posA=posA->next;
        }
        while(posB){
            lenB++;
            posB=posB->next;
        }
        posA=headA;posB=headB;
        if(lenA>lenB){
            while(lenA>lenB){
                posA=posA->next;
                lenA--;
            }
        }else{
            while(lenB>lenA){
                posB=posB->next;
                lenB--;
            }
        }
        while(posA!=posB){
            posA=posA->next;
            posB=posB->next;
        }
        return posA;
    }
};