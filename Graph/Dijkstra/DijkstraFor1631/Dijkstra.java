package DijkstraFor1631;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

class State{
    int x, y;
    int effortFromStart;
    State(int x, int y, int effortFromStart) {
        this.x = x;
        this.y = y;
        this.effortFromStart = effortFromStart;
    }
}

public class Dijkstra {
    int[][] dirs = new int[][] {{0, -1},{0, 1},{1, 0},{-1, 0}};
    // 获得上下左右相邻结点的坐标
    List<int[]> adj(int[][] matrix, int x, int y) {
        int m = matrix.length;
        int n = matrix[0].length;
        List<int[]> neighbors = new ArrayList<>();
        for(int[] dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if(nx >= m || ny >= n || nx < 0 || ny < 0) {
                continue;
            }
            neighbors.add(new int[]{nx, ny});
        }
        return neighbors;
    }

    int minimumEffortPath(int[][] heights) {
        int m = heights.length;
        int n = heights[0].length;
        int[][] effortTo = new int[m][n];
        for(int i = 0; i < m; ++i) {
            Arrays.fill(effortTo[i], Integer.MAX_VALUE);
        }
        effortTo[0][0] = 0;
        Queue<State> pq = new PriorityQueue<>((a,b)->{ return a.effortFromStart - b.effortFromStart;});
        pq.offer(new State(0, 0, 0));
        while(!pq.isEmpty()) {
            State curState = pq.poll();
            int curx = curState.x;
            int cury = curState.y;
            int curEffort = curState.effortFromStart;
            // 判断当前点是否是终点
            if(curx == m-1 && cury == n-1) return curEffort;
            if(curEffort > effortTo[curx][cury]) {
                continue;
            }
            for(int[] neighbor : adj(effortTo, curx, cury)) {
                int nextx = neighbor[0];
                int nexty = neighbor[1];
                int effortToNextNode = Math.max(effortTo[curx][cury], Math.abs(heights[curx][cury]-heights[nextx][nexty]));
                if(effortTo[nextx][nexty] > effortToNextNode) {
                    effortTo[nextx][nexty] = effortToNextNode;
                    // 只有到下一个节点的effort变小才会入队
                    pq.offer(new State(nextx, nexty, effortToNextNode)); //因为放入的是effortToNextNode，所以effortToNextNode小的会被先拿出来，而如果刚好已经到终点则一定就是答案 所以也就屙不需要重复计算
                }
            }
        }
        return -1;
    }
}
