class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        string temp;
        int count = 0, index = 0;

        while(index < s.size())
        {
            if(s[index] == ' ')
            {
                int pos = temp[temp.size() - 1] - '0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                count++;
            }
            else
            {
                temp += s[index];
            }
            index++;
        }

        // Last word ke liye (kyunki sentence ke end me space nahi hota)
        int pos = temp[temp.size() - 1] - '0';
        temp.pop_back();
        ans[pos] = temp;
        temp.clear();
        count++;

        // Final result string build karna
        temp = "";
        for(int i = 1; i <= count; i++)
        {
            temp += ans[i];
            temp += ' ';
        }

        temp.pop_back(); // Extra trailing space remove karne ke liye
        return temp;
    }
};