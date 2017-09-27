#include <bits/stdc++.h>
#define bigGuy 100000000 
#define modGuy 1000000007


using namespace std;

int main() {
    vector<int> vec ;
    int n , ele ;
    
    cin >> n ;
    
    for(int i = 0 ; i < n ; i++)
    {
        cin >> ele ;
        vec.push_back(ele) ;
    }

    for(int i = 0 ; i < vec.size() ; i++)
    {
        cout << vec[i]<<" "  ;
    }
    cout << endl ;
    
	return 0;
}
