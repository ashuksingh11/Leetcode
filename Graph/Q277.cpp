//277. Find the Celebrity
class Solution {
public:
    
    int findCelebrity(int n) {
        int candidate = 0;
        for(int i=0; i<n; i++) {
            if(knows(candidate,i)) {
                candidate = i;
            }
        }
        
        if(isCelebrity(candidate,n)) {
            return candidate;
        }
        
        return -1;
    }
    
    bool isCelebrity(int i, int numofpeople) {
        for(int j=0; j<numofpeople; j++) {
            if(i==j) continue;
            if(knows(i,j) || !knows(j,i)) {
                return false;
            }
        }
        
        return true;
    }
};