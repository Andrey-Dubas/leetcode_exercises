import java.util.HashMap;
import java.util.Map;
import java.util.Stack;
import java.util.Vector;

public class Implementation {

    public int[] twoSum(int[] v, int sum) {
        java.util.HashMap<Integer, Integer> maps = new HashMap<Integer, Integer>();

        for (int i = 0; i < v.length; ++i)
        {
            int seekElement = sum-v[i];
            if (maps.containsKey(seekElement))
            {
                int[] result = new int[2];
                result[0] = maps.get(seekElement);
                result[1] = i;
                return result;
            }
            maps.put(v[i], i);
        }
        return null;
    }
}
