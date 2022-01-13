/*
The following implementation of the Depth-First Search algorithm searches through the entire graph by visiting the depth of 
an entire branch before backtracking and moving on to the next branch. The time complexity of this algorithm is 
approximately O(n^2).

*/

#include <iostream>
#include <vector>
#include <pair>

using namespace std;

// Set a limit on the number of elements, can be taken as user input as well
int N = 1000

// Initialise an empty array, where all the visisted nodes will be stored
int visited[N];

// Initialise an empty adjacency list for all the nodes
vector<int>adjList[N];

// Define the recursive DFS function, which takes as input the current node of the graph
void DFS (int node) {

    // Mark the current node as visited so that it is not looped over again
    visited[node] = 1

    // Iterate over all the neighbours (or edges in the graph) of the current node
    for (int i = 0; i < sizeof(adjList[node]); ++i) {

        // Check if the particular neighbour node has already been visited
        if (visited[node] == 0) {

            // If so, perform DFS on this node and its neighbours
            DFS (i)

        }

    }

}


// Define a function which intiates the DFS algorithm by creating an adjacency list for all the nodes
int performDFS (int[] n, pair<int><int> edges[]) {

    // Loop over all the edges to add the neighbours of each nodes to their adjacency list
    for (int i = 0; i < sizeof(edges); ++i) {

        // Add the second node of the edge to the adjacency list of the first one
        adjList[edges[i][0]].push_back(edges[i][1])

        // Add the first node of the edge to the adjacency list of the second one
        adjList[edges[i][1]].push_back(edges[i][0])

    }

    // Call the DFS algorithm, starting with the first node
    DFS(nodes[0])

    // Return
    return 0

}
