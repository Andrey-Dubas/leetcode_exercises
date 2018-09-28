import java.util.HashMap;
import java.util.Map;
import java.util.Stack;
import java.util.Vector;

public class Implementation {

    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0)
        {
            return "";
        }

        String first = strs[0];
        int minLen = first.length();

        for (int i = 1; i < strs.length; ++i)
        {
            minLen = Math.min(minLen, strs[i].length());
        }

        for (int i = 0; i < minLen; ++i)
        {
            for (int j = 1; j < strs.length; ++j)
            {
                if (first.charAt(i) != strs[j].charAt(i)) {
                    return first.substring(0, i);
                }
            }
        }
        return first.substring(0, minLen);
    }
}
