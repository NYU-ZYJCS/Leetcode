struct Node{
    unordered_set<string> container;
    int val = 0;
    Node(int v) : val(v) {}
};

class AllOne {
public:
    unordered_map<string, list<Node>::iterator> kv;
    list<Node> List;
    
    
    AllOne() {
        
    }
    
    void inc(string key) {
        if (kv.contains(key)) {
            auto oldNode = kv[key];
            auto newNode = next(oldNode, 1);
            
            if (newNode == List.end() || newNode->val > oldNode->val + 1) {
                newNode = List.insert(newNode, Node(oldNode->val + 1));
            }

            newNode->container.insert(key);
            oldNode->container.erase(key);
            
            if (oldNode->container.empty()) {
                List.erase(oldNode);
            }
            kv[key] = newNode;
        } else {
            auto newNode = List.begin();
            
            if (List.empty() || List.begin()->val > 1) {
                newNode = List.insert(newNode, Node(1));
            }
            newNode->container.insert(key);
            kv[key] = newNode;
        }
    }
    
    void dec(string key) {
        if (kv.contains(key)){
            auto oldNode = kv[key];
            if (oldNode->val == 1) {
                kv.erase(key);
            } else {
                auto newNode = next(oldNode, -1);
                if (oldNode == List.begin() || newNode->val < oldNode->val - 1) {
                    newNode = List.insert(oldNode, Node(oldNode->val - 1));
                }
                
                newNode->container.insert(key);
                kv[key] = newNode;
            }
            
            oldNode->container.erase(key);
            if (oldNode->container.empty()) {
                List.erase(oldNode);
            }
        }
    }
    
    string getMaxKey() {
        return List.empty() ? "" : *List.rbegin()->container.begin();
    }
    
    string getMinKey() {
        return List.empty() ? "" : *List.begin()->container.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */