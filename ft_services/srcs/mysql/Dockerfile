FROM alpine

RUN apk update
# RUN apk add --no-cache mysql
RUN apk add mysql

RUN mkdir -p /run/mysqld
COPY my.cnf /etc/mysql
COPY mysql-init /tmp
COPY entrypoint.sh /tmp

EXPOSE 3306

ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]