# 모든 어플리케이션을 설정하는 파일.

echo "대쉬보드 설치"
kubectl apply -f https://raw.githubusercontent.com/kubernetes/dashboard/v2.0.0/aio/deploy/recommended.yaml
echo "대쉬보드 접근 토큰 생성"
kubectl -n kubernetes-dashboard describe secret $(kubectl -n kubernetes-dashboard get secret | grep admin-user | awk '{print $1}')
echo "인그레스 컨트롤러 설치"
kubectl apply -f https://raw.githubusercontent.com/kubernetes/ingress-nginx/master/deploy/static/provider/cloud/deploy.yaml
echo "nginx 디렉토리로 이동"
cd srcs/nginx
echo "ssl 생성"
make keys
echo "nginx ssl 시크릿 생성"
kubectl create secret tls nginxsecret --key /tmp/nginx.key --cert /tmp/nginx.crt
echo "nginx configmap 생성하기"
kubectl create configmap nginxconfigmap --from-file=default.conf
echo "nginx 이미지 빌드"
docker build -t nakim_nginx:1.0 .
echo "nginx 디플로이먼트 생성"
kubectl apply -f nginx.yaml
echo "srcs로 이동"
cd ..
echo "nginx 인그레스 생성"
kubectl apply -f ingress.yaml