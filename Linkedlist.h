

#pragma once
#include <iostream>
#include<vector>
using namespace std;
struct node {
	int value;
	int count;
	node* next;
	node(int val, int cnt) {
		value = val;
		count = cnt;
		next = nullptr;
	}

};
class Linkedlist
{
private: node* head;
public:
	Linkedlist() {
		head = nullptr;
	}
	void addnode(int value, int count) {
		node* addednode = new node(value, count);
		if (head == nullptr) {
			head = addednode;
		}
		else {
			node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = addednode;
		}
	}
	void deletenode(int values)
	{
		node* p = head;
		node* m = nullptr;
		while (p->value != values)
		{
			m = p;
			p = p->next;
		}
		if (m != nullptr) {
			m->next = p->next;
		}
	}
	void printallelements() {
		cout << "Printing all elements: " << endl;
		node* z = head;
		while (z != nullptr) {
			cout << z->value << "// Repeated " << z->count << " times" << endl;
			z = z->next;
		}
		cout << endl;
	}
	Linkedlist create(vector<int>& v) {
		Linkedlist List;
		int n = v.size();
		bool* occurred = new bool[n];
		int* counts = new int[n];

		for (int i = 0;i < n;i++) {
			occurred[i] = false;
			counts[i] = 1;
		}

		for (int i = 0; i < n; i++) {
			if (occurred[i] == false) {
				for (int j = i + 1; j < n; j++) {
					if (v[i] == v[j]) {
						counts[i]++;
						occurred[j] = true;
					}
				}
				List.addnode(v[i], counts[i]);
			}
		}

		return List;
	}

	int sumnode() {
		int sum = 0;
		node* p = head;
		while (p != nullptr) {
			sum += p->value * p->count;
			p = p->next;
		}
		return sum;
	}
};

