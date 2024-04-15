class Character{
    public:
    char ch;
    int freq;
    Character(char ch, int freq){
        this->ch=ch;
        this->freq=freq;
    }
};

class Compare {
public:
    bool operator()(const Character* a, const Character* b) {
        return a->freq < b->freq;
    }
};


class Solution {
public:
    string reorganizeString(string s) {
        priority_queue <Character *, vector<Character *> ,Compare> pq;
        string ans="";
        map <char,int> mp;
        for (char c : s) {
        mp[c]++;
       }
        
        
        auto it = mp.begin();
        while(it!=mp.end()){
            Character * temp=new Character(it->first,it->second);
            pq.push(temp);
            it++;
        }
        
        while(pq.size()>1){
            Character *ch1=pq.top();
            pq.pop();
            Character *ch2=pq.top();
            pq.pop();
            
            ch1->freq=ch1->freq-1;
            ch2->freq=ch2->freq-1;
            
            if(ch1->freq>0){
                pq.push(ch1);
            }
            if(ch2->freq>0){
                pq.push(ch2);
            }
            
            ans=ans+ch1->ch+ch2->ch;
        }

        if(pq.empty()){
            return ans;
        }
        else{
            Character *ch1=pq.top();
            if(ch1->freq>1){
                return "";
            }
            else{
                ans=ans+ch1->ch;
            }
        }
        return ans;
    }
};