package Datasoure;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class MyDatasource extends MyAbstractDatasource {
    //空闲链接池
    private  final List<Connection> idleConnections = new ArrayList<Connection>();

    //激活链接池
    private  final List<Connection> activeConnections = new ArrayList<Connection>();
    //最大正在使用链接数
    private final int poolMaxActiveConnections = 10;
    //最大空闲链接数
    private final int poolMaxIdleConnections = 5;
    //获取一个链接最多等待时间
    private final int poolTimeToWait = 30*1000;
    //监视器对象(同步)
    private final Object monitor = new Object();

    private final Object watch = new Object();

    public MyDatasource(String Url ,String Driver,String username,String password) {
        this.setUrl(Url);
        this.setDriver(Driver);
        this.setUsername(username);
        this.setPassword(password);
    }

    @Override
    public Connection getConnection(String username , String password) throws SQLException {
        Boolean wait = false;
        Connection connection = null;

        while (connection==null) {
            synchronized (monitor) {
                if (!idleConnections.isEmpty()) {
                    connection = idleConnections.remove(0);
                } else {
                    if (activeConnections.size() < poolMaxActiveConnections) {
                        try {
                            Class.forName(this.getDriver());
                        } catch (ClassNotFoundException e) {
                            throw new RuntimeException(e);
                        }
                        connection = DriverManager.getConnection(this.getUrl(),username,password);


                    }

                }
            }

            if (!wait) {
                wait = true;
            }
            if (connection == null) {
                try {
                    monitor.wait(poolTimeToWait);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                    break;
                }
            }
        }


        if (connection!=null) {

            activeConnections.add(connection);
        }

            return connection;

        }


        public void closeConnection(Connection connection){
           synchronized (watch){
               activeConnections.remove(connection);

               if (idleConnections.size()<poolMaxIdleConnections){
                   idleConnections.add(connection);

               }

               monitor.notifyAll();
           }
        }

    }



