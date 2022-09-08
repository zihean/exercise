//
//  leetcode_2.cpp
//  exercise
//
//  Created by 安子和 on 2022/9/8.
//

#include "leetcode_2.hpp"

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        int base = 1;
        
        ListNode *aTmp = l1, *bTmp = l2;
        
        ListNode *head = new ListNode();
        ListNode *cTmp = head;
        while (aTmp && bTmp) {
            c += aTmp->val + bTmp->val;
            
            cTmp->next = new ListNode(c % 10);
            cTmp = cTmp->next;
            
            aTmp = aTmp->next;
            bTmp = bTmp->next;
            
            c = c > 9 ? 1 : 0;
        }
        
        while (aTmp) {
            c += aTmp->val;
            
            cTmp->next = new ListNode(c % 10);
            cTmp = cTmp->next;
            
            aTmp = aTmp->next;
            
            c = c > 9 ? 1 : 0;
        }
        
        while (bTmp) {
            c += bTmp->val;
            
            cTmp->next = new ListNode(c % 10);
            cTmp = cTmp->next;
            
            bTmp = bTmp->next;
            
            c = c > 9 ? 1 : 0;
        }
        
        if (c) {
            cTmp->next = new ListNode(c);
        }
        
        return head->next;
}
