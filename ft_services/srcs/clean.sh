echo "metalLB manifest delete"
kubectl delete -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml

echo "nginx directory"
cd ../nginx

echo "ssl delete"
make clean

echo "nginx ssl secret delete"
kubectl delete secret nginxsecret

echo "nginx configmap create"
kubectl delete configmap nginxconfigmap

echo "nginx deployment delete"
kubectl delete -f nginx.yaml

sleep 5

echo "nginx image delete"
docker rmi gmoon_nginx:1.0