#include "trendtracker.h"

Trendtracker::Trendtracker() {}

void Trendtracker::insert(string ht) {
    for (const auto& entry : E) {
        if (entry.hashtag == ht) {
            return;
        }
    }

    Entry newEntry;
    newEntry.hashtag = ht;
    newEntry.pop = 0;
    E.push_back(newEntry);
}

int Trendtracker::size() {
    return E.size();
}

void Trendtracker::tweeted(string ht) {
    for (auto& entry : E) {
        if (entry.hashtag == ht) {
            entry.pop++;
            return;
        }
    }
}

int Trendtracker::popularity(string name) {
    for (const auto& entry : E) {
        if (entry.hashtag == name) {
            return entry.pop;
        }
    }
    return -1;
}

string Trendtracker::top_trend() {
    if (E.empty()) {
        return "";
    }

    int maxPopularity = E[0].pop;
    string maxHashtag = E[0].hashtag;

    for (const auto& entry : E) {
        if (entry.pop > maxPopularity) {
            maxPopularity = entry.pop;
            maxHashtag = entry.hashtag;
        }
    }

    return maxHashtag;
}

void Trendtracker::top_three_trends(vector<string> &T) {
    T.clear();
    if (E.empty()) return;

    for (int i = 0; i < 3 && i < E.size(); ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < E.size(); ++j) {
            if (E[j].pop > E[maxIndex].pop) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            std::swap(E[i], E[maxIndex]);
        }
        T.push_back(E[i].hashtag);
    }
}

void Trendtracker::remove(string ht) {
    for (int i = 0; i < E.size(); ++i) {
        if (E[i].hashtag == ht) {
            E.erase(E.begin() + i);
            break;
        }
    }
}

void Trendtracker::top_k_trends(vector<string> &T, int k) {
    T.clear();
    if (E.empty()) return;

    for (int i = 0; i < k && i < E.size(); ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < E.size(); ++j) {
            if (E[j].pop > E[maxIndex].pop) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(E[i], E[maxIndex]);
        }
        T.push_back(E[i].hashtag);
    }
}
