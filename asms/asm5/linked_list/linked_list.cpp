#include "linked_list.h"

int Linked_List::get_length() {
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
	if(this->length >= 0) {
		return this->length;
	}

	return -1;
}

void Linked_List::print(){
	// output a list of all integers contained within the list
	Node* current = this->head;
	cout << " ";
	while (current != NULL){
		cout << current->val << " ";
		current = current->next;
	}
 
	cout << "\n";
	return;
}

void Linked_List::clear(){
	// delete the entire list (remove all nodes and reset length to 0)
	Node* current = this->head;
	while(current != NULL) {
		Node* temp = current->next;
		delete current;
		current = temp;
	}
	this->head = NULL;
	this->length = 0;

	return;
}

void Linked_List::push_front(int val){
	// insert a new value at the front of the list 
	Node* new_node = new Node;
	new_node->val = val;
	new_node->next = this->head;
	this->head = new_node;
	this->length++;

	return;
}

void Linked_List::push_back(int val){
	// insert a new value at the back of the list 
	Node* current = this->head;
	if (current == NULL) {
		this->head = new Node;
		this->head->val = val;
		this->head->next = NULL;
	} else {
		while(current->next != NULL) {
			current = current->next;
		}
		Node* new_node = new Node;
		new_node->val = val;
		new_node->next = NULL;
		current->next = new_node;
	}
	this->length++;

	return;
}

void Linked_List::insert(int val, int index){
	// insert a new value in the list at the specified index 
	if(index < 0 || index > this->length) {
        return;
    }

    Node* new_node = new Node;
    new_node->val = val;

    if(index == 0) {
        new_node->next = this->head;
        this->head = new_node;
    } else {
        Node* current = this->head;
        for(int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    this->length++;

    return;
}

void Linked_List::pop_back(){
	// remove the node at the back of the list
	if(this->head == NULL) {
		return;
	}

	if(this->head->next == NULL) {
		delete this->head;
		this->head = NULL;
    } else {
        Node* current = this->head;
        Node* prev = NULL;
        while(current->next != NULL) {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        delete current;
    }

	this->length--;

	return;
}

void Linked_List::pop_front(){
	// remove the node at the front of the list
	if(this->head == NULL) {
		return;
	}

	Node* temp = this->head;
	this->head = this->head->next;
	delete temp;
	this->length--;

	return;
}

void Linked_List::remove(int index){
	// remove the node at index of the list
	if(index < 0 || index > this->length) {
        return;
    }

    if(index == 0) {
        pop_front();
		return;
    } else if (index == this->length - 1) {
		pop_back();
		return;
	} else {
        Node* current = this->head;
        for(int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
		Node *node_to_delete = current->next;
        current->next = node_to_delete->next;
        delete node_to_delete;
	}

    this->length--;

	return;
}

Node* Linked_List::find_middle(Node* head){
	Node* slow = head;
	Node* fast = head->next;

	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

Node* Linked_List::merge(Node* a, Node* b, bool ascending){
	if(a == NULL) {
		return b;
	}
	if(b == NULL) {
		return a;
	}

	Node* c;

	if(ascending) {
		if(a->val < b->val) {
			c = a;
			c->next = merge(a->next, b, ascending);
		} else {
			c = b;
			c->next = merge(a, b->next, ascending);
		}
	}
	if(!ascending) {
		if(a->val > b->val) {
			c = a;
			c->next = merge(a->next, b, ascending);
		} else {
			c = b;
			c->next = merge(a, b->next, ascending);
		}
	}

	return c;
}

Node* Linked_List::merge_sort(Node* head, bool ascending){
	if(head == NULL || head->next == NULL){
		return head;
	}

	Node* middle = find_middle(head);

	Node* a = head;
	Node* b = middle->next;
	middle->next = NULL;

	a = merge_sort(a, ascending);
	b = merge_sort(b, ascending);

	return merge(a, b, ascending);

}

void Linked_List::sort_ascending(){
	// sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	bool ascending = true;
	this->head = merge_sort(this->head, ascending);

	return;
}

void Linked_List::sort_descending(){
	// sort the nodes in descending order
	bool ascending = false;
	this->head = merge_sort(this->head, ascending);

	return;
}
