# ft_services

## 20.07.06 1일차

* https://subicura.com/2019/05/19/kubernetes-basic-1.html

* https://github.com/t0mm4rx/ft_services

    <details>
    <summary> 번역 </summary>

    ## 개요

    ### 도커와 쿠버네티스란?
    도커는 가벼운 가상머신을 실행할 수 있는 소프트웨어이다. dockerfile을 이용해서 컨테이너를 만들 수 있다. 컨테이너는 자체 메모리 공간과 스토리지가 있는 OS를 실행하는 가벼운 가상머신이다. 그러나 호스트 컴퓨터의 커널을 사용하는 점이 가상머신과 다르다. 컨테이너는 보다 빠르고 가볍다.

    많은 컨테이너와 서비스가 필요한 큰 앱을 실행하는 경우, 여러 컨테이너를 관리하는 방법이 필요하다. 자동으로 충돌한 컨테이너를 다시 시작하고, 컨테이너 간 데이터를 공유하고, 일부는 외부에서 가져올 수 있거나 없게 해야 한다. 이러한 이유로 쿠버네티스를 사용한다.

    쿠버네티스에는 다음이 존재한다:<br>
    * deployment: 도커 이미지의 n개 인스턴스를 실행하고 관리하는 개체. 예를 들어, 10개의 아파치 서버를 실행하고 관리하는 deployment.
    * service: deployment를 외부 또는 다른 컨테이너로 연결하는 개체. 예를 들어, 192.168.0.1을 10개의 아파치 서버에 연결하고 가장 적은 작업 부하를 가진 서버를 선택하는 것.
    * pod: deployment의 실행중인 인스턴스. 따라서 셸을 실행할 수 있다. pod는 자체 IP와 메모리 공간을 지닌다.

    위의 모든 개체들은 YAML 파일에 기술된다.

    minikube는 (쿠버네티스를 실행하고 virtualbox와의 호환성을 보장하는) 가상 머신을 만드는 데 사용되는 소프트웨어이다. 많은 tool이 있는 것이 특징인데, 예를 들어 당신의 pod가 어떻게 돌아가고 있는지 보여주는 대쉬보드와 같은 도구가 있다.

    ### 도커 기본 명령어
    ```
    docker build -t <이미지명> <도커파일위치>
    docker run -it <이미지명>
    docker run -it debian:apache -p 80:80
    docker images
    docker ps
    docker kill <컨테이너>
    docker system prune # 사용하지 않는 이미지나 캐시 삭제
    ```

    ### 쿠버네티스를 사용한 pod 관리
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

    ### 쿠버네티스로 IP를 관리하는 법
    쿠버네티스는 모든 컨테이너들을 연결하는 네트워크를 만든다. 각 컨테이너에는 고유한 개인 IP 주소가 있다. 네트워크는 (minikube ip로 얻을 수 있는) 외부 IP가 있다. 때로는 당신은 컨테이너를 다른 컨테이너와 연결하고 싶을 수 있다. 예를 들어, 당신은 컨테이너 안에 다른 컨테이너의 데이터베이스를 필요로 하는 웹사이트를 가지고 있다고 하자. 이럴 때엔 데이터베이스 컨테이너에 쉽게 접근할 수 있는 service를 만들어야 할 것이다.

    쿠버네티스 네트워크에서는 service에 IP가 아닌 서비스명으로 접근할 수 있다. 예를 들어, MySQL 컨테이너와 연결된 mysql 서비스가 있다. 이 컨테이너를 Nginx 컨테이너에서 접근하려면 다음과 같이 할 수 있다:

    ```
    mysql <database> -u <user> -p -h mysql
    mysql <database> -u <user> -p -h 127.0.0.10
    ```

    다른 예로, "test"라는 서비스와 포트 1000으로 호스트된 웹페이지가 있다고 하자. minikube ip는 192.168.0.1이다.
    ```
    # 컨테이너에서 웹페이지에 접근
    curl http://test:1000
    # 외부에서 웹페이지에 접근
    curl http://192.168.0.1:1000
    ```

    ### minikube와 도커 연결하기
    minikube는 도커 이미지를 실행할 특정 VM을 VirtualBox에 만든다. 당신은 당신의 셸과 minikube를 연결해야 한다. 다음 명령어를 통해 수행할 수 있다:
    ```
    eval $(minikube docker-env)
    ```
    다음을 통해 실행되고 있는지 테스트해볼 수 있다:
    ```
    docker images
    ```
    당신은 현재 환경에 연결된 모든 이미지를 확인할 수 있다.

    기본적으로 쿠버네티스 deployment는 온라인 도커 이미지를 찾지만, 우리는 사용자의 로컬 이미지를 로드하고자 한다. 당신은 컨테이너 객체에 "imagePullPolicy:Never"을 추가하여 이것을 수행할 수 있다.

    ## 컨테이너들

    ### Nginx
    ### FTPs
    ### Wordpress
    ### PHPMyAdmin
    ### Grafana

    </details>

## 20.07.15 (수) 2일차

\#ft_services

* https://github.com/woolimi/ft_services

* https://www.notion.so/ft_service-85d6cd8b023043f08ed0f5e1f04848cf

* https://github.com/ClemaX/ft_services

\#쿠버네티스
* https://github.com/kubernetes/examples/tree/master/staging/https-nginx/

* https://kubernetes.io/ko/docs/tasks/tools/install-minikube/
: `brew install minikube`

* https://judo0179.tistory.com/66?category=349244
: 쿠버네티스 기본 명령어

\#minikube

* https://judo0179.tistory.com/70
: #`the connection to the server localhost 8080 was refused minikube` 기본적인 내용이 잘 나와있다.

* https://aidanbae.github.io/code/devops/k8s/start/

* https://m.blog.naver.com/PostView.nhn?blogId=sharplee7&logNo=221737855770&categoryNo=0&proxyReferer=https:%2F%2Fwww.google.com%2F

* https://medium.com/humanscape-tech/kubernetes-%EB%8F%84%EC%9E%85-%EC%A0%84-minikube-%EC%82%AC%EC%9A%A9%EA%B8%B0-2eb2b6d8e444

* https://medium.com/@cratios48/minikube-%EC%84%A4%EC%B9%98-%EB%B0%8F-%ED%99%9C%EC%9A%A9-4a63ddbc7fcb

* https://bum752.github.io/posts/minikube%EB%A5%BC-%EC%9D%B4%EC%9A%A9%ED%95%B4-%EB%A1%9C%EC%BB%AC-%EC%BF%A0%EB%B2%84%EB%84%A4%ED%8B%B0%EC%8A%A4-%ED%81%B4%EB%9F%AC%EC%8A%A4%ED%84%B0-%EA%B5%AC%EC%84%B1%ED%95%98%EA%B8%B0/