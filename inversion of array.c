#include<iostream>
#include<vector>
using namespace std;
int inversion(vector<int>&arr,vector<int>&arr2){
    int i=0;
    int j=0;
    int count=0;
    while(i<arr.size()&& j<arr2.size()){
        if(arr[i]>=2*arr2[j]){
            count+=(arr.size()-i);
            j++;
        }
        else
        {

            i++;
        }
    }
    return count;
    }
void merging(vector<int>&v,vector<int>&v2,vector<int>&res)
{
    int i=0,j=0, k=0;
 while(i<v.size()&& j<v2.size())
 {

    if(v[i]<=v2[j]) res[k++]=v[i++];
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
int mergesort(vector<int>&g)
{
  int count=0;
  int n=g.size();
  if(n==1) return 0;
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
  count+=mergesort(arr);
  count+=mergesort(arr2);
  count +=inversion(arr,arr2);
  merging(arr,arr2,g);
  arr.clear();
  arr2.clear();
  return count;

}
int main()
{
    int arr[]={5,1,3,0,4,9,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(arr,arr+n);
    cout<<mergesort(v);


}

