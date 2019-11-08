class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int s=numbers.size();
        if(s<1)
            return 0;
        int hs=s/2;
        sort(numbers.begin(),numbers.end());
        for(int i=0;i+hs<s;i++)
            if(numbers[i]==numbers[i+hs])
                return numbers[i];
        return 0;
    }
};
