FROM alpine

RUN apk update
RUN apk add --no-cache nginx openssl openssh openrc

RUN adduser -D -g 'nginx www user' -h /home/www/ www
RUN mkdir -p /run/nginx

COPY default.conf /etc/nginx/conf.d/default.conf
# COPY nginx.conf /etc/nginx/nginx.conf
# 두 개 파일 차이점이 뭐임?
COPY index.html /home/www/index.html
COPY entrypoint.sh /tmp/

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt -subj "/CN=nginxsvc/O=nginxsvc"

# RUN ssh-keygen -t rsa -f /etc/ssh/ssh_host_rsa_key -N ""

# EXPOSE 80 443 22
EXPOSE 80 443

ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]