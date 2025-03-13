#include<iostream>
using namespace std;
int calculate(int arr[],int size,int total)
{
    if(size == 0)
    return -1;
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum +=arr[i];
        if(sum >= total)
        {
            return i+1;
            break;
        }
    }
    if(sum < total)
    return 0;
}
int main()
{
    int r,u;
    cin>>r>>u;
    int arr[8]={2,8,3,5,7,4,1,2};
    int total=r*u;
    cout<<calculate(arr,8,total)<<endl;
}