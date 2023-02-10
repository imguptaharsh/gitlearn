#include<iostream>
#include<vector>
using namespace std;
void multiply(vector<int>&arr , int &n,int m){
    int carry =0;
    for(int i=0;i<n;i++){
        int product=arr[i]*m +carry;
        arr[i]=product%10;
        carry=product/10;
    }
    while(carry){
        arr[n]=carry%10;
        carry/=10;
        n++;
    }
}
void big_fact(int number){
    vector<int>arr(1000,0);
    arr[0]=1;
    int n=1;
    for(int i=2;i<=number;i++){
        multiply(arr,n,i);
    }
    for(int i=n-1;i>=0;i++){
        cout<<arr[i];
    }
    cout<<endl;
    
}
int main(){
int n;
cin>>n;
big_fact(n);
return 0;
}
