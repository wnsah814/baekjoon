#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstring>
using namespace std;
using pi = pair<int, int>; // score, id
using vpi = vector<pi>;

vector<vector<vpi>> db;
vector<pair<int, pair<int, int>>> hashT; // id, grade, gender

int bs(int left, int right, int val) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (val < hashT[mid].first) {
            right = mid - 1;
        } else if (val > hashT[mid].first) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int bs2(int gr, int ge, int left, int right, int val) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (val < db[gr][ge][mid].second) {
            right = mid - 1;
        } else if (val > db[gr][ge][mid].second) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

bool cmp_des(const pi& a, const pi& b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first > b.first;
}

bool cmp_qry(const pi& a, const pi& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

bool cmp_id(const pi& a, const pi& b) {
    return a.second < b.second;
}

void init() {
    db = vector<vector<vpi>>(3, vector<vpi>(2));
	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
    int gen = strcmp("male", mGender) ? 1 : 0;
    db[mGrade - 1][gen].push_back({mScore, mId});
    hashT.push_back({mId, {mGrade - 1, gen}});
    sort(db[mGrade - 1][gen].begin(), db[mGrade - 1][gen].end(), cmp_des);
    return db[mGrade - 1][gen][0].second;
}

int remove(int mId) {
    sort(hashT.begin(), hashT.end());
    int idx = bs(0, hashT.size() - 1, mId);
    if (idx == -1) {
        return 0;
    }
    int gr = hashT[idx].second.first;
    int ge = hashT[idx].second.second;
    sort(db[gr][ge].begin(), db[gr][ge].end(), cmp_id);
    db[gr][ge].erase(db[gr][ge].begin() + bs2(gr, ge, 0, db[gr][ge].size() - 1, mId));
    sort(db[gr][ge].begin(), db[gr][ge].end(), cmp_qry);
    hashT.erase(hashT.begin() + idx);
	return (db[gr][ge].size() == 0) ? 0 : db[gr][ge][0].second;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
	vpi ans;
    for (int gr = 0; gr < mGradeCnt; ++gr) {
        int grade = mGrade[gr] - 1;
        if (mGenderCnt == 2) {
            for (int gender = 0; gender < 2; ++gender) {
                sort(db[grade][gender].begin(), db[grade][gender].end(), cmp_qry);
                auto it = lower_bound(db[grade][gender].begin(), db[grade][gender].end(), pi(mScore, 0)) - db[grade][gender].begin();
                if (db[grade][gender][it].first < mScore) continue;
                if (it >= 0 && db[grade][gender].size() > 0) {
                    ans.push_back(db[grade][gender][it]);
                }
            }
        } else {
            int gender = strcmp("male", mGender[0]) ? 1 : 0;
            sort(db[grade][gender].begin(), db[grade][gender].end(), cmp_qry);
            auto it = lower_bound(db[grade][gender].begin(), db[grade][gender].end(), pi(mScore, 0)) - db[grade][gender].begin();
            if (db[grade][gender][it].first < mScore) continue;
            if (it >= 0 && db[grade][gender].size() > 0) {
                ans.push_back(db[grade][gender][it]);
            }
        }
    }
    if (ans.size() == 0) {
        return 0;
    }
    sort(ans.begin(), ans.end(), cmp_qry);
    for (auto a : ans) {
    }
    return ans[0].second;
}