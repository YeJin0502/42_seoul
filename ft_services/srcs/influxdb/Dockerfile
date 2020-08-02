FROM alpine

RUN apk update
RUN apk add --no-cache influxdb
RUN apk add --no-cache --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted telegraf

COPY telegraf.conf /etc/telegraf/telegraf.conf
COPY influxdb.conf /etc/influxdb.conf
COPY entrypoint.sh /tmp

EXPOSE 8086

ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]