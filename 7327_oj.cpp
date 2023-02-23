# include <iostream>
# include <string>
# include <cmath>
# include <algorithm>
using namespace std;

class CharBinaryTree {
    private:
        char *arr;
        size_t capacity;

        void resize() {
            char *temp = new char[this->capacity * 2]();
            copy(this->arr, this->arr + this->capacity, temp);
            this->capacity *= 2;
            delete [] this->arr;
            this->arr = temp;
        }

    public:
        CharBinaryTree() {}
        CharBinaryTree(size_t tree_height) {
            this->capacity = (size_t) pow(2, tree_height) - 1;
            this->arr = new char[this->capacity]();
        }
        ~CharBinaryTree() {
            delete [] this->arr;
        }

        void boxFromString(string &from_str, char null_node_sign) {
            while (this->capacity < from_str.size()) {
                this->resize();
            }
            for (int i = 0; i < from_str.size(); i++) {
                this->arr[i] = from_str.at(i) != null_node_sign ? from_str.at(i) : null_node_sign;
            }
        }

        void printByInorder(size_t vidx = 0) {
            if (this->arr[vidx] < 'A' || this->arr[vidx] > 'Z') {
                return;
            }
            this->printByInorder(vidx * 2 + 1);
            cout << this->arr[vidx];
            this->printByInorder(vidx * 2 + 2);
        }

        void printByPostorder(size_t vidx = 0) {
            if (this->arr[vidx] < 'A' || this->arr[vidx] > 'Z') {
                return;
            }
            this->printByPostorder(vidx * 2 + 1);
            this->printByPostorder(vidx * 2 + 2);
            cout << this->arr[vidx];
        }
};

int main(void) {
    CharBinaryTree cbt(10);
    string input_tree;

    getline(cin, input_tree);
    // input_tree = "AB0CD00E";
    cbt.boxFromString(input_tree, '0');

    cbt.printByInorder();
    cout << endl;
    cbt.printByPostorder();
    cout << endl;
}