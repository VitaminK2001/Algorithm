package Dijkstra;

import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

class State{
    // 存放每个节点的id 和到Start节点的距离
    int id;
    int distFromStart;
    State(int id, int distFromStart){
        this.id = id;
        this.distFromStart = distFromStart;
    }
}

public class Dijkstra{
    int[] dijkstra(int start, List<int[]>[] graph){
        // 函数计算从起点start到所有结点的路径长度
        int[] distTo = new int[graph.length];
        // base case
        Arrays.fill(distTo, Integer.MAX_VALUE);
        distTo[start] = 0;
        // priority queue 
        Queue<State> pq = new PriorityQueue<>((a, b)->{
            return a.distFromStart - b.distFromStart; //距离起点近的点优先算
        });
    
        // begin
        pq.offer(new State(start, 0));
        while(!pq.isEmpty()) {
            State curState = pq.poll();
            int curNodeId = curState.id;
            int curDistFromStart = curState.distFromStart;
    
            // if start->curNode 不需要更新 这条路到该节点是一条废路
            if(curDistFromStart > distTo[curNodeId]) {
                continue; 
            }
    
            // 如果需要更新
            for(int[] neighbor : graph[curNodeId]) {
                int nextNodeId = neighbor[0]; // 下一个节点的标号
                int distToNextNode = neighbor[1] + distTo[curNodeId]; // 原点通过该节点到下一个节点的距离
                // 如果从起点到达下一个节点的距离可减小
                if(distTo[nextNodeId] > distToNextNode) { 
                    distTo[nextNodeId] = distToNextNode;
                    pq.offer(new State(nextNodeId, distToNextNode));
                }
            }
        }
        return distTo;
    }
}


