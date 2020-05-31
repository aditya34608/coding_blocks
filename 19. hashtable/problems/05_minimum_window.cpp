#include <iostream>
#include <unordered_map>

using namespace std;

string minimum_window(string pattern, string sentence)
{
    int len_1 = pattern.size();
    int len_2 = sentence.size();

    if (len_1 < len_2)
    {
        return "No Window";
    }

    int hash_pattern[256] = {0};
    int hash_sentence[256] = {0};

    for (int i = 0; i < len_2; i++)
    {
        hash_sentence[pattern[i]]++;
    }

    int start = 0, count = 0, start_id = -1, min_len = INT_MAX;

    for (int j = 0; j < len_1; j++)
    {
        hash_sentence[sentence[j]]++;

        if (hash_pattern[sentence[j]] != 0 and hash_pattern[sentence[j]] <= hash_pattern[sentence[j]])
        {
            count++;
        }

        if (count == len_2)
        {
            while (hash_sentence[sentence[start]] > hash_pattern[sentence[start]] or hash_pattern[sentence[start]] == 0)
            {
                if (hash_sentence[sentence[start]] > hash_pattern[sentence[start]])
                {
                    hash_sentence[sentence[start]] -= 1;
                }
                start++;
            }
        }
        int len_window = j - start + 1;
        if (min_len > len_window)
        {
            min_len = len_window;
            start_id = start;
        }
    }
    if (start_id == -1)
    {
        return "No Window";
    }
    return pattern.substr(start_id, min_len);
}

int main()
{
    string pattern, sentence;
    cin >> pattern >> sentence;

    cout << minimum_window(pattern, sentence) << "\n";
    return 0;
}