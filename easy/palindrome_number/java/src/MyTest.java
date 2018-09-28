import org.junit.Before;
import org.junit.Test;
import org.junit.jupiter.api.Assertions;

import java.util.Vector;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class MyTest {
    Implementation impl;

    @Before
    public void setUp()
    {
        impl = new Implementation();
    }

    @Test
    public void test1()
    {
        Assertions.assertEquals(true, impl.isPalindrome(121));
    }

    @Test
    public void test2()
    {
        Assertions.assertEquals(true, impl.isPalindrome(1221));
    }

    @Test
    public void test3()
    {
        Assertions.assertEquals(false, impl.isPalindrome(-1221));
    }

    @Test
    public void test4()
    {
        Assertions.assertEquals(true, impl.isPalindrome(0));
    }
}
