package Servlet;

import MyJdbc.JdbcUtils;
import com.alibaba.fastjson2.JSON;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import pojo.User;

import java.io.IOException;
import java.sql.SQLException;

@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {




        String s = req.getReader().readLine();


        User user = JSON.to(User.class,s);
        JdbcUtils jdbcUtils = new JdbcUtils();

        try {
            User user1 = jdbcUtils.selectOne(user);
            System.out.println(user1);
            if (user1.getUsername()!=null){
                resp.getWriter().write("success");
            }else {
                resp.getWriter().write("Error");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }





    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req,resp);
    }
}
