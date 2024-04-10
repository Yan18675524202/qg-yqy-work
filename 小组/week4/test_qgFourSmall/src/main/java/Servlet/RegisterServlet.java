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

@WebServlet("/RegisterServlet")
public class RegisterServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        String s = req.getReader().readLine();

        User user = JSON.to(User.class, s);

         JdbcUtils jdbcUtils = new JdbcUtils();



        int i = jdbcUtils.addUser(user);

        if (i == 1) {
            resp.getWriter().write("Success");
        } else {
            resp.getWriter().write("Error");
        }


    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req,resp);
    }
}
