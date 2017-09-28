#include "../../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class RangeSum2D {
        public:
		RangeSum2D(vector<vector<int>>& matrix){
			mm.resize(matrix.size());
			for(vector<int>& vv : mm)
				vv.resize(matrix[0].size());
			bi.resize(matrix.size()+1);
			for (vector<int>& vv : bi)
				vv.resize(matrix[0].size()+1);
			for (int i = 0 ; i < mm.size() ; i++){
				for (int j = 0 ; j < mm[0].size() ; j++){
					mm[i][j] = matrix[i][j];
					biupdate(i, j, matrix[i][j]);
					//print();
				}
			}
		}
		int getSum(int srow, int scol, int lrow, int lcol){
			int res;
			res += bisum(lrow, lcol);
			if (srow-1 >=0 && scol -1 >=0)
				res += bisum(srow-1, scol-1);
			if (srow-1>=0)
				res -= bisum(srow-1, lcol);
			if (scol-1>=0)
				res -= bisum(lrow,scol-1);
			return res;
		}
		void update(int row, int col, int val){
			int old = mm[row][col];
			mm[row][col] = val;
			biupdate(row, col, val - old);
		}
		int bisum(int row, int col){
			row++;col++;
			int oldcol = col;
			int ret = 0;
			while (row>0){
				while(col>0){
					ret += bi[row][col];
					col = col - bidx(col);
				}
				col = oldcol;
				row = row - bidx(row);
			}
			return ret;
		}
		void biupdate(int row, int col,int up){
			int m = bi.size();
			int n = bi[0].size();
			row++;col++;
			int oldcol = col;
			while(row<m){
				while(col<n){
					bi[row][col] += up;
					col = col + bidx(col);
				}
				col = oldcol;
				row = row + bidx(row);
			}
		}
		void print(){
#if 1
			for (int i = 0 ; i <mm.size() ; i++){
				for (int j = 0 ; j < mm[0].size() ; j++){
					cout << mm[i][j] <<" ";
				}
				cout << endl;
			}
#endif

#if 0
			for (int i = 1 ; i <bi.size() ; i++){
				for (int j = 1 ; j < bi[0].size() ; j++){
					cout << bi[i][j] <<" ";
				}
				cout << endl;;
			}
			cout << "=================\n";
#endif
		}
		int bidx(int x){
			return x & (-x);
		}
	private:
		vector<vector<int>> mm;
		;vector<vector<int>> bi;

};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
#if 1
	vector<vector<int>> mm = { {1,2,3,4},
				   {4,3,2,1},
				   {1,2,3,4},
				   {4,3,2,1}
				};
#else
	vector<vector<int>> mm = { {1,2,3},
				   {4,3,2},
				   {1,2,3}
				};
#endif
	RangeSum2D rr(mm);
	rr.print();
	cout << rr.getSum(1,1,3,3) << endl;
	//cout << rr.getSum(0,0,2,2);
	cout << rr.getSum(0,2,3,3) << endl;
	

	return 0;
}
