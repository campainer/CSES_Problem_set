#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<pair<int,int>,int>> project(n);
    vector<int> nums;
    for(auto& x:project){
        scanf("%d%d%d",&x.first.first,&x.first.second,&x.second);
        nums.push_back(x.first.first);
        nums.push_back(x.first.second);
    }
    sort(nums.begin(),nums.end());
    int j=1;
    for(int i=1;i<2*n;i++){
        if(nums[i]!=nums[i-1])nums[j++]=nums[i];
    }
    unordered_map<int,int> m;
    for(int i=0;i<j;i++)m[nums[i]]=i;
    vector<vector<pair<int,bool>>> a(j,vector<pair<int,bool>>());
    for(auto& x:project){
        x.first.first=m[x.first.first];
        x.first.second=m[x.first.second];
        a[x.first.first].push_back({x.second,true});
        a[x.first.second].push_back({x.second,false});
    }
    
    return 0;
}