class Solution {
public:
int solver(vector<int>& nums,int start,int end){

    int flag=nums[start];
    int cnt=0;
    for(int i=start+1;i<=end;i++){
        if(nums[i]<=flag){
         cnt++;
          }
    }
    int pivotIndex=start+cnt;
    swap(nums[start],nums[pivotIndex]);
    int i=start;
    int j=end;
    while(i<pivotIndex && j>pivotIndex)

    {
        while(nums[i]<=nums[pivotIndex]){
        i++;
    }
    while(nums[j]>nums[pivotIndex]){
        j--;
    }
    if(i<pivotIndex && j>pivotIndex){
        swap(nums[i++],nums[j--]);
    }
    }

   return pivotIndex;
}
void quicksort(vector<int>& nums,int start,int end){
    if(start>=end){
        return;
    }

    int partition=solver(nums,start,end);
    quicksort(nums,start,partition-1);
    quicksort(nums,partition+1,end);
}
    void sortColors(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
         quicksort(nums,start,end);
        
    }
};