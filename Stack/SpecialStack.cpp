class SpecialStack {
    public:

    stack <int> st;
    int min;
    
    



    void push(int data) {
           if(st.empty()){
               st.push(data);
               min=data;
               return;
           }
           if(data>=min){
               st.push(data);
           }
           else{
              int val=2*data-min;
               st.push(val);
               min=data;
           }
           return;    
    }

    void pop() {
        if(st.empty()){
            return;
        }
        int top=st.top();
        st.pop();
        if(top>=min){
            return;
        }
        else{
            
            min=2*min-top;
        }
        return;
        
    }

    int top() {
        if(st.empty()) return -1;
        int top=st.top();
        if(top>min){
            return top;
        }
        else{
            return min;   
        }
    }

    int getMin() {
        if(st.empty()) return -1;
         return min;
    }  
};