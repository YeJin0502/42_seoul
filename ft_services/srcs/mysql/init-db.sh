# until mysql
# do
# 	echo -n "" > /dev/null
# done

mysql -uroot --skip-password < init-mysql
sleep 1
mysql wordpress -uroot --skip-password < /tmp/wordpress.sql