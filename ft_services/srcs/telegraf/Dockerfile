FROM alpine

RUN apk add --no-cache --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted telegraf

ARG ip

COPY telegraf.conf /etc/telegraf/telegraf.conf
# RUN printf "CHECK MINIKUBE IP -> [$ip]\n"
# RUN sed -i "s/localhost/$ip/g" /etc/telegraf/telegraf.conf
COPY entrypoint.sh /tmp

ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]