mysql_install_db --user=root
mysql -u root < /tmp/init_mysql
mysql -u root wordpress < /tmp/wordpress.sql
# mysqld --user=root --bootstrap < /tmp/init_mysql
mysqld_safe -u root

# nohup sh /tmp/init-db.sh &
# mysql_install_db --user=mysql --datadir="/var/lib/mysql"
# mysqld --datadir="/var/lib/mysql"