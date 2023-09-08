package DijkstraFor743;

import java.util.LinkedList;
import java.util.List;

public class Solution743 {
    public int networkDelayTime(int[][] times, int n, int k) {
        // 因为结点编号从1开始
        List<int[]>[] graph = new LinkedList[n+1];
        for(int i = 1; i <= n; ++i) {
            graph[i] = new LinkedList<>();
        }
        for(int[] edge : times) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            graph[from].add(new int[]{to, weight});
        }
        Dijkstra dijkstra = new Dijkstra();
        int[] distTo = dijkstra.dijkstra(k, graph);
        int res = 0;
        for(int i = 1; i < distTo.length; ++i) {
            if(distTo[i] == Integer.MAX_VALUE) {
                return -1;
            }
            res = Math.max(res, distTo[i]);
        }
        return res;
    }
    public static void main(String[] args) {
        int[][] times = new int[][]{{2,1,1},{2,3,1},{3,4,1}};
        int n = 4;
        int k = 2;
        Solution743 solution743 = new Solution743();
        System.out.println(solution743.networkDelayTime(times, n, k));
    }
}
