

#include <iostream>
#include "Linkedlist.h"
#include <vector>
using namespace std;
void insertAfter(vector<int>& v, int first, int second) {
    bool flags = false;
    for (int i = 0; i < v.size(); i++) {
        if (flags == false) {
            if (v[i] == first) {
                v.insert(v.begin() + i + 1, second);
                flags = true;

            }
        }
    }
}

int main() {
    int n, x, firstval, secondval;
    cout << "Enter number of integers";
    cin >> n;
    vector<int> vec;
    for (int i = 0;i < n;i++) {
        cout << "enter the integer";
        cin >> x;
        vec.push_back(x);
    }
    cout << "Enter first value to be inserted";
    cin >> firstval;
    cout << "Enter second value to be inserted";
    cin >> secondval;
    insertAfter(vec, firstval, secondval);
    Linkedlist l;
    l = l.create(vec);
    l.printallelements();
    cout << "The sum of all nodes=" << l.sumnode();



}


