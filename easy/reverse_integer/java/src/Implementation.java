import java.util.HashMap;
import java.util.Map;
import java.util.Stack;
import java.util.Vector;

public class Implementation {

    public int reverse(int x) {
        int result = 0;
        while (x != 0)
        {
            int curNumber = x % 10;
            if (result > Integer.MAX_VALUE/10 ||
                    (result == Integer.MAX_VALUE/10 && curNumber > Integer.MAX_VALUE%10))
            {
                return 0;
            }

            if (result < Integer.MIN_VALUE/10 ||
                    (result == Integer.MIN_VALUE/10 && curNumber < Integer.MIN_VALUE%10))
            {
                return 0;
            }
            result = result * 10 + x % 10;
            x = x/10;
        }

        return result;
    }
}
