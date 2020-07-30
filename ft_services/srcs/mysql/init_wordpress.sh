until mysql
do
    echo "no_up"
done

mysql -u root < /tmp/init_mysql
mysql -u root --password= wordpress < /tmp/wordpress.sql