class Solution {
public:

    set<string> multiply(set<string>& a, set<string>& b) {
        set<string> ans;

        for (string x : a) {
            for (string y : b) {
                ans.insert(x + y);
            }
        }

        return ans;
    }

    set<string> solve(string& s, int& i) {
        set<string> result;
        set<string> current;

        current.insert("");

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                // Union current result into result
                for (string x : current) {
                    result.insert(x);
                }

                current.clear();
                current.insert("");

                i++;
            }
            else {
                set<string> next;

                if (s[i] == '{') {
                    i++; // skip '{'

                    next = solve(s, i);

                    i++; // skip '}'
                }
                else {
                    // Single character
                    next.insert(string(1, s[i]));
                    i++;
                }

                // Concatenate current × next
                current = multiply(current, next);
            }
        }

        // Add the last part
        for (string x : current) {
            result.insert(x);
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};