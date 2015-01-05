//solution 1
int removeElement(int A[], int n, int elem) {
    int i=0, j=0;
    for(int i=0; i<n; i++)
    {
        if(A[i] != elem)
        {
            A[j++] = A[i];
        }
    }
    return j;
}
    
//solution 2
int removeElement(int A[], int n, int elem) {
    int i=0, j=n-1;
    while(i <= j)
    {
        if(A[i] == elem)
        {
            A[i] = A[j];
            j--;
        }
        else
            i++;
    }
    return j+1;
}
