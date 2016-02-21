/*************************************************

Copyright:***

Author:Hao Li

Date:2016-02-21

Description:Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
			Find all unique triplets in the array which gives the sum of zero.

			Note:
			Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
			The solution set must not contain duplicate triplets.
			For example, given array S = {-1 0 1 2 -1 -4},

			A solution set is:
			(-1, 0, 1)
			(-1, -1, 2)
**************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());

	for (int i = 0; i < (int)(nums.size() - 2); i++){
		if (i > 0 && nums[i] == nums[i - 1]){
			continue;
		}

		int j = i + 1;
		int k = nums.size() - 1;

		while (j < k){
			int sum = nums[i] + nums[j] + nums[k];
			if (sum > 0){
				k--;
			}
			else if (sum < 0){
				j++;
			}
			else{
				vector<int> triplet(3);
				triplet[0] = nums[i];
				triplet[1] = nums[j];
				triplet[2] = nums[k];
				res.push_back(triplet);

				j++;
				k--;
				
				while (j < k && nums[j] == nums[j - 1] && nums[k] == nums[k + 1]){
					j++;
					k--;
				}
			}
		}
	}

	return res;
}

void printResult(vector<vector<int>> &res){
	for (auto i = 0; i < res.size(); i++){
		for (auto j = 0; j < res[i].size(); j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	vector<vector<int>> res;
	vector<int> nums;

	//nums.push_back(-1);
	//nums.push_back(0);
	//nums.push_back(1);
	//nums.push_back(1);
	//nums.push_back(2);
	//nums.push_back(-1);
	//nums.push_back(-4);

	nums.push_back(-2);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(-1);
	nums.push_back(4);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(-3);
	nums.push_back(-5);
	nums.push_back(4);
	nums.push_back(0);

	res = threeSum(nums);
	printResult(res);

	return 0;
}