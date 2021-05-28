typedef struct Node{
    int val;
    Node* next;
    Node(int v = 0):val(v), next(nullptr){}
}*LinkList;

class MyLinkedList {
private:
    LinkList head;
public:
    /** Initialize your data structure here. */
    MyLinkedList():head(nullptr) {

    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
    	if( index < 0 || !head ) 
			return -1;
        
		Node* cur = head;
        while( index-- ){
			cur = cur->next;
			if( !cur )
				return -1;
		}
		return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
		Node* newNode = new Node(val);
		newNode->next = head;
		head = newNode;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
		Node* newNode = new Node(val);
		if( !head ){
			head = newNode;
			return;
		}
		Node* cur = head;
		while( cur->next )
			cur = cur->next;
		cur->next = newNode;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
    	if( index <= 0 ){
    		addAtHead(val);
			return;
		}else if( !head ){
			return;
		}
		Node* cur = head;
		while( --index ){
			cur = cur->next;
			if( !cur )
				return;
		}
		Node* newNode = new Node(val);
		newNode->next = cur->next;
		cur->next = newNode;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
    	if( !head ) return;
    	if( index == 0 ){
			head = head->next;
			return;	
		}
    	
		Node* pre = head;
		Node* cur = head->next;
		while( --index ){
			if( !cur )
				return;
			pre = cur;
			cur = cur->next;
		}
		if( cur ){
			pre->next = cur->next;
			delete cur;
		}
    }
    
//    void print(){
//		Node* cur = head;
//		while( cur ){
//			cout << cur->val << " ";
//			cur = cur->next;
//		}
//		cout << endl;
//	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
