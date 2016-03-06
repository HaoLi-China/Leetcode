/*******************i******************************

Copyright:***

Author:Hao Li

Date:2016-02-24

Description:Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
**************************************************/
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string multiply(string num1, string num2) {
	string res(num1.length()+num2.length(), '0');
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	for (int i = 0; i < num2.size(); i++){
		int val2 = num2[i] - '0';
		int carry = 0;
		for (int j = 0; j < num1.size(); j++){
			int val1 = num1[j] - '0';
			int val = res[i + j]- '0' + val2*val1 + carry;
			res[i + j] = val % 10 + '0';
			carry = val / 10;
		}

		if (carry > 0){
			res[i + num1.size()] = carry + '0';
		}
	}
	reverse(res.begin(), res.end());

	int count = 0;
	for (int i = 0; i < res.size()-1; i++){
		if (res[count] == '0'){
			count++;
		}
		else{
			break;
		}
	}
	res.erase(0, count);

	return res;
}

void printRes(string res){
	cout << res << endl;
}

int main(){
	//string num1 = "76240047126666041961133788375854678695507175099108423713540245804984464373874905749210597511224714";
	//string num2 = "50508987390094918079940272645150122130992191514531426745139766970214425636907460704571014980779812464";

	string num1 = "102400";
	string num2 = "102400";

	DWORD start, stop;
	start = GetTickCount();

	string res = multiply(num1, num2);

	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	printRes(res);
	return 0;
}