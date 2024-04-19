class TrieNode{
   public:
    char ch;
    TrieNode * children[26];
    bool isTerminal;
    TrieNode(char ch) {
        this->ch=ch;
        isTerminal=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class Trie {
public:
    TrieNode * root; 
    Trie(){
        root=new TrieNode('/n');
    }
    
    void insertword(TrieNode * root,string word) {
        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }

        //recursive
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]){
            child=root->children[index];
        }
        else{
            child= new TrieNode(word[0]);
            root->children[index]=child;            
        }
        return  insertword(child,word.substr(1));
        


        // for(int i=0;i<26;i++){
        //     if(word[0]==root->children[i]->ch){
        //         insertword(root->children[i],word.erase(0,1));
        //     }
        //     return;
        // }

        // TrieNode * newnode=new TrieNode(word[0]);
        // insertword(root->children[i],word.erase(0,1)); 
        // return;
         


    }

    bool searchword(TrieNode * root, string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index=word[0]-'a';
        TrieNode * child;
        if(root->children[index]!=NULL){
             child=root->children[index];
        }
        else{
            return false;
        }
        return searchword(child,word.substr(1));
    }


    
    bool searchprefix(TrieNode * root, string prefix){
        if(prefix.length()==0){
            return true;
        }
        int index=prefix[0]-'a';
        TrieNode * child;
        if(root->children[index]!=NULL){
             child=root->children[index];
        }
        else{
            return false;
        }
        return searchprefix(child,prefix.substr(1));
    }

   



    void insert(string word) {
        insertword(root,word);    
    }
    
    bool search(string word) {
        return  searchword(root,word);
    
    }
    
    bool startsWith(string prefix) {
        return searchprefix(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */