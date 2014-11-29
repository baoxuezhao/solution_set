#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int partition(int A[], int s, int e)
{
	int len = e-s+1;
	int pivot = A[rand()%(e-s+1)+s];

	int left = s, right = e;

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

	return left-1;
}

void quicksort(int A[], int s, int e)
{
	int index = partition(A, s, e);
	if(s < index)
		quicksort(A, s, index);
	if(index+1 < e)
		quicksort(A, index+1, e);
}

int lower_bound(int A[], int n, int target)
{
	int left = 0, right = n-1;
	while(left <= right)
	{
		int mid = left + (right-left)/2;
		if(A[mid] >= target)
			right = mid-1;
		else
			left = mid+1;
	}
	return right+1;
}

int bsearch(int A[], int m, int B[], int n, int target)
{
	int lower_a = lower_bound(A, m, target);
	int lower_b = lower_bound(B, n, target);

	return lower_a + lower_b;
}


int main()
{
    int n = 500;
    int A[n];
    int B[n];
    int C[2*n];
    for(int i=0; i<n; i++)
    {
        A[i] = rand()%10000;
        B[i] = rand()%10000;

        C[i*2]   = A[i];
        C[i*2+1] = B[i];
    }

    quicksort(A, 0, n-1);
    quicksort(B, 0, n-1);
    quicksort(C, 0, 2*n-1);

 	for(int i=0; i<2*n; i++)
 	{
 		int target = C[i];
 		int index = bsearch(A, n, B, n, target);
 		if(C[i] != C[index])
 			cout << i << "\t" << index << endl;
 	}

    return 0;
}
