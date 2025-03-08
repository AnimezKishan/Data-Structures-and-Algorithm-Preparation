// Sliding Window

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int minOp = INT_MAX;
    
            int i = 0, operations = 0, j;
            for(j=0; j<k; j++) {
                if(blocks[j] == 'W')
                    operations++;
            }
    
            minOp = min(minOp, operations);
    
            while(j < blocks.size()) {
                if(blocks[j++] == 'W')
                    operations++;
                
                if(blocks[i++] == 'W')
                    operations--;
    
                minOp = min(minOp, operations);
            }
    
            return minOp;
        }
    };