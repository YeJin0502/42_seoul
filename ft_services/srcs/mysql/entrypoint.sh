#!/bin/sh

nohup /tmp/init_wordpress.sh &

# /usr/bin/mysql_install_db --user=mysql --datadir="/var/lib/mysql"
# /usr/bin/mysqld_safe --datadir="/var/lib/mysql"
# /usr/bin/mysql_install_db --user=mysql
/usr/bin/mysql_install_db
# 이게 문제였을까? --user=mysql일 때 됐음.
/usr/bin/mysqld_safe

# mysql_install_db --user=root
# mysql -u root < /tmp/init_mysql
# mysql -u root wordpress < /tmp/wordpress.sql
# # mysqld --user=root --bootstrap < /tmp/init_mysql
# mysqld

# nohup sh /tmp/init-db.sh &
# mysql_install_db --user=mysql --datadir="/var/lib/mysql"
# mysqld --datadir="/var/lib/mysql"