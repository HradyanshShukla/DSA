class MyCircularQueue {
    vector<int>a;
    int head,tail,sz,cap;
public:
    MyCircularQueue(int k):a(k),head(0),tail(0),sz(0),cap(k) {}   
    bool enQueue(int value) {
if(sz==cap) return false;
a[tail]=value;
tail=(tail+1)%cap;
++sz;
return true;       
}    
    bool deQueue() {
        if(sz==0)return false;
        head=(head+1)%cap;
        --sz;
        return true;        
    }    
    int Front() { 
        if(sz>0){
            return a[head];
        } else{
            return -1;
        }      
    }    
    int Rear() {    
        if(sz>0){
            int lastIndex=(tail-1+cap)%cap;
            return a[lastIndex];
        } else{
            return -1;
        }    
    }    
    bool isEmpty() {
        return (sz==0);        
    }   
    bool isFull() {  
        return (sz==cap);      
    }
};
