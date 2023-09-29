//https://www.geeksforgeeks.org/program-find-simple-moving-average/
class MovingAverage {
public:
    queue<int> q;
    int k;
    int sum;
    MovingAverage(int size) {
        k = size;
        sum = 0;
    }
    
    double next(int val) {
        double mean = 0;
        sum += val;
        q.push(val);
        if(q.size() > k) {
            sum -= q.front();
            q.pop(); 
            mean = (double)sum/k;
        }
        else {
            mean = (double)sum/q.size();
        }
        
        
        return mean;
    }
};