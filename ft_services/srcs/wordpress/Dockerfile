FROM alpine

RUN apk update
RUN apk add --no-cache php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session mysql-client

ARG ip

RUN wget http://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
RUN rm latest.tar.gz
RUN mv wordpress /etc

COPY wp-config.php /etc/wordpress
# RUN sed -i "s/minikube_ip/$ip/g" /etc/wordpress/wp-config.php
RUN printf "\ndefine( 'WP_HOME', 'http://$ip:5050' );\n" >> /etc/wordpress/wp-config.php
RUN printf "\ndefine( 'WP_SITEURL', 'http://$ip:5050' );\n" >> /etc/wordpress/wp-config.php

COPY wordpress.sql /tmp
COPY init-wordpress.sh /tmp
COPY entrypoint.sh /tmp

EXPOSE 5050

ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]