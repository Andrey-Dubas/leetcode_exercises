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
    public void test_simpleInt()
    {
        Assertions.assertEquals(123, impl.reverse(321));
    }

    @Test
    public void test_Negative()
    {
        Assertions.assertEquals(-123, impl.reverse(-321));
    }

    @Test
    public void test_zero()
    {
        Assertions.assertEquals(0, impl.reverse(0));
    }

    @Test
    public void test_overflow()
    {
        Assertions.assertEquals(0, impl.reverse(1999999999));
    }

}
