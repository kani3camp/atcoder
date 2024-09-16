//
// Created by kani3camp on 2024/09/14.
//


#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <limits>

using namespace std;

int main()
{
    long N;
    cin >> N;

    long X[N];
    long P[N];
    for (long i = 0; i < N; i++)
    {
        cin >> X[i];
    }
    for (long i = 0; i < N; i++)
    {
        cin >> P[i];
    }
    long Q;
    cin >> Q;
    long L[Q], R[Q];
    for (long i = 0; i < Q; i++)
    {
        cin >> L[i] >> R[i];
    }

    set<pair<long, long> > popul;   // 累積和
    long long cumlative = 0;
    for (long i = 0; i < N; i++)
    {
        cumlative += P[i];
        popul.insert(make_pair(X[i], cumlative));
    }

    for (long i = 0; i < Q; i++)
    {
        auto lower_pair = make_pair(L[i], numeric_limits<long>::min());
        auto upper_pair = make_pair(R[i], numeric_limits<long>::max());
        auto low_it = popul.lower_bound(lower_pair);
        long L_sum = 0;
        if (low_it != popul.begin()) L_sum = (--low_it)->second;
        auto up_it = popul.upper_bound(upper_pair);
        long R_sum = 0;
        if (up_it == popul.begin()) R_sum=0;
        else R_sum = (--up_it)->second;

        cout << (R_sum - L_sum) << endl;
    }

    return 0;
}