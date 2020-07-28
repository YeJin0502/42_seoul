FROM alpine

RUN apk update
RUN apk --no-cache mysql

COPY my.cnf /etc/mysql
COPY mysql-init /tmp
COPY entrypoint.sh /tmp

EXPOSE 3306

ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]