package org.example;

import org.example.Datasoure.MyDatasource;
import org.example.pojo.user;

import java.sql.Connection;
import java.sql.SQLException;
import java.util.ArrayList;

public class JdbcUtils {


    private static MyDatasource myDatasource;

  static {

     myDatasource = new MyDatasource(ConstInformation.URL,
              ConstInformation.DRIVER,
              ConstInformation.USERNAME,
              ConstInformation.PASSWORD);

  }
    public Connection getConnection() throws SQLException {
    return myDatasource.getConnection(myDatasource.getUsername(), myDatasource.getPassword());
    }



}