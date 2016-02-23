/*******************i******************************

Copyright:***

Author:Hao Li

Date:2016-02-23

Description:You are given two linked lists representing two non-negative numbers. 
			The digits are stored in reverse order and each of their nodes contain a single digit. 
			Add the two numbers and return it as a linked list.

			Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
			Output: 7 -> 0 -> 8
**************************************************/
#include <iostream>
#include <windows.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

	void insert(int x){
		ListNode *nl = this;
		while (nl->next){
			nl = nl->next;
		}

		nl->next = new ListNode(x);
	}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *res = new ListNode(0);
	ListNode *tem = res;

	int carry = 0;
	while (l1 || l2){
		int val = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
		carry = val / 10;
		val %= 10;

		tem->next = new ListNode(val);
		tem = tem->next;

		if (l1){
			l1 = l1->next;
		}

		if (l2){
			l2 = l2->next;
		}
	}

	while (carry != 0){
		tem->next = new ListNode(carry%10);
		tem = tem->next;

		carry /= 10;
	}

	return res->next;
}

void printRes(ListNode* res){
	while (res){
		cout << res->val << " ";
		res = res->next;
	}

	cout << endl;
}

int main(){
	//ListNode* l1 = new ListNode(2);
	//ListNode* l2 = new ListNode(5);

	//l1->insert(4);
	//l1->insert(3);

	//l2->insert(6);
	//l2->insert(4);

	ListNode* l1 = new ListNode(5);
	ListNode* l2 = new ListNode(5);

	DWORD start, stop;
	start = GetTickCount();
	ListNode* res = addTwoNumbers(l1, l2);
	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	printRes(res);
	return 0;
}