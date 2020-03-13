FROM debian:latest
MAINTAINER gmoon <gmoon@student.42seoul.kr>

RUN apt-get update
RUN apt-get install -y nginx \
    apache2 php5 php5-mysql mysql-client wget

RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf
RUN chown -R www-data:www-data /var/lib/nginx

VOLUME ["/data", "/etc/nginx/site-enabled", "/var/log/nginx"]

WORKDIR /etc/nginx

CMD ["nginx"]

EXPOSE 80
EXPOSE 443

# 아 몰겠어ㅓㅓㅓ