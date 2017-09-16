#include "../helpers.cpp"
/*
Your input is a double array, and you can use *, +, -, and () parenthesis 
anywhere to create and output the maximum possible value. 

Ex: 
input is {3,4,5,1} --> output: 72 
input is {1,1,1,5} --> output: 15 

Follow up, if there are numbers <0
 *
 */
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
       	double maxnum(vector<double>& nums){
		vector<double> vec;
		vec = helper(nums, 0, nums.size() - 1);
		return vec[0];
        }
	vector<double> helper(vector<double>& nums, int ll, int rr){
		double lmax = numeric_limits<double>::lowest();
		double lmin = numeric_limits<double>::max();
		if (ll==rr)
			return {nums[ll], nums[ll]};
		for (int i = ll ; i < rr ; i++){
			vector<double> left = helper(nums, ll, i);
			vector<double> right = helper(nums, i+1, rr);
			for (int m = 0 ; m < left.size() ; m++){
				for (int n = 0 ; n < right.size() ; n++){
					double val;
					val = left[m] + right[n];
					lmax = max(lmax, val);
					lmin = min(lmin, val);
					val = left[m] - right[n];
					lmax = max(lmax, val);
					lmin = min(lmin, val);
					val = left[m] * right[n];
					lmax = max(lmax, val);
					lmin = min(lmin, val);
				}
			}
		}
		return {lmax, lmin};
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	//vector<double> A = {3,4,5,1};
	vector<double> A = {1,1,-1,5};
	Solution sol;
	cout <<  sol.maxnum(A);


	return 0;
}
