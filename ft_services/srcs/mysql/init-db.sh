until mysql
do
	echo -n "" > /dev/null
done

mysql -uroot --skip-password < init-mysql
mysql wordpress -uroot --skip-password < /tmp/wordpress.sql