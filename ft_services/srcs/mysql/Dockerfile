FROM alpine

RUN apk update
# RUN apk add --no-cache mysql
RUN apk add mysql mysql-client

ARG ip

RUN mkdir -p /run/mysqld
COPY init_mysql /tmp
COPY init_wordpress.sh /tmp
COPY entrypoint.sh /tmp
COPY my.cnf /etc/mysql
# COPY init-db.sh /tmp
COPY wordpress.sql /tmp
RUN printf "CHECK MINIKUBE IP -> [$ip]\n"
RUN sed -i "s/192.168.99.154/$ip/g" /tmp/wordpress.sql
RUN chmod 755 /tmp/*

EXPOSE 3306

ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]