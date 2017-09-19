#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        private:
                struct comp{
                        vector<int> n1;
                        vector<int> n2;
                        comp(const vector<int>& i1, const vector<int>& i2){
                                n1 = i1; n2 = i2;
                        }
                        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const{
                                return  n1[a.first] + n2[a.second] > n1[b.first] + n2[b.second];
                        }
                };
        public:
        vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
                vector<pair<int,int>> res;
		vector<vector<int>> used(nums1.size(), vector<int>(nums2.size()));
                if (nums1.empty() || nums2.empty())
                        return res;
                if (k>nums1.size() * nums2.size())
                        k = nums1.size() * nums2.size();
                priority_queue<pair<int,int>, vector<pair<int,int>>, comp> heap(comp(nums1,nums2));
                heap.push(pair<int,int>(0,0));
		used[0][0] = 1;
                while(res.size() < k){
                        pair<int,int> tt = heap.top();
                        heap.pop();
			int a = tt.first;
			int b = tt.second;
                        res.push_back(pair<int,int>(nums1[a],nums2[b]));
                        if (a + 1 < nums1.size() && !used[a+1][b]){
                                heap.push(pair<int,int>(a+1, tt.second));
				used[a+1][b] = 1;
                        }
                        if (b + 1 < nums2.size() && !used[a][b+1]){
                                heap.push(pair<int,int>(a, b+1));
				used[a][b+1] = 1;
                        }
                }
                return res;
        }
};


#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,1,2};
	vector<int> B = {1,2,3};
	Solution sol;
	auto ret_vec = sol.kSmallestPairs(A,B,10);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i].first<<":" << ret_vec[i].second << endl;
	cout <<endl;

	return 0;
}
