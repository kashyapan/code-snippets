#include <bits/stdc++.h>

using namespace std;
//bitset<32>(n) -- To display in binary

int flipLSB(unsigned int n);
int twosComplement(unsigned int n);
int getParent(unsigned int n) ;
int getNext(unsigned int n);
void buildFedwick(int orgArr[] , int arr[], int n);
//0 based index in original array
void updateFedwick(int orgArr[] , int  arr[]  , int index , int value , int n) ;
int getSum(int arr[] , int k) ;


int main()
{
  
  int orgArr[] =  {3,2,-1,6,5,4,-3,3,7,2,3} ;
  int *arr ;
  
  int n  = sizeof(orgArr) / sizeof(orgArr[0]) + 1  ;
  
  arr = new int[n+1] ;

  buildFedwick(orgArr, arr , n) ;

  cout << getSum(arr  , 5)<<endl  ;
  //Change index 2 to 1  
  updateFedwick(orgArr,arr, 2 , 1 ,  n) ;
  
  cout << getSum(arr  , 5)<<endl  ;

  delete arr ;
  
  
  
  
  return 0 ;
}



int flipLSB(unsigned int n)
{
  return (n&(n-1)) ;
}

int twosComplement(unsigned int n)
{
  int temp = n ;
  temp = (~temp) ;
  temp ++ ; 
  return temp ;
}

int getParent(unsigned int n)
{
  unsigned int temp = twosComplement(n);
  temp = temp&n ;
  return (n-temp) ;
}

int getNext(unsigned int n)
{
  unsigned int temp = twosComplement(n);
  temp = temp & n ;
  return (n+temp) ;
}

//Takes O(nlogn)
void buildFedwick(int orgArr[] , int arr[], int n)
{
  int nextNode ;

  for(int i = 1 ; i <= n ; i++)
  {  
    nextNode = i ;
    
    while  (nextNode <= n)
    {
      arr[nextNode] += orgArr[i-1] ;
      nextNode = getNext(nextNode);
    }
  }
  
}

int getSum(int arr[] , int k)
{
  int sum = 0 ;  

  while(k != 0)
  {
    sum += arr[k] ;
    k = getParent(k) ;    
  }  
  
  return sum ;
}

//0 index `
void updateFedwick(int orgArr[] , int  arr[]  , int index , int value , int n) 
{
    int diff =  value - orgArr[index]  ;
    int nextNode = index + 1 ;
    
    while (nextNode <= n)
    {
      arr[nextNode] += diff ;
      nextNode = getNext(nextNode) ;
    }
    
}
