#include <bits/stdc++.h>
#define bigGuy 100000000 
#define modGuy 1000000007
using namespace std; 
int main()
{
   vector<int> vec ;
   int n = 100 ;
   
   for (int i = 0 ; i <= n ; i++)
   {
     vec.push_back(1) ;
   }
   
   for (int i = 2 ; i < n ; i++ )
   {
     for (int j = i ; i*j <=  n ; j ++ )
     {
        if(vec[i*j] == 1)
        {
          vec[i*j] = 0 ; 
        }
     }
   }

   for (int i = 2 ; i <= n ; i++)
   {
      if(vec[i] == 1)
      {
        cout << i <<" " ;
      }
   }
   
  return 0 ;
}  
