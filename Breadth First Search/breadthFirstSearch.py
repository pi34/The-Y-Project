"""
The following implementation of the Breadth-First Search algorithms search through the entire graph by visiting all the 
neighbours of particular nodes in a sequence. The time complexity of this algorithm is O(n).

"""

# Define the BFS function which takes as input, the nodes and edges
def BFS (nodes, edges):

    # Initialise an empty adjacency list for all the nodes
    adjList = [[0]] * len(nodes)

    # Loop over all the edges to add the neighbours of each nodes to their adjacency list
    for i in range(len(edges)):

        # Add the second node of the edge to the adjacency list of the first one
        adjList[edges[i][0]].append(edges[i][1])

        # Add the first node of the edge to the adjacency list of the second one
        adjList[edges[i][1]].append(edges[i][0])

    # Initialise an empty array, where all the visisted nodes will be stored
    visited = []

    # Initialise an empty array, which will act as the queue for our algorithm, telling us which node is to be visited next
    queue = []

    # To begin, add the first node to the queue
    queue.append(nodes[0])

    # Subsequently, mark the first node as visited
    visited.append[nodes[0]]

    # Now run a while which terminates only when the entire queue becomes empty, i.e, there are no other nodes left to visit
    while len(queue) > 0:

        # Remove the last element from the queue since it has now been visited, and store it
        node = queue.pop()

        # Iterate over all the neigbours of the current node
        for i in adjList[node]:

            # Check if the particular neighbour node has already been visited
            if i not in visited:

                # If so, mark this neighbour as visited
                visited.append(i)

                # Add the neighbour to the queue
                queue.append(i)

                  
