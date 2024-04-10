package Datasoure;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public abstract class MyAbstractDatasource implements MyDatasourceInterface {
   private String url;
  private   String driver;
  private   String username;
  private   String password;

    @Override
    public Connection getConnection() throws SQLException {
        return getConnection(username,password);
    }

    @Override
    public Connection getConnection(String username, String password) throws SQLException {

        return doGetConnection(username, password);
    }

    public  Connection doGetConnection(String username, String password) throws SQLException {
       return DriverManager.getConnection(url, username, password);

    }
    public String getUrl() {
        return url;
    }

    public void setUrl(String url) {
        this.url = url;
    }

    public String getDriver() {
        return driver;
    }

    public void setDriver(String driver) {
        this.driver = driver;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
