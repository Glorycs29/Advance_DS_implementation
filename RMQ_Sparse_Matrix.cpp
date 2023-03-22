#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]= {11,2,101,13,21,20,41,5,4,12,34,2,3,45,67,54,12,34,23,34,53,45,12,32};
    int n= 24;
    //count the bits in which n can be represented
    int m = ceil(log2(n));
    vector<vector<int>> dp(2*n, vector<int>(m,INT_MAX));
    //traversing over all bits
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(j==0){
                dp[i][j]=arr[i];
            }else{
                dp[i][j]=min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
//query
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int x = r-l+1, ans = INT_MAX, cur=1;
        for(int i=m-1;i>=0;i--){
            //set bit
            if((x&(1<<i))!= 0){
                ans = min(ans,dp[cur][i]);
                cur+=(1<<i);
            }
        }
        cout<<"Minimum of range"<<l<<" to "<<r<<" is: "<<ans<<"\n";
    }
    return 0;


}