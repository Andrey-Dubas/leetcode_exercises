import org.junit.Before;
import org.junit.Test;
import org.junit.jupiter.api.Assertions;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class MyTest {
    Implementation impl;

    @Before
    public void setUp()
    {
        impl = new Implementation();
    }

    @Test
    public void test_PairBrackets_True()
    {
        Assertions.assertEquals(true, impl.isValid("()"));
    }

    @Test
    public void test_PlainPairs_True()
    {
        Assertions.assertEquals(true, impl.isValid("()[]{}"));
    }

    @Test
    public void test_NestedPairs_True()
    {
        Assertions.assertEquals(true, impl.isValid("({[]})"));
    }

    @Test
    public void test_Unmatched_False()
    {
        Assertions.assertEquals(false, impl.isValid("(]"));
    }

}
