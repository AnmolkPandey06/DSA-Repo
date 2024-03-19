//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        
        
        //putted all the elements in the stack
        stack <int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        
        //now jabtak ek element na bacje stack me 
        while(!(s.size()<=1)){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            
            //b ko a janta hai
            if(M[a][b]==1){
                s.push(b);
            }
            
            //a ko b janta hai
            if(M[b][a]==1){
                s.push(a);
            }
            
            
            
        }
        
        if(s.empty()){
            return -1;
        }
        //checkingh last time
        else{
            int celeb=s.top();
            bool rowcheck=false;
            bool colcheck=false;
            int row=0;
            int col=0;
            
            //cout<<"celeb"<<celeb<<endl;
            //this if he know noone
            for(int i=0;i<n;i++){
               // cout<<M[celeb][i]<<" ";
                if(M[celeb][i]==0) {
                    row=row+1;
                    
                }
            }
            //cout<<"row"<<row<<endl;
            if(row==n) rowcheck=true;
            
            
            // this for everyone knows him
            for(int i=0;i<n;i++){
                if(M[i][celeb]==1) col++;
            }
           // cout<<"col"<<col<<endl;
            if(col==n-1) colcheck=true;
            
            
            //
            if(rowcheck && colcheck) return celeb;
            return -1;
            
                        
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends