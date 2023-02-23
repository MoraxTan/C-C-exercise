# include <iostream>
# include <cmath>
# include <algorithm>
using namespace std;

template <typename T>
class BST {
    private:
        T *arr;
        T null_sign;
        size_t capacity;
        size_t layers;

        void initArray(T *arr, size_t size) {
            if (arr) {
                for (int i = 0; i < size; i++) {
                    arr[i] = this->null_sign;
                }
            }
        }

        void resize() {
            size_t new_layers = this->layers * 2;
            size_t new_capacity = (size_t) pow(2, new_layers) - 1;
            T *new_arr = new T[new_capacity];
            this->initArray(new_arr, new_capacity);
            copy(this->arr, this->arr + this->capacity, new_arr);
            delete [] this->arr;
            this->arr = new_arr;
            this->capacity = new_capacity;
            this->layers = new_layers;
        }

        int searchInsertSlot(T new_val) {
            size_t cur_idx = 0;
            while (this->arr[cur_idx] != this->null_sign) {
                if (new_val == this->arr[cur_idx]) {
                    return -1;
                }
                
                cur_idx = (new_val < this->arr[cur_idx]) ? cur_idx*2+1 : cur_idx*2+2;
            }
            
            return cur_idx;
        }

        int searchDestinaSlot(T dest_val) {
            size_t cur_idx = 0;
            while (this->arr[cur_idx] != this->null_sign) {
                if (this->arr[cur_idx] == dest_val) {
                    return cur_idx;
                }
                
                cur_idx = (dest_val < this->arr[cur_idx]) ? cur_idx*2+1 : cur_idx*2+2;
            }
            
            return -1;
        }

        void recursiveRemove(size_t rem_idx) {
            size_t left_idx = rem_idx * 2 + 1;
            size_t right_idx = rem_idx * 2 + 2;
            if (this->arr[left_idx] == this->null_sign && this->arr[right_idx] == this->null_sign) {
                this->arr[rem_idx] = null_sign;
                return;
            }
            
            if (this->arr[left_idx] != this->null_sign) {
                size_t pred_idx = left_idx;
                while (this->arr[pred_idx*2+2] != this->null_sign) {
                    pred_idx = pred_idx * 2 + 2;
                }
                this->arr[rem_idx] = this->arr[pred_idx];
                this->recursiveRemove(pred_idx);
            }
            
            else if (this->arr[right_idx] != this->null_sign) {
                size_t succ_idx = right_idx;
                while (this->arr[succ_idx*2+1] != this->null_sign) {
                    succ_idx = succ_idx * 2 + 1;
                }
                this->arr[rem_idx] = this->arr[succ_idx];
                this->recursiveRemove(succ_idx);
            }
        }

        int getLayer(size_t idx) {
            int k = 1;
            int fidx = (int) pow(2, k) - 2;
            while (idx > fidx) {
                fidx = (int) pow(2, ++k) - 2;
            }
            return k;
        }

    public:
        BST() {}
        BST(size_t required_layers, T _null_sign) {
            this->null_sign = _null_sign;
            this->layers = required_layers;
            this->capacity = (size_t) pow(2, required_layers) - 1;
            this->arr = new T[this->capacity];
            this->initArray(this->arr, this->capacity);
        }
        ~BST() {
            delete [] this->arr;
        }

        void insert(T val) {
            int insertion_idx = this->searchInsertSlot(val);
            if (insertion_idx == -1) {
                return;
            }
            while (insertion_idx >= this->capacity) {
                this->resize();
            }
            this->arr[insertion_idx] = val;
        }

        void remove(T val) {
            int rem_idx = this->searchDestinaSlot(val);
            if (rem_idx == -1) {
                return;
            }
            this->recursiveRemove(rem_idx);
        }

        bool isEmpty() {
            return this->arr[0] == this->null_sign;
        }

        void clear() {
            this->initArray();
        }

        void print() {
            size_t final_nonzero_idx = 0, max_layer, end_idx;
            for (int i = 0; i < this->capacity; i++) {
                if (this->arr[i] != this->null_sign) {
                    final_nonzero_idx = i;
                }
            }
            
            max_layer = this->getLayer(final_nonzero_idx);
            end_idx = (size_t) pow(2, max_layer) - 2;
            for (int i = 0; i <= end_idx; i++) {
                cout << this->arr[i] << ' ';
            }
        }
};

int main(void) {
    BST<int> bst(10, 0);
    int num;

    while ((cin >> num) && num != -1) {
        bst.insert(num);
    }

    while ((cin >> num) && num != -1) {
        bst.remove(num);
    }

    bst.print();
}
