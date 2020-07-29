clear

# export MINIKUBE_HOME=~/goinfre
minikube start --vm-driver=virtualbox --extra-config=apiserver.service-node-port-range=1-35000

eval $(minikube docker-env)
export ip=$(minikube ip)

kubectl apply -f https://raw.githubusercontent.com/google/metallb/v0.8.1/manifests/metallb.yaml
kubectl apply -f srcs/yaml/metallb.yaml

docker build -t nginx-image srcs/nginx
docker build -t ftps-image srcs/ftps --build-arg ip=$ip
docker build -t mysql-image srcs/mysql
docker build -t phpmyadmin-image srcs/phpmyadmin
docker build -t wordpress-image srcs/wordpress --build-arg ip=$ip

kubectl create -f srcs/yaml/nginx.yaml
kubectl create -f srcs/yaml/ftps.yaml
kubectl create -f srcs/yaml/mysql.yaml
kubectl create -f srcs/yaml/phpmyadmin.yaml
kubectl create -f srcs/yaml/wordpress.yaml