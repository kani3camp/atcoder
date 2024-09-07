//
// Created by kani3camp on 2024/09/07.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const string DREAM = "dream";
const string ERASE = "erase";
const string ER_DREAM = "erdream";
const string ER_ERASE = "ererase";
const string ER = "er";
const string R = "r";

int main()
{
    string S;
    cin>>S;

    long long pos = 0;
    while (true)
    {
        if (pos == S.size()) {
            cout<<"YES"<<endl;
            return 0;
        }

        if (equal(DREAM.begin(), DREAM.end(), S.begin() + pos)) {
            pos = pos + DREAM.size();
            if (pos == S.size()) {
                cout << "YES" << endl;
                return 0;
            }
            if (equal(DREAM.begin(), DREAM.end(), S.begin() + pos)) {
                continue;
            } else if (equal(ER_DREAM.begin(), ER_DREAM.end(), S.begin() + pos)) {
                pos = pos + ER.size();
                continue;
            } else if (equal(ERASE.begin(), ERASE.end(), S.begin() + pos)) {
                continue;
            } else if (equal(ER_ERASE.begin(), ER_ERASE.end(), S.begin() + pos)) {
                pos = pos + ER.size();
                continue;
            } else if (equal(ER.begin(), ER.end(), S.begin() + pos)) {
                pos = pos + ER.size();
                continue;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (equal(ERASE.begin(), ERASE.end(), S.begin() + pos)) {
            pos = pos + ERASE.size();
            if (pos == S.size()) {
                cout << "YES" << endl;
                return 0;
            }
            if (equal(R.begin(), R.end(), S.begin() + pos)) {
                pos = pos + R.size();
                continue;
            } else if (equal(ERASE.begin(), ERASE.end(), S.begin() + pos)) {
                continue;
            } else if (equal(DREAM.begin(), DREAM.end(), S.begin() + pos)) {
                continue;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}