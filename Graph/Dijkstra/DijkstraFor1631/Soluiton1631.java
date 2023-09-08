package DijkstraFor1631;

public class Soluiton1631 {
    public static void main(String[] args) {
        Dijkstra dijkstra = new Dijkstra();
        int[][] heights = new int[][]{{1,2,2},{3,8,2},{5,3,5}};
        System.out.println(dijkstra.minimumEffortPath(heights));
    }
}
