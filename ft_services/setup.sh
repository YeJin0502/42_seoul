clear

# export MINIKUBE_HOME=~/goinfre
minikube start --vm-driver=virtualbox --extra-config=apiserver.service-node-port-range=1-35000

eval $(minikube docker-env)
# export ip=$(minikube ip)

kubectl apply -f https://raw.githubusercontent.com/google/metallb/v0.8.1/manifests/metallb.yaml
kubectl create -f srcs/metallb.yaml