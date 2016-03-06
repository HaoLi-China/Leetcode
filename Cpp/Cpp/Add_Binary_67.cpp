/*******************i******************************

Copyright:***

Author:Hao Li

Date:2016-02-24

Description:Given two binary strings, return their sum (also a binary string).

			For example,
			a = "11"
			b = "1"
			Return "100".
**************************************************/
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string addBinary(string a, string b) {
	string res = "";

	int lenA = (int)a.length();
	int lenB = (int)b.length();

	int len = lenA < lenB ? lenB : lenA;

	bool isCarry = false;
	for (int i = 0; i < len; i++){
		bool ba = false;
		bool bb = false;

		if (i<lenA){
			ba = (a[lenA - i - 1] == '1');
		}
		if (i<lenB){
			bb = (b[lenB - i - 1] == '1');
		}

		bool sum = ba^bb^isCarry;
		if ((ba&&bb) || (ba&&isCarry) || (isCarry&&bb)){
			isCarry = true;
		}
		else{
			isCarry = false;
		}

		res = (sum ? "1" : "0") + res;
	}
	res = (isCarry ? "1" : "") + res;

	return res;
}

void printRes(string res){
	cout << res << endl;
}

int main(){
	string a = "1111011";
	string b = "101001";

	DWORD start, stop;
	start = GetTickCount();

	string res = addBinary(a, b);

	stop = GetTickCount();
	cout << "time: " << stop - start << " ms" << endl;

	printRes(res);
	return 0;
}