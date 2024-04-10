package Datasoure;

import javax.sql.DataSource;
import java.io.PrintWriter;
import java.sql.*;
import java.util.logging.Logger;

public interface MyDatasourceInterface extends DataSource {
    @Override
    default Connection getConnection() throws SQLException{
        return  null;
    }

    @Override
    default Connection getConnection(String username, String password) throws SQLException {
        return null;
    }

    @Override
    default PrintWriter getLogWriter() throws SQLException {
        return null;
    }

    @Override
    default void setLogWriter(PrintWriter out) throws SQLException {

    }

    @Override
    default void setLoginTimeout(int seconds) throws SQLException {
    }

    @Override
    default int getLoginTimeout() throws SQLException {
        return 0;
    }


    @Override
    default <T> T unwrap(Class<T> iface) throws SQLException {
        return null;
    }

    @Override
    default boolean isWrapperFor(Class<?> iface) throws SQLException {
        return false;
    }

    @Override
    default Logger getParentLogger() throws SQLFeatureNotSupportedException {
        return null;
    }

    @Override
    default ConnectionBuilder createConnectionBuilder() throws SQLException {
        return DataSource.super.createConnectionBuilder();
    }

    @Override
    default ShardingKeyBuilder createShardingKeyBuilder() throws SQLException {
        return DataSource.super.createShardingKeyBuilder();
    }
}
