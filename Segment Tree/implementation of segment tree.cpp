#include<bits/stdc++.h>
using namespace std;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
 
void updateSegTree(int diff,int si,int sl,int sr,int i,vector<int>& seg){
    if(i<sl || sr<i){
        return;
    }
    seg[si]+=diff;
    int mid=sl+(sr-sl)/2;
    if(sl!=sr){
        updateSegTree(diff,2*si+1,sl,mid,i,seg);
        updateSegTree(diff,2*si+2,mid+1,sr,i,seg);
    }
}
 
int createSegTree(vector<int>& arr,int l,int r,int n,vector<int>& seg){
    if(l==r){
        seg[n]=arr[l];
        return seg[n];
    }
    int mid=l+(r-l)/2;
    int left=createSegTree(arr,l,mid,2*n+1,seg);
    int right=createSegTree(arr,mid+1,r,2*n+2,seg);
    seg[n]=left+right;
    return seg[n];
}
 
int getSum(int si,int sl,int sr,int l,int r,vector<int>& seg){
    if(l<=sl && sr<=r){
        return seg[si];
    }
    else if(sl>r || sr<l){
        return 0;
    }
    else{
        int mid=sl+(sr-sl)/2;
        int left=getSum(2*si+1,sl,mid,l,r,seg);
        int right=getSum(2*si+2,mid+1,sr,l,r,seg);
        return left+right;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //TxtIO;
    vector<int> arr={1,2,5,6,7,9};
    int n=arr.size();
 
    //create seg tree
    int segHeight=ceil(log2(n));
    int segSize=pow(2,segHeight+1)-1;
    vector<int> seg(segSize,0);
    createSegTree(arr,0,n-1,0,seg);
    for(int i=0;i<seg.size();i++){
        cout<<seg[i]<<" ";
    }cout<<endl;
 
    //get sum in range 2-4
    int sum=getSum(0,0,n-1,2,4,seg);
    cout<<"sum->"<<sum<<endl;
 
    //update arr & seg tree i=3 with arr[3]=14
    int i=3,val=14;
    int diff=val-arr[i];
    arr[i]=val;
    updateSegTree(diff,0,0,n-1,i,seg);
    for(int i=0;i<seg.size();i++){
        cout<<seg[i]<<" ";
    }cout<<endl;
    return 0;
}