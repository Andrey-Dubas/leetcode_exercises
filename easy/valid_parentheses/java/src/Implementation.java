import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class Implementation {

    public boolean isValid(String str) {
        java.util.Stack<Character> stack = new Stack<>();

        java.util.HashMap<Character, Character> maps = new HashMap<Character, Character>();
        maps.put(']', '[');
        maps.put(')', '(');
        maps.put('}', '{');

        for (char ch: str.toCharArray())
        {
            if ("[{(".indexOf(ch) != -1)
            {
                stack.push(ch);
            }

            if(maps.containsKey(ch)) {
                if (maps.get(ch) == stack.peek()) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
}
