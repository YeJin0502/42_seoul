mysql -u root < /tmp/init_mysql
until [ $? != 1 ]
do
	sleep 1
	mysql -u root < /tmp/init_mysql
done

mysql -u root --skip-password wordpress < /tmp/wordpress.sql
until [ $? != 1 ]
do
	sleep 1
	mysql -u root --skip-password wordpress < /tmp/wordpress.sql
done

# until mysql
# do
#     echo "no_up"
# done

# # mysql -u root < /tmp/init_mysql
# # mysql -u root --password= wordpress < /tmp/wordpress.sql

# echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
# echo "CREATE USER 'wordpress_user'@'%' IDENTIFIED BY 'password';" | mysql -u root --skip-password
# echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpress_user'@'%' WITH GRANT OPTION;" | mysql -u root --skip-password
# # echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
# # echo "DROP DATABASE test" | mysql -u root --skip-password
# echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password
# mysql wordpress -u root --password=  < /tmp/wordpress.sql