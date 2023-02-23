//Huffman Encoding, copied from internet
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Node {   
	int frequency;                                  
    string code;                                    
    Node* left;                                     
    Node* right;                                   
};

struct cmp {   
	bool operator ()  (Node const *a, Node const *b) {
        return a->frequency > b->frequency;        
    }
};

class Huffman_Tree {
	public:
    	void build_tree();                              
    	void get_info(vector<string> code, vector<int>);
    	string decode(string code);   
		                 
    	void get_path() {                                 
        	vector<string> con;                        
       		get_path(0, con, root);                         
    	}
		
    	void delete_node(Node *t); 
		                     
    	Huffman_Tree() {
    		num = 0;
    		root = 0;
		}
    	~Huffman_Tree(){
    		num = 0;
    		if (root == 0) return;
    		delete_node(root);
    		while (!con.empty())
        		con.pop();
		}
    
	private:
    	priority_queue<Node*, vector<Node*>, cmp> con; 
    	Node* root;                                     
    	int num;                                        
    	void get_path(int i, vector<string> temp, Node* t);  
};
	
string Huffman_Tree::decode(string code) {
    cout<<code<<endl;
    string res = "";
    int len = code.size();
    Node *temp = root;
    for (int i = 0; i < len; ++i){   
		char a = code[i];
        if (a == '0'){
            if (temp->left == 0){
                return "";
            }
            temp = temp->left;
            if (temp->left == 0 && temp->right == 0){
                res += temp->code;
                temp = root;                                    
            }
        }
        if (a == '1'){
            if (temp->right == 0){
                return "";
            }
            temp = temp->right;
            if (temp->left == 0 && temp->right == 0){
                res += temp->code;
                temp = root;                                     
            }
        }
    }
    return res;
}

void get_path(int i, vector<string> temp, Node* t){                                                               
    if (!t->left && !t->right){
        cout << "character: " << t->code << " code:";
        for (int j = 0; j < i; j++)
            cout << temp[j] << "";
        cout << endl;
        return;
    }
    
    temp.push_back("0");
    if (t->left != 0)
        get_path(i + 1, temp, t->left);
    temp[i] = "1";
    if (t->right != 0)
        get_path(i + 1, temp, t->right);
}

void Huffman_Tree::get_info(vector<string> con1, vector<int> con2) {
    for (int i = 0; i < con1.size(); ++i) {
        Node* tt = new Node;
        tt->frequency = con2[i];
        tt->code = con1[i];
        tt->left = tt->right = 0;
        con.push(tt);                           
    }
}

void Huffman_Tree::build_tree() {                      
    for (;;) {
        if (con.size() == 1) return ;
        Node* h;
        Node* j;
        
        h = con.top();
        con.pop();
        j = con.top();
        con.pop();
        
        if (!j) return ;
        Node* k = new Node;  
		                  
        k->frequency = h->frequency + j->frequency;
        k->left = h;
        k->right = j;
        con.push(k);
        root = k;
    }
}
void Huffman_Tree::delete_node(Node* t) {
    if (t->right != 0)
        delete_node(t->right);
    if (t->left != 0)
        delete_node(t->left);
    delete t;
}

int main(int argc, char const *argv[]) {
	vector<string> letter;
	vector<int> value;
	
	letter.push_back("a");
	letter.push_back("b");
	letter.push_back("c");
	letter.push_back("d");
	
	value.push_back(14);
	value.push_back(1);
	value.push_back(2);
	value.push_back(3);
	
	Huffman_Tree huffmanTree;
	huffmanTree.get_info(letter, value);
	huffmanTree.build_tree();
	huffmanTree.get_path();
	
	return 0;
}
