# mysql_install_db --user=root
# mysqld --user=root --bootstrap < /tmp/mysql-init
# mysqld --user=root

nohup sh /tmp/init-db.sh &

sleep 3
mysql_install_db --user=root --datadir="/var/lib/mysql"
mysqld --datadir="/var/lib/mysql"