struct Node{
    Node* links[26];
    bool flag=false;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void setKey(char ch,Node* reference){
        links[ch-'a']=reference;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(auto i:word){
            if(!node->containsKey(i)){
                node->setKey(i,new Node());
            }
            node=node->get(i);
        }
        node->flag=true;
    }
    
    bool search(string word) {
        Node* node=root;
        for(auto i:word){
            if(!node->containsKey(i)){return !true;}
            node=node->get(i);
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){return !true;}
            if(i==prefix.size()-1){return true;}
            else{
                node=node->get(prefix[i]);
            }
        }   
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */