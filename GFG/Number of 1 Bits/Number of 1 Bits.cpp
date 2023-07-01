// Example 1:

// Input:
// N = 6
// Output:
// 2
// Explanation:
// Binary representation is '110' 
// So the count of the set bit is 2.
// Example 2:

// Input:
// 8
// Output:
// 1
// Explanation:
// Binary representation is '1000' 
// So the count of the set bit is 1.

int setBits(int N) {
        // Write Your Code here
        int set_bits = 0;
        while(N>0){
            N = N & (N-1);
            set_bits++;
        }
        return set_bits;
    }