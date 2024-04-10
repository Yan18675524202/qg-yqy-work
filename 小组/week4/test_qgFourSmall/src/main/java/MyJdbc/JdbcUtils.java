package MyJdbc;

import Datasoure.MyDatasource;
import pojo.User;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class JdbcUtils {


    private static MyDatasource myDatasource;

  static {

     myDatasource = new MyDatasource(ConstInformation.URL,
              ConstInformation.DRIVER,
              ConstInformation.USERNAME,
              ConstInformation.PASSWORD);

  }
  public int addUser(User user) {

      PreparedStatement preparedStatement = null;
      Connection connection = null;
      int resultSet = 0;
      String sql = " insert  into user (id, username , password)values (null ,?,?) ";
      try {
          connection = getConnection();
          connection.setAutoCommit(false);

          preparedStatement = connection.prepareStatement(sql);

          preparedStatement.setObject(1, user.getUsername());
          preparedStatement.setObject(2, user.getPassword());

           resultSet = preparedStatement.executeUpdate();

          connection.commit();


      } catch (SQLException e) {
          try {
              if (connection != null) {
                  connection.rollback();
              }
          } catch (SQLException ex) {
              System.out.println("Error rolling back transaction: " + ex.getMessage());
          }
          System.out.println("Error inserting record: " + e.getMessage());
      } finally {
          // 关闭连接和语句对象
          try {
              if (preparedStatement != null) {
                  preparedStatement.close();
              }
              if (connection != null) {
                  connection.close();
              }
          } catch (SQLException e) {
              System.out.println("Error closing resources: " + e.getMessage());
          }



      }
      return resultSet;
  }



    public User selectOne(User user) throws SQLException {


        Connection connection = getConnection();

        String sql="select * from user where username = ? and password = ?";
        PreparedStatement preparedStatement = connection.prepareStatement(sql);

        preparedStatement.setObject(1,user.getUsername());
        preparedStatement.setObject(2,user.getPassword());
        ResultSet resultSet = preparedStatement.executeQuery();

        User user1 = new User();
        while (resultSet.next()){
            String password= resultSet.getString("password");
            String name = resultSet.getString("username");
            user1 = new User(name,password);

        }




        resultSet.close();
        preparedStatement.close();
        connection.close();

      return user1;
    }



    public Connection getConnection() throws SQLException {
    return myDatasource.getConnection(myDatasource.getUsername(), myDatasource.getPassword());
    }



}