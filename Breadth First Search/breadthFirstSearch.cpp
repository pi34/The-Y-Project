/*
The following implementation of the Breadth-First Search algorithms search through the entire graph by visiting all the 
neighbours of particular nodes in a sequence. The time complexity of this algorithm is O(n).

*/

#include <iostream>
#include <queue>

using namespace std;

// Set a limit on the number of elements, can be taken as user input as well
int N = 1000;

// Initialise an empty array, where all the visisted nodes will be stored
int visited[N];

// Initialise an empty adjacency list for all the nodes
vector<int>adjList[N];

// Define the BFS function which takes as input, the nodes and edges
int BFS () {

    // Loop over all the edges to add the neighbours of each nodes to their adjacency list
    for (int i = 0; i < sizeof(edges); ++i) {

        // Add the second node of the edge to the adjacency list of the first one
        adjList[edges[i][0]].push_back(edges[i][1]);

        // Add the first node of the edge to the adjacency list of the second one
        adjList[edges[i][1]].push_back(edges[i][0]);

    };

    // Initialise an empty queue, which will act as the queue for our algorithm, telling us which node is to be visited next
    queue<int> que;

    // To begin, add the first node to the queue
    que.push(0);

    // Subsequently, mark the first node as visited
    visited[0] = 1;

    // Now run a while which terminates only when the entire queue becomes empty, i.e, there are no other nodes left to visit
    while (!que.empty()) {

        // Store the last element from the queue which is the current node
        int node = que.front();

        // Remove the last element from the queue since it has now been visited, and store it
        que.pop()

        // Iterate over all the neigbours of the current node
        for (int i = 0; i < sizeof(adjList[node]); ++i) {

            // Check if the particular neighbour node has already been visited
            if (visited[node] == 0) {

                // If so, mark this neighbour as visited
                visited[i] = 1

                // Add the neighbour to the queue
                que.push(i)

            }

        }

    }

    // Return 
    return 0

}
