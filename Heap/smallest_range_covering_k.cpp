class Node{
    public:
    int data;
    int i;
    int j;

    Node(int data,int i,int j){
        this->data=data;
        this->i=i;
        this->j=j;
    }
};


class Compare {
public:
    bool operator()(const Node* a, const Node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini=INT_MAX, maxi=INT_MIN;
        priority_queue <Node *,vector<Node *>,Compare> pq;
        
        
        for(int i=0; i<nums.size();i++){
            Node * temp= new Node(nums[i][0],i,0);
            pq.push(temp);
            maxi=max(temp->data,maxi);
            mini=min(mini,nums[i][0]);
        }

        int start=mini, end=maxi;

        while(!pq.empty()){
            Node * ele=pq.top();
            pq.pop();
            mini=ele->data;
            if(maxi-mini<end-start){
                start=mini;
                end=maxi;
            }
            if(ele->j+1<nums[ele->i].size()){
                Node * temp= new Node(nums[ele->i][ele->j+1],ele->i,ele->j+1);
                pq.push(temp);
                maxi=max(maxi,temp->data);
            }
            else{
                break;
            }
        }
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};