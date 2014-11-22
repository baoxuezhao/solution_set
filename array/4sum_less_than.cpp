#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int fourSum(vector<int> &num, int target) 
{
    sort(num.begin(),num.end());
    for(int i=0;i<num.size();i++)
        cout<<num[i]<<" ";
    cout<<endl;
    int n=num.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(i && num[i]==num[i-1])
            continue;
        for(int j=i+1;j<n;j++)
        {
            if(j>i+1 && num[j]==num[j-1])
                continue;
            int lo=j+1;
            int hi=n-1;
            while(lo < hi)
            {    
                int sum=num[i]+num[j]+num[lo]+num[hi];
               
                if(sum<=target)
                {
                    for(int k=lo+1;k<=hi;k++)
                    {
                        if(k>lo+1 && num[k]==num[k-1])
                            continue;
                        count++;
                        cout << num[i] << " " << num[j] << " " <<num[lo] << " " <<num[k]<<endl;
                    }

                    do{
                        lo++;
                    }while(lo<hi && num[lo]==num[lo-1]);
                    
                }else if(sum>target)
                    hi--;
            }
        }
    }
    return count;
}

int main(){
    vector<int> num={1,2,4,5,2,6,8,1,1,9,12,34};
    int target=10;
    cout<<fourSum(num,target)<<endl;
    
}
