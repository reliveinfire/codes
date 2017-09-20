#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
		int pos = m + n -1;
		int a = m-1, b = n-1;
		while(a>=0 || b>=0){
			int ll=INT_MIN, rr=INT_MIN;
			if (a>=0)
				ll = nums1[a];
			if (b>=0)
				rr = nums2[b];
			if (ll>rr){
				a--;
				nums[pos--]=ll;
			} else {
				b--;
				nums[pos--]=rr;
			}
		}
		return;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret;
	ret = sol.
	auto ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
