until mysql
do
	echo "NO_UP" > /dev/null
done

mysql -uroot --skip-password < init-mysql
mysql wordpress -uroot --password= < /tmp/wordpress.sql