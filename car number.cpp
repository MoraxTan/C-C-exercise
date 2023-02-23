# include <iostream>
using namespace std;

int calculate_digitSum(int n) {
    int temp = 0, current;
    while (n) {
        current = n % 10;
        if (current == 4) {
            return -1;
        }
        temp += current;
        n /= 10;
    }
    return temp;
}

int main(void) {
    int N, combos, digit_sum, counts;

    while ((cin >> N) && N >= 0) {
        if (N > 36) {
          cout << 0 << endl;
        }
        else {
            counts = 0;
            for (combos = 0; combos <= 9999; combos++) {
                digit_sum = calculate_digitSum(combos);
                if (digit_sum == N) {
                    counts++;
                }
            }
            cout << counts << endl;
        }
    }
}
