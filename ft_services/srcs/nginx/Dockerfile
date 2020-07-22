# docker rm $(docker ps -a -q)
# docker rmi $(docker images -a -q)
# docker run -it --name nginx -p 80:80 -p 443:443 alpine

# https://www.cyberciti.biz/faq/how-to-install-nginx-web-server-on-alpine-linux/
# https://www.osetc.com/en/how-to-install-and-configure-nginx-web-server-on-alpine-linux.html

FROM alpine

RUN apk update

RUN apk add --no-cache nginx openssl openssh

RUN adduser -D -g 'Nginx www user' -h /home/mynginx/ mynginx

COPY default.conf /etc/nginx/conf.d/
COPY entrypoint.sh /tmp/
RUN mkdir -p /run/nginx
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt -subj "/CN=nginxsvc/O=nginxsvc"

EXPOSE 80 443 22
# 22는 뭐임?

RUN apk add --no-cache openrc

ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]