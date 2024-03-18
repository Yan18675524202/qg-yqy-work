package org.example;

import org.example.pojo.user;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

// 按两次 Shift 打开“随处搜索”对话框并输入 `show whitespaces`，
// 然后按 Enter 键。现在，您可以在代码中看到空格字符。
public class Main {
    public static void main(String[] args) throws SQLException {


        JdbcUtils jdbcUtils = new JdbcUtils();
        Connection connection = jdbcUtils.getConnection();

        String sql="select * from user";
        PreparedStatement preparedStatement = connection.prepareStatement(sql);

        ResultSet resultSet = preparedStatement.executeQuery();

        ArrayList<user> list = new ArrayList<>();
        while (resultSet.next()){
            int id = resultSet.getInt("id");
            String name = resultSet.getString("name");
            user user = new user(name,id);
            list.add(user);
        }
        System.out.println(list);

        resultSet.close();
        preparedStatement.close();
        connection.close();
    }
}