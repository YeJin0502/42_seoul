FROM alpine

RUN apk update
RUN apk add --no-cache --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted grafana

ARG ip

COPY entrypoint.sh /tmp
COPY dashboards.yaml /usr/share/grafana/conf/provisioning/dashboards
COPY influxdb.yaml /usr/share/grafana/conf/provisioning/datasources
RUN mkdir -p /var/lib/grafana/dashboards
# 안만들어줘도 copy가 되나?
COPY dashboards /var/lib/grafana/dashboards

EXPOSE 3000

ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]