class MedianFinder {
private:
    priority_queue<double, vector<double>, greater<double>> minH;
    priority_queue<double> maxH;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minH.size() == 0){
            minH.push(num);
            return;
        }
        if(minH.size() == maxH.size()){
            if(num < minH.top()) maxH.push(num);
            else minH.push(num);
        } else{
            if(maxH.size() > minH.size()){
                if (num > maxH.top()) minH.push(num);
                else {
                    minH.push(maxH.top());
                    maxH.pop();
                    maxH.push(num);
                }
            } else {
                if(num < minH.top()) maxH.push(num);
                else {
                    maxH.push(minH.top());
                    minH.pop();
                    minH.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if(maxH.size() == minH.size()){
            double f = maxH.top();
            double s = minH.top();
            return (double)(f+s) / 2;
        } else if(maxH.size() > minH.size()){
            return maxH.top();
        } else {
            return minH.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */