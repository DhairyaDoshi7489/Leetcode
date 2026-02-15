class MedianFinder {
public:
    multiset<int> l, r;
    MedianFinder(){}
    
    void addNum(int num) {
        if(!l.size())l.insert(num);
        else{
            if(num>=(*--l.end()))r.insert(num);
            else l.insert(num);
            if(abs(int(l.size()-r.size()))>1){
                if(l.size()>r.size())r.insert(*--l.end()), l.erase(--l.end());
                else l.insert(*r.begin()), r.erase(r.begin());
            }
        }
    }
    
    double findMedian() {
        int val = l.size()+r.size();
        if(val&1){
            if(l.size()>r.size())return *--l.end();
            else return *r.begin();
        }
        else return (*--l.end()+*r.begin())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */