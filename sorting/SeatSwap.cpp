#include <iostream>
#include <vector>
using namespace std;

void seatswap(vector<int> &array)
{
  const int n = array.size();
  if(n <= 2) return;
  
  int value1, value2;
  for(int i=0; i<n-1; i+=2)
  {
  	value1 = array[i];
  	value2 = array[i+1];
  	if(value1 != value2)
  	{
	  	for(int j=i+2; j<n; j++)
	  	{
	  		if(array[j] == value1)
	  		swap(array[i+1], array[j]);
	  	}
	}
  }
}

int main()
{
	int A[] = {1,2,3,4,5,1,2,3,4,5};
	vector<int> AA(A, A+sizeof(A)/sizeof(int));
	seatswap(AA);
	
	for(int i=0; i<AA.size(); i++)
	{
		cout << AA[i] << endl;
	}
	return 0;
}
