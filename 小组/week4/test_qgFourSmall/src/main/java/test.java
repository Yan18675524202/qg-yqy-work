import MyJdbc.JdbcUtils;
import org.junit.Test;

import pojo.User;

import java.sql.SQLException;

public class test {



    @Test
    public void test1() throws SQLException {

        JdbcUtils jdbcUtils = new JdbcUtils();

        User user = jdbcUtils.selectOne(new User("23324", "33124"));
        System.out.println(user);

    }
}
