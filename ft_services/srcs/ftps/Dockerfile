FROM alpine

RUN apk update
# RUN apk add --no-cache vsftpd openssl openrc
RUN apk add vsftpd openssl openrc

ARG ip

COPY entrypoint.sh /tmp
COPY vsftpd.conf /etc/vsftpd/vsftpd.conf
RUN mkdir /srv/ftp

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/vsftpd/vsftpd.pem -out /etc/vsftpd/vsftpd.pem -subj "/CN=localhost"

RUN adduser -D -g 'ftps gmoon user' -h /home/gmoon/ gmoon
RUN echo "gmoon:gmoon" | chpasswd
RUN printf "CHECK MINIKUBE IP -> [$ip]\n"
RUN printf "\npasv_address=$ip\n" >> /etc/vsftpd/vsftpd.conf
RUN chown gmoon:gmoon /home/gmoon -R
RUN chmod +x /tmp
# RUN touch /etc/vsftpd.user_list
# RUN chmod 777 /etc/vsftpd.user_list
# RUN echo "gmoon" >> /etc/vsftpd.user_list
# RUN echo "vsftpd: ALL" >> /etc/hosts.allow

EXPOSE 20 21 30020 30021

ENTRYPOINT [ "sh", "/tmp/entrypoint.sh" ]