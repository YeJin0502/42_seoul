clear
# echo "=> Delete minikube."
# minikube delete

echo "=> Start minikube."
export MINIKUBE_HOME=~/goinfre
# minikube config set vm-driver virtualbox
# minikube start --extra-config=apiserver.service-node-port-range=1-35000
# minikube start --vm-driver=virtualbox
minikube start --vm-driver=virtualbox --extra-config=apiserver.service-node-port-range=1-35000
# vm-driver? driver? 어떤걸 선택해야하지?
eval $(minikube docker-env)

echo "=> Install MetalLB"
# kubectl apply -f https://raw.githubusercontent.com/google/metallb/v0.8.1/manifests/metallb.yaml
minikube addons enable metallb

# echo "=> Activate ARP."
# kubectl get configmap kube-proxy -n kube-system -o yaml | sed -e "s/strictARP: false/strictARP: true/" | kubectl diff -f - -n kube-system
# kubectl get configmap kube-proxy -n kube-system -o yaml | sed -e "s/strictARP: false/strictARP: true/" | kubectl apply -f - -n kube-system

# echo "=> Install metalLB."
# kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
# kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
# # kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
# kubectl apply -f srcs/metallb.yaml

# echo "=> Setting nginx."
# cd src/nginx
# make keys
# kubectl create secret tls nginxsecret --key /Users/gmoon/Desktop/nginx.key --cert /Users/gmoon/Desktop/nginx.crt
# kubectl create configmap nginxconfigmap --from-file=default.conf
# cd ../..

echo "=> Build images."
docker build -t nginx-image srcs/nginx

echo "=> apply yaml."
kubectl apply -f srcs/nginx.yaml