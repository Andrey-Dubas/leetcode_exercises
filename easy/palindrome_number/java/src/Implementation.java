import java.util.HashMap;
import java.util.Map;
import java.util.Stack;
import java.util.Vector;

public class Implementation {

    public boolean isPalindrome(int x) {
        int copy = x;
        int reversed = 0;
        if (x < 0) return false;

        while (copy != 0)
        {
            reversed = reversed * 10 + copy % 10;
            copy /= 10;
        }
        return reversed == x;
    }
}
