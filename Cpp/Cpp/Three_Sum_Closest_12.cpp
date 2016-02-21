/*******************i******************************

Copyright:***

Author:Hao Li

Date:2016-02-21

Description:Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
			Return the sum of the three integers. 
			You may assume that each input would have exactly one solution.
			For example, given array S = {-1 2 1 -4}, and target = 1.
			The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
**************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());

	int sum = nums[0] + nums[1] + nums[2];

	for (int i = 0; i < (int)(nums.size() - 2); i++){
		if (i > 0 && nums[i] == nums[i - 1]){
			continue;
		}

		int j = i + 1;
		int k = nums.size() - 1;

		while (j < k){
			int sum_tem = nums[i] + nums[j] + nums[k];

			if (abs(sum_tem - target) < abs(sum - target)){
				sum = sum_tem;
			}

			if (sum_tem > target){
				k--;
			}
			else if (sum_tem < target){
				j++;
			}
			else{
				return target;
			}
		}
	}

	return sum;
}

void printRes(int target){
	cout << target << endl;
}

int main(){
	vector<int> nums;
	int target = -1;

	nums.push_back(-3);
	nums.push_back(-2);
	nums.push_back(-5);
	nums.push_back(3);
	nums.push_back(-4);

	int res = threeSumClosest(nums, target);
	printRes(res);

	return 0;
}