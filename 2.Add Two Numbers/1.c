#include<stdio.h>
#include<stdlib.h>


struct ListNode {
	int val;
	struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ret, *c, *p;
    int num,carry = 0;
    

    while (l1 || l2) {
        num = carry;
        if(l1) {
            num += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            num += l2->val;
            l2 = l2->next;
        }
        carry = num / 10;
        c = (struct ListNode*)malloc(sizeof(struct ListNode));
        c->val = num % 10;
        c->next = NULL;
        if (!ret) {
            p = ret = c;
        } else {
            p->next = c;
            p = c;    
        }
    }
    if (carry) {
        c = (struct ListNode*)malloc(sizeof(struct ListNode));
        c->val = carry;
        c->next = NULL;
        if (!ret) {
            p = ret = c;
        } else {
            p->next = c;
            p = c;    
        }
    }
    return ret;
}

int main(){ 
	struct ListNode *l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *l1 = (struct ListNode*)malloc(sizeof(struct ListNode));

	l1->val = 0;
	l2->val = 0;
	struct ListNode *lr =addTwoNumbers(l1,l2);


	
}
