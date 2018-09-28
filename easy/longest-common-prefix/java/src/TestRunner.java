

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

public class TestRunner {
    public static void main(String[] strs) {
        Result result = JUnitCore.runClasses(MyTest.class);

        for (Failure failure: result.getFailures())
        {
            System.out.println(failure.toString());
        }
    }
}
