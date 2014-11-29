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

int select_kth(int A[], int s, int e, int k)
{
	int left_last = partition(A, s, e);

	int left_index = left_last - s;

	if(k == left_index)
		return A[left_last];
	else if(left_index > k)
		return select_kth(A, s, left_last, k);
	else
		return select_kth(A, left_last+1, e, k-(left_index+1));
}

void quicksort(int A[], int s, int e)
{
	int index = partition(A, s, e);
	if(s < index)
		quicksort(A, s, index);
	if(index+1 < e)
		quicksort(A, index+1, e);
}

int main()
{
    int n = 500000;
    int a[n];
    int b[n];
    for(int i=0; i<n; i++)
    {
        a[i] = rand()%10000;
        b[i] = a[i];
    }
    cout << endl;

    sort(b, b+n);

    /*
    for(int i=0; i<n; i++)
    {
        if(select_kth(a,0,n-1,i) != b[i])
        	cout << "error " << endl;
    }*/

    quicksort(a, 0, n-1);
    for(int i=0; i<n; i++)
    {
    	if(a[i] != b[i])
    		cout << "error " << endl;
    }
    return 0;
}
