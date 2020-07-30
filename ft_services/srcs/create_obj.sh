kubectl apply -f https://raw.githubusercontent.com/google/metallb/v0.8.1/manifests/metallb.yaml
kubectl apply -f srcs/yaml/metallb.yaml
kubectl create -f srcs/yaml/nginx.yaml
kubectl create -f srcs/yaml/ftps.yaml
kubectl create -f srcs/yaml/mysql.yaml
kubectl create -f srcs/yaml/phpmyadmin.yaml
kubectl create -f srcs/yaml/wordpress.yaml
# kubectl create -f srcs/yaml
# 순서가 유의한가?