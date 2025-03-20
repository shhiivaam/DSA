#include<iostream>
using namespace std;
int fact(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}
int main()
{
    int domain;
    cout<<"enter domain"<<endl;
    cin>>domain;
    int codomain;
    cout<<"enter codomain"<<endl;
    cin>>codomain;
cout<<"domain-> "<<fact(domain)<<endl;
cout<<"domain-> "<<fact(codomain)<<endl;
int ans=0;
int domain1=fact(domain);
int codomain2=(fact(codomain))*(fact(domain-codomain));
ans=domain1 / codomain2;
cout<<"Answer is-> "<<ans<<endl;


}