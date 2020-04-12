FROM debian:buster
LABEL maintainer="gmoon@student.42seoul.kr"

# install
RUN apt update
RUN apt install -y nginx mariadb-server php-fpm php-mysql
RUN apt install -y curl php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip
RUN apt install -y wget php-json php-mbstring
RUN apt install -y libnss3-tools
WORKDIR /tmp
RUN curl -LO https://wordpress.org/latest.tar.gz
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN wget https://github.com/FiloSottile/mkcert/releases/download/v1.1.2/mkcert-v1.1.2-linux-amd64

# wordpress
RUN tar xzvf latest.tar.gz; \
	mv wordpress /var/www/html
ADD srcs/wp-config.php /var/www/html/wordpress/wp-config.php
RUN service mysql start; \
	echo "CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;" | mysql; \
	echo "GRANT ALL ON wordpress.* TO 'wordpress_user'@'localhost' IDENTIFIED BY 'password';" | mysql; \
	echo "FLUSH PRIVILEGES;" | mysql

# phpmyadmin
RUN tar xzvf phpMyAdmin-4.9.0.1-all-languages.tar.gz; \
	mv phpMyAdmin-4.9.0.1-all-languages /usr/share/phpmyadmin
ADD srcs/config.inc.php /usr/share/phpmyadmin/config.inc.php
RUN mkdir /usr/share/phpmyadmin/tmp; \
	chmod 777 /usr/share/phpmyadmin/tmp; \
	chmod 644 /usr/share/phpmyadmin/config.inc.php
RUN ln -s /usr/share/phpmyadmin /var/www/html/phpmyadmin

# ssl
RUN mv mkcert-v1.1.2-linux-amd64 mkcert; \
	chmod +x mkcert; \
	./mkcert -install; \
	./mkcert localhost

# nginx
ADD srcs/default /etc/nginx/sites-available/default

EXPOSE 80 443

CMD service mysql start; \
	service php7.3-fpm start; \
	nginx -g 'daemon off;'