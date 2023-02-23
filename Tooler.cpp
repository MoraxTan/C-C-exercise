# include <iostream>
# include <string>
using namespace std;

void compile_S(int arr[], size_t size=12) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

bool handler(const string &strn, int set[], size_t size=12) {
    int cur_int, Ri, str_len = strn.size();
    string cur_str;
    for (int s = 0; s < size; s++) {
        cur_str = "";
        if (set[s] == 1) {
          continue;
        }
        if (!set[s]) {
          break;
        }

        for (int i = 0; i < str_len; i+=5) {
            //get one %number with five numbers,let the %number group it with next five numbers
            for (int j = i; j < i+5; j++) {
                if (j >= str_len) {
                  break;
                }
                cur_str += strn[j];
            }
            cur_int = stoi(cur_str);
            Ri = cur_int % set[s];
            cur_str = to_string(Ri);
        }

        cur_int = stoi(cur_str);
        if (cur_int) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int t, Sum_num, Sumary[12];
    string N;
    bool res;

    cin >> t;
    while (t--) {
        getchar();  
        getline(cin, N); //for get string M,ignore'\n'

        compile_S(Sumary);
        cin >> Sum_num;
        for (int i = 0; i < Sum_num; i++) {
            cin >> Sumary[i];
        }

        // handle
        if (handler(N, Sumary)) {
            cout<<N<< " - Wonderful." << endl;
        }
        else {
           cout<<N<< " - Simple." << endl;
        }
    }
}
