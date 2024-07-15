// 2024-07-15 Monday 10:37:37
// [中等] 721. 账户合并

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class DS {
  public:
    DS(int size) {
        p.resize(size);
        std::iota(begin(p), end(p), 0);
    }

    int parent(int i) { return p[i] == i ? i : (p[i] = parent(p[i])); }

    void merge(int i, int j) { p[parent(j)] = parent(i); }

  private:
    vector<int> p;
};

class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        using std::begin;
        using std::end;
        using std::next;
        // Assign id to emails
        int id = 0;
        unordered_map<string, int> emailId;
        unordered_map<int, string> emailOwner;

        for (const auto& entry : accounts) {
            for (auto it = next(begin(entry)); it != end(entry); ++it) {
                if (emailId.count(*it) == 0) {
                    emailOwner[id] = entry[0];
                    emailId[*it] = id++;
                }
            }
        }

        // Merge
        DS ds{id};
        for (const auto& entry : accounts) {
            auto start = next(begin(entry));
            for (auto it = start; it != end(entry); ++it) {
                ds.merge(emailId[*it], emailId[*start]);
            }
        }

        // Sort
        unordered_map<int, vector<string>> merged;
        for (const auto& [email, notused] : emailId) {
            merged[ds.parent(emailId[email])].push_back(email);
        }
        vector<vector<string>> res;
        for (auto& [groupid, emails] : merged) {
            std::sort(begin(emails), end(emails));
            res.push_back({emailOwner[groupid]});
            for (const auto& e : emails) {
                res.back().push_back(e);
            }
        }

        return res;
    }
};

int main() {
    vector<vector<string>> v = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                {"John", "johnsmith@mail.com", "john00@mail.com"},
                                {"Mary", "mary@mail.com"},
                                {"John", "johnnybravo@mail.com"}};

    Solution().accountsMerge(v);
}