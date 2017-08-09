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
		vector<int> numpos;
		vector<int> countSmaller(vector<int>& nums){
			if (nums.empty())
				return nums;
			vector<int> result(nums.size(), 0);
			if (nums.size() == 1)
				return result;
			for (int i = 0 ; i < nums.size() ; i++){
				numpos.push_back(i);
			}

			mergeSort(nums, 0, nums.size() - 1, result);
			return result;
		}

		void mergeSort(vector<int>& nums, int ll, int rr, vector<int>& result){
			if (ll < rr){
				int mid = (ll + rr) / 2;
				mergeSort(nums,ll,mid, result);
				mergeSort(nums,mid+1, rr, result);
				merge(nums, ll,rr, result);
			}
		}
		void merge(vector<int>& nums, int ll, int rr, vector<int>& result){
			int mid = (ll + rr) / 2;
			//cout << ll << ":" <<mid << ":"<< rr << endl;
			int idxL = ll, idxR = mid + 1;;
			vector<int> seq;
			vector<int> pos;
			while (idxL <= mid  && idxR <=rr){
				if (nums[idxL] <= nums[idxR]){
					seq.push_back(nums[idxL]);
					pos.push_back(numpos[idxL]);
					idxL++;
				} else {
					// left > right
					for (int i = idxL ; i <= mid ; i++){
						result[numpos[i]]++;
					}
					seq.push_back(nums[idxR]);
					pos.push_back(numpos[idxR]);
					idxR++;
				}
			}
			while(idxL <= mid){
					seq.push_back(nums[idxL]);
					pos.push_back(numpos[idxL]);
					idxL++;
			}
			while(idxR <= rr){
					seq.push_back(nums[idxR]);
					pos.push_back(numpos[idxR]);
					idxR++;
			}
			// update index here;
			for (int i = 0 ; i < seq.size() ; i++){
				numpos[ll+i] = pos[i];
				nums[ll+i]   = seq[i];
			}
			return;
		}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {5,2,6,1};
	int B[] = {-1,-1};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	int ret;
	ret_vec = sol.countSmaller(da);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
