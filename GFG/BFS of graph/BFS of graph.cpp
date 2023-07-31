// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.


// Example 1:

// Input:

// Output: 0 1 2 3 4
// Explanation: 
// 0 is connected to 1 , 2 , 3.
// 2 is connected to 4.
// so starting from 0, it will go to 1 then 2
// then 3. After this 2 to 4, thus bfs will be
// 0 1 2 3 4.
// Example 2:

// Input:

// Output: 0 1 2
// Explanation:
// 0 is connected to 1 , 2.
// so starting from 0, it will go to 1 then 2,
// thus bfs will be 0 1 2. 

// Your task:
// You dont need to read input or print anything. Your task is to complete the function bfsOfGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns  a list containing the BFS traversal of the graph starting from the 0th vertex from left to right.


// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)


// Constraints:
// 1 ≤ V, E ≤ 104


  
    
    //1.insitialize a visited marked all as 0.
    //2.first node is 1 is visted.
    //3.create empty queue FIFO.
    //4.first elemnt is always presend ,so it marked as visited (2).
    //5.initilize empty vector.
    //6.while queue is not empty it goes on.
    //7.instilize node = first presented element in queue.
    //8.pop out that item from the queue.
    //9.push that item into bfs which  is created.(5)(7)
    //10.itreate the adjecent element of the node.(7)
    //11.check if the adj is not visted.(1)
    //12.not visited then make it visited = 1.
    //13.push that element into queue.(4)(6)
    //14. return the generated bfs.
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};   //1
        vis[0] = 1;        //2
        queue<int>q;         //3
        q.push(0);          //4
        vector<int> bfs;     //5
        while(!q.empty()){   //6
            int node = q.front();  //7
            q.pop();         //8
            bfs.push_back(node);   //9
            
            for(auto it : adj[node]){  //10
                if(!vis[it]){     //11
                    vis[it] = 1;    //12
                    q.push(it);     //13
                } 
            }
        }
        return bfs;     //14
    } 
};