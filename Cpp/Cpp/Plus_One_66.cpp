/*******************i******************************

Copyright:***

Author:Hao Li

Date:2016-03-06

Description:Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	vector<int> res;

	int carry = 0;
	for (int i = (int)digits.size() - 1; i >= 0; i--){
		int val = digits[i] + carry + ((i == (int)digits.size() - 1)?1:0);
		res.push_back(val % 10);
		carry = val / 10;
	}

	if (carry > 0){
		res.push_back(carry);
	}

	reverse(res.begin(), res.end());

	return res;
}

void printRes(vector<int>& res){
	for (auto i = 0; i < res.size(); i++){
		cout << res[i];
	}
	cout << endl;
}

int main(){
	DWORD start, stop;

	start = GetTickCount();
	vector<int> digits = {1,0};
	vector<int> res = plusOne(digits);
	stop = GetTickCount();

	cout << "time: " << stop - start << " ms" << endl;

	printRes(res);
	return 0;
}