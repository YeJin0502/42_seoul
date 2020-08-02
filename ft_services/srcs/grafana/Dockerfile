FROM alpine

RUN apk update
RUN apk add --no-cache --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted grafana

ARG ip

COPY entrypoint.sh /tmp
COPY defaults.ini /usr/share/grafana/conf/defaults.ini
RUN sed -i "s/change_to_ip/$ip/g" /usr/share/grafana/conf/defaults.ini

EXPOSE 3000

ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]