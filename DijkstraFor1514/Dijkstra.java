package DijkstraFor1514;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;

class State{
    int id;
    double SuccProb;
    State(int id, double SuccProb) {
        this.id = id;
        this.SuccProb = SuccProb;
    }
}

public class Dijkstra { 
    public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
        List<double[]>[] graph = new LinkedList[n];
        for(int i = 0; i < n; ++i) {
            graph[i] = new LinkedList<>();
        }
        for(int i = 0; i < edges.length; ++i) {
            int from = edges[i][0];
            int to = edges[i][1];
            double weight = succProb[i];
            graph[from].add(new double[]{to, weight});
            graph[to].add(new double[]{from, weight});
        }

        return dijkstra(n, edges, succProb, start, end, graph);
    }
    double dijkstra(int n, int[][] edges, double[] succProb, int start, int end, List<double[]>[] graph) {
        double[] probTo = new double[n];
        Arrays.fill(probTo, -1);
        probTo[start] = 1;
        PriorityQueue<State> pq = new PriorityQueue<>((a,b)->{return (int)(a.SuccProb - b.SuccProb);});
        pq.offer(new State(start, 1));
        while(!pq.isEmpty()){
            State curState = pq.poll();
            int curId = curState.id;
            double curSuccProb = curState.SuccProb;

            if(curSuccProb < probTo[curId]) {
                continue;
            }
            if(curId == end) {
                return curSuccProb;
            }

            for(double[] neighbor : graph[curId]) {
                int nextNodeId = (int) neighbor[0];
                double ProbToNextNode = curSuccProb * neighbor[1];
                if(ProbToNextNode > probTo[nextNodeId]) {
                    probTo[nextNodeId] = ProbToNextNode;
                    pq.offer(new State(nextNodeId, ProbToNextNode));
                }
            }
        }
        return 0.0;
    }
}
