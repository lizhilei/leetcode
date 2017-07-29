#include<stdio.h>
#include<stdlib.h>


struct ListNode {
	int val;
	struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ret = NULL, *tail = NULL, *t, *n;
    int num,carry = 0, v1, v2;

    while (l1 || l2) {
		v1 = l1 ? l1->val : 0;
		v2 = l2 ? l2->val : 0;
		num = v1 + v2 + carry;
        carry = num / 10;
		num = num % 10;
//        c = (struct ListNode*)malloc(sizeof(struct ListNode));
		t = l1 ? l1 : l2;
		t->val = num;
//        c->next = NULL;
        if (!ret) {
            tail = ret = t;
        } else {
            tail->next = t;
            tail = tail->next;    
        }
		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2;
    }
    if (carry) {
        n = (struct ListNode*)malloc(sizeof(struct ListNode));
        n->val = carry;
        n->next = NULL;
		tail->next = n;    
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
