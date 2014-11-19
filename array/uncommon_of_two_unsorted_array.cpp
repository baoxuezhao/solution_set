vector<int> find(vector<int> &A, vector<int> &B)
{
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());

	int idx1=0, idx2=0;
	vector<int> result;
	while(idx1 < A.size() || idx2 < B.size())
	{
		int val1 = (idx1 < A.size())? A[idx1]: INT_MAX;
		int val2 = (idx2 < B.size())? B[idx2]: INT_MAX;

		if(val1 < val2)
		{
			result.push_back(val1);
			do{
				idx1++;
			}while(idx1 < A.size() && A[idx1] == val1);
		}
		else if(val1 > val2)
		{
			result.push_back(val2);
			do{
				idx2++;
			}while(idx2 < B.size() && B[idx2] == val2);
		}
		else
		{
			do{
				idx1++;
			}while(idx1 < A.size() && A[idx1] == val1);

			do{
				idx2++;
			}while(idx2 < B.size() && B[idx2] == val2);
		}
	}
	return result;
}
