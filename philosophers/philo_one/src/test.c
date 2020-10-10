#include <stdio.h>
#include <pthread.h>

/*
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
        // printf("1초마다 출력! %ld\n",
        //     (now_time.tv_sec - start_time.tv_sec) +
        //     (now_time.tv_usec - start_time.tv_usec) / 1000000);
        printf("1초마다 출력! %ld\n",
            (now_time.tv_sec - start_time.tv_sec)); // 위와 마찬가지로 1초마다 나온다.
        usleep(1000 * 1000);
    }
}

int main()
{
    struct timeval now_time;

    while (1)
    {
        gettimeofday(&now_time, NULL);
        printf("%ld:%ld\n", now_time.tv_sec, now_time.tv_usec); // 마이크로초가 뭘 의미하는거지?
        usleep(1000 * 1000);
    }
}
*/

/*
void* thread_fuction(void* data)
{
    *(int*)data += 10;

    printf("자식 스레드: %d\n", *(int*)data);
    return (NULL);
}

int main()
{
    pthread_t threadID;
    int data = 1;

    pthread_create(&threadID, NULL, thread_fuction, (void*)&data);
    printf("스레드 생성.\n");

    printf("메인 스레드가 자식 스레드를 기다립니다.\n");
    pthread_join(threadID, NULL);

    printf("메인 스레드가 자식 스레드를 기다리는 것을 마쳤습니다.\n");
    printf("메인 스레드: %d\n", data);
    return (0);
}
*/

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
    pthread_join(threadID, &return_value);

    printf("메인 스레드가 자식 스레드를 기다리는 것을 마쳤습니다.\n");
    printf("return_value: %d\n", *(int*)return_value);
    return (0);
}
