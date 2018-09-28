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
        int[] vec = {2,7,11,15};
        int target = 9;
        int[] expect = {0, 1};
        Assertions.assertArrayEquals(expect, impl.twoSum(vec, 9));
    }

}
