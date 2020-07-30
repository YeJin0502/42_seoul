ip=$(minikube ip)
docker build -t nginx-image srcs/nginx
docker build -t ftps-image srcs/ftps --build-arg ip=$ip
docker build -t mysql-image srcs/mysql --build-arg ip=$ip
docker build -t phpmyadmin-image srcs/phpmyadmin
docker build -t wordpress-image srcs/wordpress --build-arg ip=$ip