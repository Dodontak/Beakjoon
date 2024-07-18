#include <iostream>

using namespace std;

class Node
{
private:
	int	value;
	Node *left;
	Node *right;
public:
	Node(int _value) : value(_value), left(NULL), right(NULL) {}
	~Node() {
		if (left) delete left;
		if (right) delete right;
	}
	void add(int new_value) {
		if (new_value < value) {
			if (left) left->add(new_value);
			else left = new Node(new_value); 
		} else {
			if (right) right->add(new_value);
			else right = new Node(new_value);
		}
	}
	void print() {
		if (left) left->print();
		if (right) right->print();
		cout << value << endl;
	}
};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int	num; cin >> num;
	Node	root(num);
	while (cin >> num) {
		root.add(num);
	}
	root.print();
}
