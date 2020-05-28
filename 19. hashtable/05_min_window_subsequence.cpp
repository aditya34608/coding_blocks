#include <iostream>
#include <unordered_map>

using namespace std;

string min_window_sequence(string str, string pat){
    int len_1 = str.size();
    int len_2 = pat.size();

    if (len_1 < len_2){
        return "No Window";
    }

    int hash_str[256] = {0};
    int hash_pat[256] = {0};
    for (int i=0; i<len_2 - 1; i++){
        hash_pat[pat[i]] ++;
    }

    int start = 0, count = 0, start_id = -1, min_len = INT_MAX;

    for (int j = 0; j < len_1; j++){
        hash_str[str[j]] ++;
        if (hash_pat[str[j]] != 0 and hash_pat[str[j]] <= hash_pat[str[j]]){
            count ++;
        }

        if (count == len_2){
            while(hash_str[str[start]] > hash_pat[str[start]] or hash_pat[str[start]] == 0){
                if (hash_str[str[start]] > hash_pat[str[start]]) {
                    hash_str[str[start]] --;
                }
            }
        } 
    }
}

int main(){
    string str, pat;
    cin >> str >> pat;
    cout << min_window_sequence(str, pat) << "\n";
    return 0;
}
