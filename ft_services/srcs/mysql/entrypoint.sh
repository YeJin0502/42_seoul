# mysql_install_db --user=root
# mysqld --user=root --bootstrap < /tmp/mysql-init
# mysqld --user=root

mysql_install_db --user=root --datadir="/var/lib/mysql"
nohup sh /tmp/init-db.sh
mysqld --datadir="/var/lib/mysql"