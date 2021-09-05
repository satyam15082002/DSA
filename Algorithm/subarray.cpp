#include<iostream>
#include<cmath>
using namespace std;
void printSubArray(int A[],int N);//O(N^3)
void printAllSubArraySum(int A[],int N);//O(N^2)
void pairWithSum(int A[],int N,int S);//O(N)
void maxSubArraySum1(int A[],int N);//O(N^3)
void maxSubArraySum2(int A[],int N);//O(N^2)
void kadane(int A[],int N);//O(N)
void pairSum(int A[],int N,int target);//O(N)
int main()
{
    int A[]={2,4,7,11,14,16,20,21};
    pairSum(A,8,31); 
    return 0;
}
void printSubArray(int A[],int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=i;j<N;j++)
        {
            for(int k=i;k<=j;k++)
                cout<<A[k]<<" ";
            cout<<endl;
        }
    }
}
void printAllSubArraySum(int A[],int N)
{
    for(int i=0;i<N;i++)
    {
        int curr=0;
        for(int j=i;j<N;j++)
        {
            curr+=A[j];
            cout<<curr<<endl;
        }
    }
}
void pairWithSum(int A[],int N,int S)
{
    int s=-1,e=-1,sum=0;
    for(int i=0;i<N;i++)
    {
        sum+=A[i];
        if(s==-1)
        {
            ++s;
            ++e;
        }
        else
            ++e;
        while(sum>S&&s<=e)
        {
            sum-=A[s];
            s++;
        }
        if(sum==S) break;
    }
    if(sum==S)
    {
        cout<<s+1<<" "<<e+1<<endl;
    }
    else
        cout<<-1<<endl;
}
void maxSubArraySum1(int A[],int N)
{
    int mx=0;
    for(int i=0;i<N;i++)
        for(int j=i;j<N;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
                sum+=A[k];
            mx=max(mx,sum);
        }
    cout<<mx<<endl;
}
void maxSubArraySum2(int A[],int N)
{
    int mx=0;
    for(int i=0;i<N;i++)
    {
        int sum=0;
        for(int j=i;j<N;j++)
        {
            sum+=A[j];
            mx=max(mx,sum);
        }
    }
    cout<<mx<<endl;
}
void kadane(int A[],int N)
{
    int max_global,max_curr;
    max_global=max_curr=0;
    for(int i=0;i<N;i++)
    {
        max_curr=max(A[i],max_curr+A[i]);
        if(max_curr>max_global)
            max_global=max_curr;
    }
    cout<<max_global<<endl;
}
void pairSum(int A[],int N,int target)
{
    int low=0,high=N-1,sum=0;
    while(low<high)
    {
        sum=A[low]+A[high];
        if(sum==target)
            break;
        else if(sum>target)
            --high;
        else
            ++low;
    }
    if(sum==target)
        cout<<low<<"\t"<<high;
    else
        cout<<"Not Found"<<endl;
}
