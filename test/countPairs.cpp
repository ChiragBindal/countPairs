#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &nums ,vector<int> &temp  ,int s , int mid , int e , int diff){
    int cnt = 0;
    for(int i=s ; i<=mid;i++){
        for(int j=mid ; j<=e ;j++){
            if((nums[i]-nums[j])<=diff) cnt++;
        }
    }
    int low = s;
     int high = mid+1;
    while((low<=mid-1) && (high<=e)){
       if(nums[low]<=nums[high]) temp.push_back(nums[low++]);
        else temp.push_back(nums[high++]);
    }
    while(low<=mid-1) temp.push_back(nums[low++]);
    while(high<=e) temp.push_back(nums[high++]);

    for(int i=s ; i<=e ; i++) nums[i] = temp[i-s];
    return cnt;
}

int mergeSort(vector<int> &nums , vector<int> &temp ,int low , int high ,int diff){
    if(low>=high) return 0;
    int mid = low + (high-low)/2;
    int count = mergeSort(nums ,temp, low , mid,diff);
    count += mergeSort(nums,temp,mid+1,high,diff);

    count += merge(nums,temp,low,mid,high,diff);
    return count;
}
int main(){
    int diff = -1;
    vector<int> nums(5);
    vector<int> temp;
    for(int i=0 ; i<5 ; i++) cin>>nums[i];
    int ans =  mergeSort(nums,temp,0,4,diff);
    cout<<ans<<endl;
}