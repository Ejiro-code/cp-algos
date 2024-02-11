//#include <bits/stdc++.h>
#include <iostream>

long long modex(long long x, long long y, long long z);

int main()
{
    // grabbing the number of datasets
    int c;
    std::cin >> c;

    while(c-- > 0)
    {
        
        long long x,y,n;
        std::cin >> x >> y >> n;


        long long z = modex(x, y, n);
        std::cout << z << std::endl;
        
        //reading final 0
        if(c == 0) std::cin >> c;
    }
}

// iterative solution
// runtime of O(log y) ?
// Idea:
/**
 * starting from 1 and working our way up
 * whilst y > 0
 * check if the LSB of y is 1 
 * If it is we multiply our result by the current power of x
 * regardless, as we continue to shift the bits, we also continue to square x
 * */ 
long long modex(long long x, long long y, long long z){
    long long res = 1;
    while(y > 0){
        if(y & 1){
            res = (res * x) % z;
        }
        x = x * x % z;
        y >>= 1;
    }
    return res;
}