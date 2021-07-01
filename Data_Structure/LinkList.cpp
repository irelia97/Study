#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int   data;
    Node* next;
    Node(int x):data(x), next(nullptr){}
}List;

class LinkList{
private:
    List* head;
    int  _size;
public:
    LinkList() : _size(0) { head = new Node(0); }
    LinkList(const LinkList& anoList) : _size(anoList._size) {
        List* p1 = this->head = new Node(0);
        List* p2 = anoList.head->next;
        while( p2 != nullptr ){
            Node* node = new Node(p2->data);
            p1->next = node;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    ~LinkList(){
        List* pre  = head;
        List* p    = head;
        do{
            p = p->next;
            delete pre;
            pre = p;
        }while( pre != nullptr );
    }

    int  size() const { return _size; }
    bool isEmpty() const { return _size == 0; }
    //  插入到[1, size]的位置，若超出size则插入到末尾
    bool insert(int index, int data){
        if( index <= 0 )
            return false;
        List* p = head;
        while( --index && p->next ){
            p = p->next;
        }
        Node* node = new Node(data);
        node->next = p->next;
        p->next = node;
        _size++;

        return true;
    }

    bool push_back(int data)  { return insert(_size + 1, data); }
    bool push_front(int data) { return insert(1, data); }

    //  删除[1, size]位置的元素
    bool remove(int index){
        if( index <= 0 || index > _size )
            return false;
        List* p = head;
        while( --index ){
            p = p->next;
        }
        p->next = p->next->next;
        _size--;

        return true;
    }

    bool pop_front() { return remove(1); }
    bool pop_back()  { return remove(_size); }

    Node* getNode(int index) const{
        if( index <= 0 || index > _size ){
            cerr << "getNode index out of bound!\n";
            return head;
        } 
        List* p = head;
        while( index-- )
            p = p->next;
        return p;
    }

    Node* search(int data) const{
        List* p = head->next;
        while( p != nullptr ){
            if( p->data == data )
                break;
            p = p->next;
        }
        return p;
    }

    void printList() const{
        List* p = head->next;
        while( p != nullptr ){
            cout << p->data << " ";
            p = p->next;
        }
        cout << "\n\n";
    }
};

int main()
{
    LinkList L1;
    L1.insert(10, 10);
    L1.push_front(3);
    L1.push_back(5);
    L1.printList();

    L1.insert(2, 4);
    L1.insert(4, 20);
    L1.printList();
    cout << L1.getNode(0)->data << endl;

    L1.remove(3);
    L1.printList();

    L1.pop_front();
    L1.pop_back();
    L1.printList();


    return 0;
}