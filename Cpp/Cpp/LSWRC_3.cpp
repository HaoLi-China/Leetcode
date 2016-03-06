/*******************i******************************

Copyright:***

Author:Hao Li

Date:2016-03-06

Description:Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
**************************************************/

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
	int res = 0;
	int hash[256];
	for (int i = 0; i < 256; i++){
		hash[i] = -1;
	}

	int start = 0;
	for (int i = 0; i < s.length(); i++){
		if (hash[s[i]] != -1){
			if (res < i - start){
				res = i - start;
			}

			for (int k = start; k < hash[s[i]]; k++){
				hash[s[k]] = -1;
			}

			start = hash[s[i]] + 1;
		}

		hash[s[i]] = i;
	}

	if (res < s.length() - start){
		res = s.length() - start;
	}

	return res;
}

void printRes(int len){
	cout << len << endl;
}

int main(){
	string s = "bbbbb";
	DWORD start, stop;

	start = GetTickCount();
	int len = lengthOfLongestSubstring(s);
	stop = GetTickCount();

	cout << "time: " << stop - start << " ms" << endl;

	printRes(len);
	return 0;
}