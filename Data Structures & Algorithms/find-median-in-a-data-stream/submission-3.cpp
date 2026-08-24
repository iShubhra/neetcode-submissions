class MedianFinder {
public:
    priority_queue<int, vector<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if ( left.empty() ) {
            left.push(num);
            return;
        }

        if ( left.top() < num ) right.push(num);
        else left.push(num);

        if ( left.size() + 1 < right.size() ) {
            left.push( right.top() );
            right.pop();
        } else if ( right.size() + 1 < left.size()) {
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if ( left.size() == right.size() ) return double( left.top() + right.top() ) / 2.0;
        return left.size() > right.size() ? left.top() : right.top();
    }
};
