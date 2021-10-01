package GRAPH.Java;
import java.util.*;
import jdk.internal.org.jline.utils.InputStreamReader;
import java.io.*;

// Adjancy List Representation of Graph

class Graph-Representation{

        static class Edge{
            int src;       // source
            int nbr;    // neighbour
            int w;      // weight

            Edge(int src,int nbr, int w){
                this.src = src;
                this.nbr = nbr;
                this.w = w;
            }

    public static void main(String[] args){

            BufferedOutputStream br = new BufferedReader(new InputStreamReader(System.in));

            // number of vertex

            int size = 6;

            // graph represent as array of arraylist of edges

            ArrayList<Edge>[] graph = new ArrayList<Edge>[size];

            // create list for each vertex
            for(int i=0;i<size;i++)
	            {
		            graph[i] = new ArrayList<Edge>();
                }

                // here in first array 0 is connected with 3 with weight 10
                // likewise 0 connected with 1 with weight 50...... 
            
            graph[0].add(new Edge(0, 3, 10));
            graph[0].add(new Edge(0, 1, 50));

            graph[1].add(new Edge(1, 0, 50));
            graph[1].add(new Edge(1, 2, 54));

            graph[2].add(new Edge(2, 0, 23));
            graph[2].add(new Edge(2, 2, 34));
            graph[2].add(new Edge(2, 4, 52));

            graph[3].add(new Edge(3, 5, 10));
            graph[3].add(new Edge(3, 4, 40));

            graph[4].add(new Edge(4, 3, 67));
            graph[4].add(new Edge(4, 1, 89));

            graph[5].add(new Edge(5, 2, 30));
            graph[5].add(new Edge(5, 1, 20));
                
            
         }
    }
}