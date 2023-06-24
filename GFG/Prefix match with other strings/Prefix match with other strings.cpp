Example 1:

Input:
n = 6
// arr[] = {“abba”, “abbb”, “abbc”, “abbd”, 
// “abaa”, “abca”}
// str = “abbg”
// k = 3
// Output: 
// 4 
// Explanation:
// “abba”, “abbb”, “abbc” and “abbd” have their prefix of length 3 equal to 3-length prefix of str i.e., "abb".
// Example 2:

// Input:
// n = 3
// arr[] = {“geeks”, “geeksforgeeks”, “forgeeks”}
// str = “geeks”
// k = 2
// Output: 
// 2
// Explanation:
// “geeks” and “geeksforgeeks” have their prefix of length 2 equal to 2-length prefix of str i.e., "ge".


class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        
        int count = 0;
        str = str.substr(0,k);
        for(int i=0;i<n;i++)
        {
            string temp = arr[i];
            if(temp.length()>=k and temp.substr(0,k)==str)
            {
                count++;
            }
            
        }
        return count;
    }
};