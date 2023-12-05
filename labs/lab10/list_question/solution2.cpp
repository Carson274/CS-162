#include <iostream>

#include "list.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *p1 = head;
    ListNode *p2 = head;
    ListNode *prev = NULL;

    for(int i = 0; i < n; ++i) {
        if(p2 != NULL) {
            p2 = p2->next;
        }
    }

    while(p2 != NULL) {
        prev = p1;
        p1 = p1->next;
        p2 = p2->next;
    }

    if(prev == NULL) {
        head = p1->next;
    } else {
        prev->next = p1->next;
    }

    delete p1;

    return head;
}
