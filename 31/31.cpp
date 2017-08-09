#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
class Solution {
	public:
	void nextPermutation(vector<int>& nums){
		stack<int> ss;
		int i;
		int pos;
		for (i = nums.size() - 1 ; i >= 0 ; i--){
			if(ss.empty()){
				ss.push(i);
			} else {
				int target = nums[ss.top()];
				if (nums[i] >= target)
					ss.push(i);
				else {
					while(!ss.empty() && nums[i] < nums[ss.top()] ){
						pos = ss.top();
						ss.pop();
					}
					int tmp = nums[pos];
					nums[pos] = nums[i];
					nums[i] = tmp;
					break;
				}
			}
		}

		if (i < 0)
			sort(nums.begin(), nums.end());
		else
			sort(nums.begin()+i+1, nums.end());
		return;
	}
};
#if 1
void quicksort(vector<int>& nums, int left, int right)
{
	int pivot = nums[left];
	
	int ll = left+1;
	int rr = right;
	if (left >= right)
		return;

	while(true){
		while(nums[rr]>pivot)
			rr--;
		while(nums[ll]<pivot && ll < right)
			ll++;
		if (ll>=rr)
			break;
		int tmp = nums[rr];
		nums[rr] = nums[ll];
		nums[ll] = tmp;
	}
	int tmp = nums[left];
	nums[left] = nums[rr];
	nums[rr] = tmp;
	
	for (int i = 0 ; i < nums.size() ; i++)
		cout << nums[i] << " ";
	cout <<endl;
	quicksort(nums, left, rr-1);
	quicksort(nums, rr+1, right);

	return;
}
#endif
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {6,7,5,3,2,4,1};
	int B[] = {0,1,1,0,4,4};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	quicksort(da, 0, 6);
	for (int i = 0 ; i < da.size() ; i++)
		cout << da[i] << " ";
	cout <<endl;
#if 0
	sol.nextPermutation(da);

	for (int i = 0 ; i < da.size() ; i++)
		cout << da[i] << " ";
	cout <<endl;
	
	sol.nextPermutation(db);

	for (int i = 0 ; i < db.size() ; i++)
		cout << db[i] << " ";
	cout <<endl;
#endif
	return 0;
}
