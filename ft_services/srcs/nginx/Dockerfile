# docker rm $(docker ps -a -q)
# docker rmi $(docker images -a -q)
# docker run -it --name nginx -p 80:80 -p 443:443 alpine

FROM alpine

RUN apk update && apk upgrade
# upgrade 할게 있나?

RUN apk add --no-cache nginx openssl openssh
# no-cache 하면 뭐가 좋지?
# openssh는 뭐지?

COPY default.conf /etc/nginx/conf.d/
# 여기에 하는게 맞나? /etc/nginx/nginx.conf 도 있는데... 어디에 하는거지?
COPY entrypoint.sh /tmp/
RUN mkdir -p /run/nginx
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt -subj "/CN=nginxsvc/O=nginxsvc"

RUN adduser -D gmoon
RUN echo "gmoon:1234" | chpasswd

EXPOSE 80 443 22
# 22는 뭐임?

ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]