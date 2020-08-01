FROM alpine

RUN apk update
RUN apk add --no-cache --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted grafana

COPY entrypoint.sh /tmp

EXPOSE 3000

ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]