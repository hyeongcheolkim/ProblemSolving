//baekjoon 4153 ps

#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    while(1)
    {
        static array<double,3> arr={1.0,1.0,1.0};

        for(auto &e:arr)
            cin >> e;
        
        if(arr[0]==0.0 && arr[1]==0.0 && arr[2]==0.0)
            break;

        int max = *max_element(arr.begin(), arr.end());
        double sum=0;
        for(const auto &e:arr)
            if(e!=max)
                sum += pow(e, 2);
        
        if(pow(max,2)==sum)
            cout << "right" << endl;
        else
            cout << "wrong"<<endl;
        
    }

}