//source http://stackoverflow.com/questions/11681114/min-no-of-moves-to-sort-an-array
#include <iostream>

using namespace std;

int move_count(int *a, int n) 
{
    int j = 0;
    while(j < n-1 && a[j+1] > a[j]) 
        ++j;
    
    if (j == n-1) return 0;   // the array is already sorted
    // min_val holds the smallest element in the array after
    // the currently investigated position, v_1 holds the smallest
    // element after the current position that is larger than any later
    int max_val = a[j], v_1 = a[j+1];
    
    j += 2;
    while(j < n) 
    {
        if (a[j] > max_val) 
        {
            max_val = a[j];
        } 
        else if (a[j] > v_1) 
        {
            v_1 = a[j];
        }
        ++j;
    }
    cout << v_1 << "\t" << max_val << endl;
    
    int count_smaller = 0;
    for(j = 0; j < n; ++j) 
    {
        if (a[j] <= v_1) ++count_smaller;
    }
    return count_smaller;
}

int main()
{
    
    int A[] = {10, 12, 14, 1, 2, 4, 17, 20, 5, 3, 6, 11};
    cout << move_count(A, sizeof(A)/sizeof(int)) << endl;
   
   return 0;
}

