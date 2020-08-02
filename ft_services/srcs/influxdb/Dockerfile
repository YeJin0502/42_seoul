FROM alpine

RUN apk update
RUN apk add --no-cache influxdb
RUN apk add --no-cache --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted telegraf

ARG ip

COPY telegraf.conf /etc/telegraf/telegraf.conf
COPY influxdb.conf /etc/influxdb.conf
RUN sed -i 's/127.0.0.1:8088/$ip:8086/g' /etc/influxdb.conf
COPY entrypoint.sh /tmp

# VOLUME ["/var/lib/influxdb"]

EXPOSE 8086

ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]