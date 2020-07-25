clear

export MINIKUBE_HOME=~/goinfre
minikube start --vm-driver=virtualbox --extra-config=apiserver.service-node-port-range=1-35000

# export ip=$(minikube ip)