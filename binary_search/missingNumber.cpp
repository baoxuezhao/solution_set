#include <iostream>
#include <vector>
using namespace std;

int findMissing(int A[], int n)
{
  int left = 0, right = n-1;
  while(left <= right)
  {
    int mid = left + (right-left)/2;
    if(left == right)
    {
      if(A[left] == left + 1)
        return left;
    }
    if(A[mid] == mid)
      left = mid+1;
    else if(A[mid] == mid+1)
      right = mid;
  }
  return n;
}


int main()
{
  int A1[] = {0};
  cout << findMissing(A1, 1) << endl;
  
  int A2[] = {1};
  cout << findMissing(A2, 1) << endl;
  
  int A3[20];
  
  for(int missing = 0; missing <= 20; missing++)
  {
    int curval = 0;
    for(int i=0; i<20; i++)
    {
      if(curval == missing) curval++;
      A3[i] = curval++;
    }
    cout << missing << "\t" << findMissing(A3, 20) << endl;
  }
  return 0;
}
