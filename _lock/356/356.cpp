#include "../../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        bool Reflect(vector<vector<int>>& points){
			unordered_set<pair<int,int>, pairhash> pts;
			int min_x = INT_MAX, max_x = INT_MIN;
			for (int i = 0 ; i < points.size() ; i++){
				int x = points[i][0];
				int y = points[i][1];
				if (x < min_x)
					min_x = x;
				if (x > max_x)
					max_x = x;
				pts.insert(pair<int,int>(x,y));
			}
			double mid = (min_x + max_x) / 2.0;
			for (auto iter = pts.begin() ; iter!=pts.end() ; iter++){
				pair<int,int> tt;
				if (iter->first < mid)
					tt.first = mid + mid - iter->first;
				else
					tt.first = mid - (iter->first - mid);
				tt.second = iter->second;
				auto ff = pts.find(tt);
				if (ff==pts.end())
					return false;
			}
			return true;
        }
	private:
		struct pairhash{
			size_t operator()(const pair<int,int>& a)const {
				return a.first ^ a.second;
			}
		};
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<vector<int>> point{{1,1},
				   {-1,1}};
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret = sol.Reflect(point);
	cout << ret << "\n";


	return 0;
}
