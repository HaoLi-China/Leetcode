/*************************************************

Copyright:***

Author:Hao Li

Date:2016-02-20

Description:Given an array of integers, return indices of the two numbers such that they add up to a specific target.
			You may assume that each input would have exactly one solution.

			Example:
			Given nums = [2, 7, 11, 15], target = 9,
			Because nums[0] + nums[1] = 2 + 7 = 9,
			return [0, 1].
**************************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
	map<int, int> mp;
	vector<int> res(2);

	for (auto i = 0; i < nums.size(); i++){
		int x = nums[i];
		int y = target - x;
		if (mp.find(y) != mp.end()){
			res[0] = mp[y];
			res[1] = i;

			return res;
		}
		else
			mp[x] = i;
	}

	res[0] = -1;
	res[1] = -1;
	return res;
}

vector<int> genNums(){
	vector<int> nums;
	int totalNum = rand() + 1;
	cout << "nums: ";
	for (int i = 0; i < totalNum; i++){
		nums.push_back(rand());
		cout << nums[i] << " ";
	}

	cout << endl;
	return nums;
}

int genTarget(){
	int target = rand();
	cout << "target: " << target << endl;
	return target;
}

void printResult(vector<int> &res){
	if (res.size() == 2 && res[0] >= 0 && res[1] >= 0){
		for (auto i = 0; i < res.size(); i++){
			cout << res[i] << " ";
		}
	}
	else{
		cout << "no solution!";
	}
	
	cout << endl;
}

int main(){
	//vector<int> nums = genNums();
	//int target = genTarget();

	//vector<int> res = twoSum(nums, target);
	//printResult(res);

	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	int target = 9;

	vector<int> res = twoSum(nums, target);
	printResult(res);
}

