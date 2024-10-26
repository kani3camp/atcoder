//
// Created by kani3camp on 2024-10-26.
//


#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    long N, M; cin >> N >> M;

    set<pair<long, long> > x;
    set<pair<long, long> > area = {
        make_pair(2, 1),
        make_pair(1, 2),
        make_pair(-1, 2),
        make_pair(-2, 1),
        make_pair(-2, -1),
        make_pair(-1, -2),
        make_pair(1, -2),
        make_pair(2, -1)
    };

    for (long i = 0; i < M; i++) {
        long a, b; cin >> a >> b;
        x.insert(make_pair(a, b));
        for (auto point : area) {
            long area_a = a + point.first;
            if (area_a < 1 || area_a > N) continue;
            long area_b = b + point.second;
            if (area_b < 1 || area_b > N) continue;
            x.insert(make_pair(area_a, area_b));
        }
    }
    cout << static_cast<long long>(N)*N - x.size() << endl;
    return 0;
}