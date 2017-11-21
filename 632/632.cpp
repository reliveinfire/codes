#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
struct Item{
	int val;
	int row;
	int idx;
	bool operator<(const Item& that) const{
		return val < that.val;
	}
	Item(int v, int r, int i): val(v),row(r),idx(i){}
};
class Solution {
        public:
        vector<int> smallestRange(vector<vector<int>>& nums){
		vector<int> res(2,0);
		multiset<Item> pq;
		
		for (int i = 0 ; i < nums.size() ; i++){
			pq.insert(Item(nums[i][0],i,0));
		}
		res[0] = pq.begin()->val;
		res[1] = (--pq.end())->val;
		while(true){
			auto tt = pq.begin();
			int tr = tt->row;
			int ti = tt->idx;
			pq.erase(tt);
			if (ti+1==nums[tr].size())
				break;
			else
				pq.insert(Item(nums[tr][ti+1],tr,ti+1));
			int mi = pq.begin()->val;
			int ma = (--pq.end())->val;
			if (ma-mi < res[1]-res[0]){
				res[0] = mi;
				res[1] = ma;
			}
		}
		return res;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<vector<int>> A = {{ 4,10,15,24,26},
			  	{0,9,12,20},
				  {5,18,22,30}
				};
	Solution sol;
	auto ret_vec = sol.smallestRange(A);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";

	return 0;
}
