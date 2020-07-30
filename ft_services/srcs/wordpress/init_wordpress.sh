sleep 3
mysql --host='mysql-service' --user='wordpress_user' --password='password' wordpress < /tmp/wordpress.sql
until [ $? != 1 ]
do
	sleep 1
	mysql --host='mysql-service' --user='wordpress_user' --password='password' wordpress < /tmp/wordpress.sql
done