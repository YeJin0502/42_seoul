# ft_services

## 20.07.06 1일차
https://subicura.com/2019/05/19/kubernetes-basic-1.html

---

https://github.com/t0mm4rx/ft_services <br>

### 개요

#### 도커와 쿠버네티스란?
도커는 가벼운 가상머신을 실행할 수 있는 소프트웨어이다. dockerfile을 이용해서 컨테이너를 만들 수 있다. 컨테이너는 자체 메모리 공간과 스토리지가 있는 OS를 실행하는 가벼운 가상머신이다. 그러나 호스트 컴퓨터의 커널을 사용하는 점이 가상머신과 다르다. 컨테이너는 보다 빠르고 가볍다.

많은 컨테이너와 서비스가 필요한 큰 앱을 실행하는 경우, 여러 컨테이너를 관리하는 방법이 필요하다. 자동으로 충돌한 컨테이너를 다시 시작하고, 컨테이너 간 데이터를 공유하고, 일부는 외부에서 가져올 수 있거나 없게 해야 한다. 이러한 이유로 쿠버네티스를 사용한다.

쿠버네티스에는 다음이 존재한다:<br>
* deployment: 도커 이미지의 n개 인스턴스를 실행하고 관리하는 개체. 예를 들어, 10개의 아파치 서버를 실행하고 관리하는 deployment.
* service: deployment를 외부 또는 다른 컨테이너로 연결하는 개체. 예를 들어, 192.168.0.1을 10개의 아파치 서버에 연결하고 가장 적은 작업 부하를 가진 서버를 선택하는 것.
* pod: deployment의 실행중인 인스턴스. 따라서 셸을 실행할 수 있다. pod는 자체 IP와 메모리 공간을 지닌다.

위의 모든 개체들은 YAML 파일에 기술된다.

minikube는 (쿠버네티스를 실행하고 virtualbox와의 호환성을 보장하는) 가상 머신을 만드는 데 사용되는 소프트웨어이다. 많은 tool이 있는 것이 특징인데, 예를 들어 당신의 pod가 어떻게 돌아가고 있는지 보여주는 대쉬보드와 같은 도구가 있다.

#### 도커 기본 명령어
```
docker build -t <이미지명> <도커파일위치>
docker run -it <이미지명>
docker run -it debian:apache -p 80:80
docker images
docker ps
docker kill <컨테이너>
docker system prune # 사용하지 않는 이미지나 캐시 삭제
```

#### 쿠버네티스를 사용한 pod 관리
```
# YAML 파일로부터 pod 생성하기
kubectl create -f <YAML 파일>

# pod 삭제하기
kubectl delete deployment <deployment>
kubectl delete service <service>

# pod에서 셸 실행
kubectl get pods
kubectl exec -it <pod명> -- /bin/sh

# 내 컴퓨터에서 pod로 파일 복사, 혹은 반대
kubectl cp <pod명>:<파일> <to>
kubectl cp <from> <pod명>:<to>

# deployment 재실행
kubectl rollout restart deployment <deployment명>

# minikube 대쉬보드 실행
minikube dashboard

# 클러스터의 외부 IP 얻기
minikube ip

# minikube vm 리셋
minikube delete
```

#### 어떻게 쿠버네티스로 IP를 관리하는가
쿠버네티스는 모든 컨테이너들을 연결하는 네트워크를 만든다. 각 컨테이너에는 고유한 개인 IP 주소가 있다. 네트워크는 (minikube ip로 얻을 수 있는) 외부 IP가 있다. 