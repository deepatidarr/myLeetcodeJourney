class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int ele1;
        int ele2;
        int f1=0, f2=0;
        for(int i=0; i<n; ++i){
            if(f1==0 && nums[i]!=ele2){
                f1 = 1;
                ele1 = nums[i];
            }
            else if(f2==0 && nums[i]!=ele1){
                f2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1) f1++;
            else if(nums[i] == ele2) f2++;
            else{
                f1--; f2--;
            }
        }
        int c1=0, c2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==ele1) c1++;
            if(nums[i]==ele2) c2++;
        }
        if(c1 > n/3) res.push_back(ele1);
        if(c2 > n/3) res.push_back(ele2);
        return res;
    }
};
