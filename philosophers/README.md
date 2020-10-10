# philosophers

### 식사하는 철학자
* https://namu.wiki/w/%EC%8B%9D%EC%82%AC%ED%95%98%EB%8A%94%20%EC%B2%A0%ED%95%99%EC%9E%90%20%EB%AC%B8%EC%A0%9C
* https://www.hanbit.co.kr/media/channel/view.html?cms_code=CMS2554000338&cate_cd=001
* https://github.com/tyrue/3th_Operating-System
* https://simsimjae.tistory.com/72
* https://m.blog.naver.com/hirit808/221788147057
* https://blog.naver.com/hirit808/221790851401
* https://has3ong.github.io/dining-philosopher/

### 프로세스와 스레드
* https://gmlwjd9405.github.io/2018/09/14/process-vs-thread.html
* https://brunch.co.kr/@kd4/3
* https://www.crocus.co.kr/481?category=204622
* https://www.crocus.co.kr/482?category=204622

### 뮤텍스와 세마포어
* https://velog.io/@conatuseus/OS-%EC%84%B8%EB%A7%88%ED%8F%AC%EC%96%B4%EC%99%80-%EB%AE%A4%ED%85%8D%EC%8A%A4
* https://jwprogramming.tistory.com/13
* https://worthpreading.tistory.com/90
* https://loginfo.dev/Semaphore-and-Mutex

### 스레드
* https://reakwon.tistory.com/56

### philo_one 함수

* 시간 관련 함수

    `void usleep(unsigned long useconds);`   
    마이크로초만큼 대기. 마이크로초는 1/1000000초. unistd.h 헤더에 선언.

    `int gettimeofday(struct timeval *tv, struct timezone *tz);`  
    현재 시간을 가져온다. 성공시 1, 실패시 -1 리턴. 두번째 인자에는 NULL을 넣으면 된다고 한다.

    ```c
    #include <sys/time.h> // gettimeofday()
    #include <unistd.h> // usleep()

    int main()
    {
        struct timeval start_time;
        struct timeval now_time;

        gettimeofday(&start_time, NULL);
        while (1)
        {
            gettimeofday(&now_time, NULL);
            /*
            printf("1초마다 출력! %ld\n",
                    (now_time.tv_sec - start_time.tv_sec) +
                    (now_time.tv_usec - start_time.tv_usec) / 1000000);
                // 1초마다 메세지가 출력된다.
            */
            printf("1초마다 출력! %ld\n",
                    (now_time.tv_sec - start_time.tv_sec));
                // 위와 마찬가지로 1초마다 나온다.
                // usec이 뭘 의미하는걸까?
            usleep(1000 * 1000);
        }
    }
    ```

* 스레드 함수

    * `int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);`  
    새로운 스레드를 생성한다.  

    * `int pthread_join(pthread_t thread, void **retval);`  
    다른 스레드가 종료되는걸 기다린다.  
    thread는 스레드, retval은 스레드의 리턴값을 받을 곳.
    메인 스레드가 종료되면 자식 스레드까지 종료되므로, 자식 스레드가 수행되기 전에 종료될 수 있다. 따라서 이 함수를 사용해서 자식 스레드의 종료까지 대기하는 것.

    > https://www.crocus.co.kr/484
    > https://bitsoul.tistory.com/160

    ```c
    #include <pthread.h> // 컴파일시 clang(gcc) -pthread 옵션을 붙여줘야.
     
    void* thread_fuction(void* data)
    {
        *(int*)data += 10; // 전달받은 포인터가 가르키는 값 변경.

        printf("자식 스레드: %d\n", *(*int)data);
        return (NULL);
    }

    int main()
    {
        pthread_t threadID;
        int data = 1;

        printf("스레드 생성\n");
        pthread_create(&threadID, NULL, thread_fuction, (void*)&data); // 성공하면 0 리턴.

        printf("메인 스레드가 자식 스레드를 기다립니다.\n");
        pthread_join(threadID, NULL); // "자식 스레드: 11" 출력
        // join 함수가 없으면 자식 스레드의 출력이 나오지 않는다.

        printf("메인 스레드가 자식 스레드를 기다리는 것을 마쳤습니다.\n");
        printf("메인 스레드: %d\n", data); // "메인 스레드: 11" 출력
        return (0);
    }
    ```

    ```c
    #include <pthread.h>

    void* thread_fuction(void* data)
    {
        *(int*)data += 10;
        printf("자식 스레드 실행\n");
        return (data);
    }

    int main()
    {
        pthread_t threadID;
        int data = 1;
        void* return_value;

        pthread_create(&threadID, NULL, thread_fuction, (void*)&data);
        printf("스레드 생성\n");

        printf("메인 스레드가 자식 스레드를 기다립니다.\n");
        pthread_join(threadID, &return_value); // &return_value에 리턴값 저장.

        printf("메인 스레드가 자식 스레드를 기다리는 것을 마쳤습니다.\n");
        printf("return_value: %d\n", *(int*)return_value); // "return_value: 11" 출력
        return (0);
    }
     ```

    * `int pthread_detach(pthread_t th);`  
    실행중인 스레드를 분리(detach) 상태로 만든다.

* `int pthread_mutex_init(pthread_mutex_t * mutex, const pthread_mutex_attr *attr);`  
뮤텍스 객체를 초기화한다.

* `int pthread_mutex_destroy(pthread_mutex_t *mutex);`  
뮤텍스를 파괴한다.

* `int pthread_mutex_lock(pthread_mutex_t *mutex);`  
뮤텍스 객체를 잠근다.

* `int pthread_mutex_unlock(pthread_mutex_t *mutex);`  
뮤텍스 객체의 락을 해제한다.