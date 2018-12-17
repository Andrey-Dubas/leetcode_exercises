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
    public void test0()
    {
        String[] input = {"flower","flow","flight"};
        char[] expect = {'f', 'l'};
        Assertions.assertArrayEquals(expect, impl.longestCommonPrefix(input).toCharArray());
    }

    @Test
    public void test1()
    {
        String[] input = {"dog","racecar","car"};
        char[] expect = {};
        Assertions.assertArrayEquals(expect, impl.longestCommonPrefix(input).toCharArray());
    }

    @Test
    public void test2()
    {
        String[] input = {};
        char[] expect = {};
        Assertions.assertArrayEquals(expect, impl.longestCommonPrefix(input).toCharArray());
    }

    @Test
    public void test3()
    {
        String[] input = {"dog","doggish","doggo"};
        char[] expect = {'d', 'o', 'g'};
        Assertions.assertArrayEquals(expect, impl.longestCommonPrefix(input).toCharArray());
    }

    @Test
    public void test4()
    {
        String[] input = {"doggish", "dog","doggo"};
        char[] expect = {'d', 'o', 'g'};
        Assertions.assertArrayEquals(expect, impl.longestCommonPrefix(input).toCharArray());
    }
}
