#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int partition(int A[], int s, int e)
{
	int r = rand()%(e-s+1)+s;
	swap(A[r], A[e]);
	int pivot = A[e];
	int left = s, right = e-1;

	while(left <= right)
	{
		while(A[left] < pivot) left++;
		while(A[right] > pivot) right--;

		if(left <= right)
		{
			swap(A[left], A[right]);
			left++;
			right--;
		}
	}
	swap(A[left], A[e]);

	return left; //return the pivot idx
}

int select_kth(int A[], int s, int e, int k)
{
	int mid = partition(A, s, e);

	int mid_index = mid - s;

	if(k == mid_index)
		return A[mid];
	else if(mid_index > k)
		return select_kth(A, s, mid-1, k);
	else
		return select_kth(A, mid+1, e, k-(mid_index+1));
}

void quicksort(int A[], int s, int e)
{
	int mid = partition(A, s, e);
	if(s < mid-1)
		quicksort(A, s, mid-1);
	if(mid+1 < e)
		quicksort(A, mid+1, e);
}

int main()
{
    int n = 50000;
    int a[n];
    int b[n];
    for(int i=0; i<n; i++)
    {
        a[i] = rand()%1000000;
        b[i] = a[i];
    }
    cout << endl;

    sort(b, b+n);
    
    quicksort(a, 0, n-1);
    for(int i=0; i<n; i++)
    {
    	if(a[i] != b[i])
    		cout << "error " << endl;
    }
    
    return 0;
}
