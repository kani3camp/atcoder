//
// Created by kani3camp on 2024/09/08.
//
#include <iostream>
using namespace std;

int main()
{
    string S;
    cin>>S;

    int max=0;
    int current_seq = 0;
    for(const char i : S)
    {
        if (i=='A' || i=='C' || i=='G' || i=='T')
        {
            current_seq++;
            if (current_seq>max) max=current_seq;
        }
        else current_seq = 0;
    }

    cout<<max<<endl;
    return 0;
}