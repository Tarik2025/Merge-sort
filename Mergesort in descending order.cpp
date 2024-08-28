#include<iostream>
#include<vector>
using namespace std;
void merging(vector<int>&v,vector<int>&v2,vector<int>&res)
{
    int i=0,j=0, k=0;
 while(i<v.size()&& j<v2.size())
 {

    if(v[i]>=v2[j]) res[k++]=v[i++];
    else res[k++]=v2[j++];

 }
 if(i==v.size())
 {
     while(j<=v2.size()-1)
     {
         res[k++]=v2[j++];
     }
 }
   if(j==v2.size())
 {
     while(i<=v.size()-1)
     {
         res[k++]=v[i++];
     }
 }
}
void mergesort(vector<int>&g)
{

  int n=g.size();
  if(n<=1) return;
  int a=n/2;
  int b=n-n/2;
 vector<int>arr(a),arr2(b);
 vector<int>res(n);
  for(int i=0;i<a;i++)
  {
      arr[i]=g[i];
  }
  for(int i=0;i<b;i++)
  {
      arr2[i]=g[i+a];
  }
  mergesort(arr);
  mergesort(arr2);
  merging(arr,arr2,g);
  arr.clear();
  arr2.clear();


}
int main()
{
    int arr[]={5,1,2,9,8,0,3};
    //int arr2[]={3,5,6,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    //int m=sizeof(arr2)/sizeof(arr2[0]);
    //int s=m+n;
    vector<int>v(arr,arr+n);
    //vector<int>v2(arr2,arr2+m);
    //vector<int>res(s);
   // merging(v,v2,res);
    mergesort(v);
     for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
