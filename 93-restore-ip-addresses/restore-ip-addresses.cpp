class Solution {
public:
    vector<string> ans;

    void solve(string s, int index, int count, string ip) {
        if (count == 4 && index == s.size()) {
            ip.pop_back();
            ans.push_back(ip);
            return;
        }

        if (count == 4 || index == s.size()) {
            return;
        }

        string part = "";

        for (int i = index; i < s.size() && i < index + 3; i++) {
            part += s[i];

            if (part.size() > 1 && part[0] == '0') {
                continue;
            }

            if (stoi(part) <= 255) {
                solve(s, i + 1, count + 1, ip + part + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0, "");
        return ans;
    }
};
