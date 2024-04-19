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
                


    }
    void insert(string word) {
        insertword(root,word);    
    }


    void printsuggestion(TrieNode *curr, vector<string> &temp, string prefix){
           if(curr->isTerminal){
               temp.push_back(prefix);
           }
           for(char ch='a';ch<='z';ch++){
               TrieNode * next=curr->children[ch-'a'];
               if(next){
                   prefix.push_back(ch);
                   printsuggestion(next,temp,prefix);
                   prefix.pop_back();
               }
           }

    }


    vector<vector <string>> getsuggestionqueryString(string str){
            TrieNode * prev=root;
            TrieNode * curr=root;
            vector<vector<string>> output;
            string prefix="";
            for(int i=0;i<str.length(); i++){
                char ch=str[i];
                prefix.push_back(ch);

                TrieNode * curr=prev->children[ch-'a'];

                if(!curr){
                    break;
                }
                vector <string> temp;
               printsuggestion(curr,temp,prefix);
               output.push_back(temp);
               temp.clear();
               prev=curr;

            }
            return output;
    }
    
    
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie * trie=new Trie();
    for(int i=0;i<contactList.size();i++){
          trie->insert(contactList[i]);
    }

    return trie->getsuggestionqueryString(queryStr);
          
}