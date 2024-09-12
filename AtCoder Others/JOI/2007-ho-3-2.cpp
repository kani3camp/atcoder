//
// Created by kani3camp on 2024-09-10.
//


#include <iostream>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <cmath>
using namespace std;


long pow(int base, int exp) {
    long result = 1;
    for (int i = 1; i <= exp; i++) {
        result *= base;
    }
    return result;
}

long dist(int x1, int y1, int x2, int y2) {
    return pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2);
}


int main() {
    int n;
    vector<int> x, y;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x_i, y_i;
        cin >> x_i >> y_i;
        x.push_back(x_i);
        y.push_back(y_i);
    }

    set<long> square_sizes;

    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            long dist_ij = dist(x[i], y[i], x[j], y[j]);
            auto it1 = square_sizes.lower_bound(dist_ij);
            if (it1 != square_sizes.end()) continue;
            for (int k = j + 1; k < n - 1; k++) {
                long dist_ik = dist(x[i], y[i], x[k], y[k]);
                auto it2 = square_sizes.lower_bound(dist_ik);
                if (it2 != square_sizes.end()) continue;
                // 直角二等辺三角形になっているか
                if (dist_ij == dist_ik) {
                    long dist_jk = dist(x[j], y[j], x[k], y[k]);
                    if (dist_jk != dist_ij + dist_ik) continue;
                } else if (dist_ij > dist_ik) {
                    if (dist_ij != 2 * dist_ik) continue;
                } else if (dist_ik > dist_ij) {
                    if (dist_ik == 2 * dist_ij) continue;
                } else { continue; }

                for (int l = k + 1; l < n; l++) {
                    long dist_il = dist(x[i], y[i], x[l], y[l]);
                    auto it3 = square_sizes.lower_bound(dist_il);
                    if (it3 != square_sizes.end()) continue;

                    if (dist_ij > dist_ik && dist_ik == dist_il) {
                        long dist_kl = dist(x[k], y[k], x[l], y[l]);
                        if (dist_ij != dist_kl) continue;
                        // ２本の対角線のそれぞれの中点が一致するか
                        if (x[i] + x[j] == x[k] + x[l] && y[i] + y[j] == y[k] + y[l]) { square_sizes.emplace(dist_ik);}
                    } else if (dist_ik > dist_ij && dist_ij == dist_il) {
                        long dist_jl = dist(x[j], y[j], x[k], y[k]);
                        if (dist_ik != dist_jl) continue;
                        if (x[i] + x[k] == x[j] + x[l] && y[i] + y[k] == y[j] + y[l]) { square_sizes.emplace(dist_ij);}
                    } else if (dist_il > dist_ij && dist_ij == dist_ik) {
                        long dist_jk = dist(x[j], y[j], x[k], y[k]);
                        if (dist_jk != dist_il) continue;
                        if (x[j] + x[k] == x[i] + x[l] && y[j] + y[k] == y[i] + y[l]) { square_sizes.emplace(dist_ij);}
                    }
                }
            }
        }
    }

    auto it = square_sizes.rbegin();
    if (it == square_sizes.rend()) {
        cout << 0 << endl;
    } else {
        cout << *it << endl;
    }

    return 0;
}
