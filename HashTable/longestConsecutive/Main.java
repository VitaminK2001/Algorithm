package longestConsecutive;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int longestConsecutive(int[] nums) {
        // key表示num，value表示num所在连续区间的长度
        Map<Integer, Integer> map = new HashMap<>();
        int ans = 0;
        for (int num : nums) {
            // 当map中不包含num，也就是num第一次出现
            if (!map.containsKey(num)) {
                // left为num-1所在连续区间的长度，更进一步理解为：左连续区间的长度
                int left = map.getOrDefault(num - 1, 0);
                // right为num+1所在连续区间的长度，更进一步理解为：右连续区间的长度
                int right = map.getOrDefault(num + 1, 0);
                // 当前连续区间的总长度
                int curLen = left + right + 1;
                ans = Math.max(ans, curLen);
                // 将num加入map中，表示已经遍历过该值。其对应的value可以为任意值。
                map.put(num, -1); // 中间的数无所谓 只要有记录表示遍历过就行
                // 更新当前连续区间左边界和右边界对应的区间长度
                map.put(num - left, curLen); // 当他左边没有数的时候 num就是区间的左端点
                map.put(num + right, curLen); // 当他右边没有数的时候 num就是区间的右端点
            }
        }
        return ans;
    }
};

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        s.longestConsecutive(new int[]{2,4,3,3,5,1,3,2});
    }
}