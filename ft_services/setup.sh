minikube delete

export MINIKUBE_HOME=~/goinfre
minikube start --vm-driver=virtualbox
# vm-driver 설정을 안하면 docker로 실행되는 것 같은데, 어떤걸로 해야하는거지?

# extra-config는? 해야하는건가?
# minikube start --extra-config=apiserver.service-node-port-range=1-35000

# minikube dashboard
# minikube dashboard & 이랑 차이가 뭐지?

kubectl get configmap kube-proxy -n kube-system -o yaml | sed -e "s/strictARP: false/strictARP: true/" | kubectl diff -f - -n kube-system
kubectl get configmap kube-proxy -n kube-system -o yaml | sed -e "s/strictARP: false/strictARP: true/" | kubectl apply -f - -n kube-system

echo "metalLB manifest"
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
cd srcs/metallb
kubectl apply -f config.yaml

echo "fieldPath: status.hostTP"

echo "nginx directory"
cd ../nginx

echo "ssl create"
make keys

echo "nginx ssl secret create"
kubectl create secret tls nginxsecret --key /Users/gmoon/Desktop/nginx.key --cert /Users/gmoon/Desktop/nginx.crt

echo "nginx configmap create"
kubectl create configmap nginxconfigmap --from-file=default.conf

echo "nginx image build"
docker build -t gmoon
_nginx:1.0 .

echo "nginx deployment"
kubectl apply -f nginx.yaml


# echo "대쉬보드 설치"
# kubectl apply -f https://raw.githubusercontent.com/kubernetes/dashboard/v2.0.0/aio/deploy/recommended.yaml
# echo "대쉬보드 접근 토큰 생성"
# kubectl -n kubernetes-dashboard describe secret $(kubectl -n kubernetes-dashboard get secret | grep admin-user | awk '{print $1}')
# echo "인그레스 컨트롤러 설치"
# kubectl apply -f https://raw.githubusercontent.com/kubernetes/ingress-nginx/master/deploy/static/provider/cloud/deploy.yaml
# echo "nginx 디렉토리로 이동"
# cd srcs/nginx
# echo "ssl 생성"
# make keys
# echo "nginx ssl 시크릿 생성"
# kubectl create secret tls nginxsecret --key /tmp/nginx.key --cert /tmp/nginx.crt
# echo "nginx configmap 생성하기"
# kubectl create configmap nginxconfigmap --from-file=default.conf
# echo "nginx 이미지 빌드"
# docker build -t nakim_nginx:1.0 .
# echo "nginx 디플로이먼트 생성"
# kubectl apply -f nginx.yaml
# echo "srcs로 이동"
# cd ..
# echo "nginx 인그레스 생성"
# kubectl apply -f ingress.yaml