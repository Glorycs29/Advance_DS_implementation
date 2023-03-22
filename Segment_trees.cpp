#include<bits/stdc++.h>
using namespace std;
int arr[]={11, 22, 110, 13, 21, 20, 41, 5, 4, 12};
int n = sizeof(arr)/sizeof(arr[0]);
//vector<int>(4*n,0);
    

int build(vector<int> &tree, int l, int h, int index, int arr[]){ // array //vertex//t_low//t_high
    if(l>h) return 0;
    if(l==h){
        // leaf node 
       return tree[index]=arr[l];
    }
        int mid = (l+h)/2;
        return tree[index]= build(tree, l, mid, 2*index+1, arr) + build(tree, mid+1, h, 2*index+2, arr);
    
}

int query(vector<int> &tree, int lt, int ht, int l, int h, int index){
    if(l>ht || h<lt) return 0;
    if(l<=lt && h>=ht) return tree[index]; // leaf node(left==right)
    int mid = (lt+ht)/2; // mid 
    return query(tree, lt, mid, l, h, 2*index+1) + query(tree, mid+1, ht, l, h, 2*index+2);
}


signed main(){
    
    
    // for buiding segment tree we have to use buid function
    // which will store the sum over a range into node of segment tree in form of array
    // with 1-indexing left child sof vertex at index i is stored at index 2i,
    // and right one at index 2i+1.
    // Equivalently the parent of vertex at index i is stored at i/2;
    // we do not need to store the structure of tree in memory.
    // it is defined implicitly.
    // we only need ine array which contains the sum of all segments.

    // to store segment sums in array we need to create an array of 4*n size .
    // the values might be less, but for convenience we always an arra of size 4*n

    // IMPLEMENTATION : ⭐⭐⭐
    vector<int> tree(4*n,0);

    build(tree, 0, n-1, 0, arr);
    for(int i=0;i<4*n;i++){
        cout<<i<<" : "<<tree[i]<<" , ";
    }
    cout<<"\n";
    
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans= query(tree,0,n-1,l,r,0);
        cout<<"sum of range "<<l<<" to "<<r<<" is: "<<ans<<"\n";
    }

}