# Graph

-------------------------------------------------------------------------------------------------------------------------------------------------------
## Graph shortest path questions: 


1. Shortest path from a src to all nodes in DAG 
	Method1 : Dijkstra 

	Method2 : Because it a DAG 
	Algo: Toposort + Edge relaxation. 
	1. Do a topological sort
	2. Do relaxation of edges from left to right using a distance array. 

2. Shortest path from a src to all nodes in undirected graph with unit weight. 

	using Dijkstra's algo - queue version will work here since all weights are equal. 
	Algo: Using simple queue + dist array 
	1. Push source in queue. 
	2. Do relaxation of edges, push a node into queue only when updation takes place. 

3. Dijkstra's Algo - Single Source Shortes Path finding algorithm 

Maintain any container(queue, pq or set) and dist array 

Push into pq when updation takes place. 
	
	3.1 Using queue. 
	3.2 Using pq 
	3.3 Using set 

Dijkstra's algo does not work for graph containing even a single negative weight or a negative cycle. 


4. Bellman Ford Algo - Single Source Shortes Path finding algorithm 

	- Dijkstra fails when we have -ve weight or -ve cycle. 
	- Bellman Ford works with negative weights and also helps us to detect negative cycle. 
	-Negative cyle- cylce whose total path wt < 0. 
	- Only applicable for DIRECTED GRAPHS. 
	- Incase of undirected graph, first convert it into a directed graph. 

	Algo: 
	1. Relax all edges N-1 times sequentially. 

	Relax ->
	if (dist[node] + wt < dist[adjNode]){
		dist[adjNode] = dist[node]+wt;
	}

	NOTE: Negative edges are allowed but negative cycle is not allowed. For a normal graph dist array will not get updated after N-1 iterations are done. But, if there is a negative cycle present, than it will update even at the Nth iteration. 


5. Floyd Warshall Algo 