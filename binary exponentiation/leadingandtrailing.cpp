#include <iostream>
#include <math.h>

#define ll long long

using namespace std;

//Will have to circle back to fully grasp reasoning for leading zeros

int trailing(ll x, ll y)
{
    int cap = 1000;
    int res = 1;
    while(y > 0)
    {
        if(y & 1)
            res *= x % cap;
        x = x * x % cap;
        y >>= 1;
    }
    return res % cap;
}

int main()
{
    int v;
    cin >> v;

    while(v--){
        ll x,y;
        cin >> x >> y;

        //obtaining the leading digits
        double long d = y * log10(x);
        d = pow(10, ((d) - floor(d)));
        d = floor(d * 100);

        int trail = trailing(x, y);

        //allows us to print leading zeros
        printf("%03d...%03d",(int)d, trail);
    }
}