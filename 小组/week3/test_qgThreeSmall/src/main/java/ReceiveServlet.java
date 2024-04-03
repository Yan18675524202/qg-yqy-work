import com.alibaba.fastjson.JSONObject;
import com.fasterxml.jackson.databind.ObjectMapper;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/ReceiveServlet")
public class ReceiveServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 设置响应内容类型
        resp.setContentType("application/json");
       // 从请求中获取表单数据
        String s = req.getReader().readLine();




        // 创建JSON对象并设置表单数据
        ObjectMapper objectMapper = new ObjectMapper();
        String s1 = objectMapper.writeValueAsString(s);


        // 将JSON对象转换为字符串


        // 将JSON字符串发送回前端
        PrintWriter out = resp.getWriter();
        out.print(s1);
        out.flush();


    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req,resp);
    }
}
