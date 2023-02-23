#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
class Solution
{
public:
	int min(int a, int b)
	{
		if(a < b) return a;
		else return b;
	}
	int findMin(vector<int>& nums)
	{
		int Min = 1000000;
		for(int i = 0; i < nums.size(); ++i)
		{
			Min = min(Min, nums[i]);
		}
		return Min;
	}
};

int main () {
	int n;
	cin>>n>>endl;
	vector<int>& nums;
	cin >> nums;
	findMin(nums);
	return 0;
}
