//
// Created by 廖洲洲 on 2020/10/4.
//

#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        Node *copyHead=(Node *)malloc(sizeof(Node));
        Node *copyNow=copyHead;
        copyHead->val=head->val;
        map<Node *,Node*> hashMap;
        hashMap.insert(make_pair(head,copyHead));
        Node *now=head->next;
        Node *tmp;
        while(now){
            tmp=(Node *)malloc(sizeof(Node));
            tmp->val=now->val;
            copyNow->next=tmp;
            copyNow=tmp;
            hashMap.insert(make_pair(now,copyNow));
            now=now->next;
        }
        copyNow->next=NULL;
        now=head;
        copyNow=copyHead;
        while(now){
            if(now->random){
                copyNow->random=hashMap.find(now->random)->second;//find函数返回的是键值对
            }else{
                copyNow->random=NULL;
            }
            now=now->next;
            copyNow=copyNow->next;
        }
        return copyHead;
    }
};