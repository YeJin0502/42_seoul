# docker rm $(docker ps -a -q)
# docker rmi $(docker images -a -q)
# docker run -it --name nginx -p 80:80 -p 443:443 alpine

FROM alpine

RUN apk update && apk upgrade
# upgrade 할게 있나?
RUN apk add --no-cache nginx
# no-cache 하면 뭐가 좋지?

COPY default.conf /etc/nginx/conf.d/
# 여기에 하는게 맞나? /etc/nginx/nginx.conf 도 있는데... 어디에 하는거지?
COPY entrypoint.sh /tmp

EXPOSE 80 443 22
# 22는 뭐임?

ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]
