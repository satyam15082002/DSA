#include<iostream>
using namespace std;
int getBit(int n,int pos);//O(1)
int setBit(int n,int pos);//O(1)
int clearBit(int n,int pos);//O(1)
int updateBit(int n,int pos,int val);//O(1);
bool isPowerOf2(int n);//O(1)
int twosComplement(int n);//O(1)
int numberOfOnes(int n); //O(1)
void printSubsets(int A[],int n );//O(n)
int main()
{
    int A[]={1,2,3};
    printSubsets(A,3);
    return 0;
}
int getBit(int n,int pos)
{
    return (n&(1<<pos))!=0;
}
int setBit(int n,int pos)
{
    return n|(1<<pos);
}
int clearBit(int n,int pos)
{
    int mask=~(1<<pos);
    return n&mask;
}
int updateBit(int n,int pos,int val)
{
    int mask=~(1<<pos);
    n=n&mask;
    return n|(val<<pos);
}
bool isPowerOf2(int n)
{
    return (n&&!(n&(n-1)));
}
int twosComplement(int n)
{
    return (~n)+1;
}
int numberOfOnes(int n)
{
    int count=0;
    while(n)
    {
        n=n&(n-1);
        ++count;
    }
    return count;
}
void printSubsets(int A[],int n )
{
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                cout<<A[j]<<"\t";
            }
        }
        cout<<endl;
    }
}
