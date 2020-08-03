ip=$(minikube ip)
docker build -t nginx-image srcs/nginx
docker build -t ftps-image srcs/ftps --build-arg ip=$ip
docker build -t mysql-image srcs/mysql --build-arg ip=$ip
docker build -t phpmyadmin-image srcs/phpmyadmin
docker build -t wordpress-image srcs/wordpress --build-arg ip=$ip
docker build -t influxdb-image srcs/influxdb --build-arg ip=$ip
docker build -t telegraf-image srcs/telegraf --build-arg ip=$ip
docker build -t grafana-image srcs/grafana --build-arg ip=$ip