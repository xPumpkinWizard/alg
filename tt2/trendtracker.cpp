#include "trendtracker.h"

Trendtracker::Trendtracker(string filename) {
    ifstream file(filename);
    string hashtag;

    while (file >> hashtag) {
        Entry entry;
        entry.hashtag = hashtag;
        entry.pop = 0;
        E.push_back(entry);
    }
    file.close();
}

int Trendtracker::size() {
    return E.size();
}

int Trendtracker::search(string ht) {
    int left = 0;
    int right = E.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (E[mid].hashtag == ht) {
            return mid;
        }
        else if (E[mid].hashtag < ht) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

void Trendtracker::tweeted(string ht) {
    int index = search(ht);
    if (index != -1) {
        E[index].pop++;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == index) {
                S.erase(S.begin() + i);
                break;
            }
        }

    int newS = 0;
        while (newS < S.size() && E[S[newS]].pop > E[index].pop) {
            newS++;
        }
        S.insert(S.begin() + newS, index);

        if (S.size() > 3) {
            S.pop_back();
        }
    }
}

int Trendtracker::popularity(string name) {
    int index = search(name);
    if (index != -1) {
        return E[index].pop;
    }
    return -1;
}

string Trendtracker::top_trend() {
    if (S.empty()) {
        return "";
    }
    return E[S[0]].hashtag;
}

void Trendtracker::top_three_trends(vector<string> &T) {
    T.clear();
    for (int i : S) {
        T.push_back(E[i].hashtag);
    }
    while (T.size() < 3 && T.size() < E.size()) {
        T.push_back(E[T.size()].hashtag);
    }
}
