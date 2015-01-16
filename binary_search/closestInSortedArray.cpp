int FindNearestNum(int* arr, int len, int n)
{
    if(len == 1) return arr[0];
    if(n < arr[0]) return arr[0];
    if(n > arr[len - 1]) return arr[len - 1];

    int low = 0;
    int up = len - 1;

    int res;
    int gap = INT_MAX;

    while(low <= up){
        int mid = low + (up - low) / 2;

        if(arr[mid] == n){
            return n;
        }
        
        if(abs(arr[mid]-n) < gap)
        {
            res = arr[mid];
            gap = abs(arr[mid]-n);
        }
        if(arr[mid] > n){
            up = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return res;
    //return abs(arr[low] - n) > abs(arr[up] - n) ? arr[up] : arr[low];
}
