class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        Node* curr = head;
        int i = 0;

        while (curr) {
            if (i == index) return curr->val;
            curr = curr->next;
            i++;
        }

        return -1;
    }

    void insertHead(int val) {
        Node* node = new Node(val);

        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head = node;
        }
    }

    void insertTail(int val) {
        Node* node = new Node(val);

        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    bool remove(int index) {
        if (!head) return false;

        if (index == 0) {
            Node* temp = head;
            head = head->next;

            if (!head) tail = nullptr;

            delete temp;
            return true;
        }

        Node* curr = head;
        int i = 0;

        while (curr && i < index - 1) {
            curr = curr->next;
            i++;
        }

        if (!curr || !curr->next) return false;

        Node* temp = curr->next;
        curr->next = temp->next;

        if (temp == tail) {
            tail = curr;
        }

        delete temp;
        return true;
    }

    vector<int> getValues() {
        vector<int> ans;
        Node* curr = head;

        while (curr) {
            ans.push_back(curr->val);
            curr = curr->next;
        }

        return ans;
    }
};