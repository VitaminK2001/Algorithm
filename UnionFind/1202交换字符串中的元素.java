package UnionFind;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

class UnionFind{
    private int[] parent;
    public UnionFind(int n) {
        parent = new int[n];
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int Find(int i) {
        if(parent[i] != i) {
            parent[i] = Find(parent[i]);
        }
        return parent[i];
    }
    void Union(int i1, int i2) {
        parent[Find(i1)] = Find(i2);
    }
}

class Solution {
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        int len = s.length();
        UnionFind unionFind = new UnionFind(len);
        for(List<Integer> pair : pairs) {
            int i1 = pair.get(0);
            int i2 = pair.get(1);
            unionFind.Union(i1, i2);
        }
        char[] charArray = s.toCharArray();
        Map<Integer, PriorityQueue<Character>> hashMap = new HashMap<>(len);
        for(int i = 0; i < len; ++i) {
            int root = unionFind.Find(i);
            if(hashMap.containsKey(root)) {
                hashMap.get(root).offer(charArray[i]);
            }else {
                PriorityQueue<Character> minHeap = new PriorityQueue<>();
                minHeap.offer(charArray[i]);
                hashMap.put(root, minHeap);
            }
        }
        StringBuilder stringBuilder = new StringBuilder();
        for(int i = 0; i < len; ++i) {
            int root = unionFind.Find(i);
            stringBuilder.append(hashMap.get(root).poll());
        }
        return stringBuilder.toString();
    }
}