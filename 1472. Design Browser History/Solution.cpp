class BrowserHistory {
   struct Node{
    string data;
    Node* prev;
    Node* next;
    Node(string d): data(d), prev(nullptr), next(nullptr){}
   };
public:
    Node* curr;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    void visit(string url) {
        Node* node = new Node(url);
        curr->next = node;
        node->prev = curr;
        curr = node;  
    }
    
    string back(int steps) {
        while(curr->prev!= NULL && steps>0){
            curr = curr->prev;
            steps--;
        }
        return curr->data;
    }
    
    string forward(int steps) {
        while(curr->next!=NULL && steps>0){
            curr = curr->next;
            steps--;
        }
        return curr->data;
    }
};