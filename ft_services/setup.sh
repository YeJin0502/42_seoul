clear

# export MINIKUBE_HOME=~/goinfre
minikube start --vm-driver=virtualbox --extra-config=apiserver.service-node-port-range=1-35000

eval $(minikube docker-env)
export ip=$(minikube ip)

kubectl apply -f https://raw.githubusercontent.com/google/metallb/v0.8.1/manifests/metallb.yaml
kubectl apply -f srcs/yaml/metallb.yaml

docker build -t nginx-image srcs/nginx
# docker build -t ftps-image srcs/ftps --build-arg ip=$ip
docker build -t ftps-image srcs/ftps

kubectl create -f srcs/yaml/nginx.yaml
kubectl create -f srcs/yaml/ftps.yaml