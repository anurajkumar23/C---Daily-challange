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