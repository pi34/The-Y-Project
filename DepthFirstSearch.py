"""
The following implementation of the Depth-First Search algorithm searches through the entire graph by visiting the depth of 
an entire branch before backtracking and moving on to the next branch. The time complexity of this algorithm is 
approximately O(n^2).

"""

# Initialise an empty array, where all the visisted nodes will be stored
visited = []

# Define the recursive DFS function, which takes as input the graph, and the current node of the graph
def DFS (N, graph):

    # Mark the current node as visited so that it is not looped over again
    visited.append(N)

    # Iterate over all the neighbours (or edges in the graph) of the current node
    for i in graph[N]:
        
        # Check if the particular neighbour node has already been visited
        if i not in visited:

            # If so, perform DFS on this node and its neighbours
            DFS(i, graph)


# Define a function which intiates the DFS algorithm by creating an adjacency list for all the nodes
def performDFS (nodes, edges):

    # Initialise an empty adjacency list for all the nodes
    adjList = [[0]] * len(nodes)

    # Loop over all the edges to add the neighbours of each nodes to their adjacency list
    for i in range(len(edges)):

        # Add the second node of the edge to the adjacency list of the first one
        adjList[edges[i][0]].append(edges[i][1])

        # Add the first node of the edge to the adjacency list of the second one
        adjList[edges[i][1]].append(edges[i][0])

    # Call the DFS algorithm, starting with the first node
    DFS(nodes[0], adjList)
     
