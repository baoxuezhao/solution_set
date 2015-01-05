class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> line1(rowIndex+1, 1);
        vector<int> line2(rowIndex+1, 1);
        
        for(int i=1; i<=rowIndex; i++)
        {
            line2[0] = 1;
            for(int j=1; j<i; j++)
            {
                line2[j] = line1[j-1]+line1[j];
            }
            line2[i] = 1;
            swap(line1, line2);
        }
        return line1;
    }
};
