#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// pthread_mutex_t lock;
typedef struct s_test
{
    int id;
    int i;
    pthread_t pt;
    pthread_mutex_t lock_test;
    pthread_mutex_t *right;
} t_test;

void *ic(void *i)
{
    t_test *b = (t_test *)i;
    int e = 0;
    // if (b->id % 2 == 0)
    //     usleep(10000);
    pthread_mutex_lock(&b->lock_test);
    pthread_mutex_lock(b->right);
   while (e < 5000000)
   {
        e++;
        b->i++;    
    }
    printf("test nb =>%d val == %d\n",b->id,b->i);
    pthread_mutex_unlock(&b->lock_test);
    pthread_mutex_unlock(b->right);

   return (NULL);
}
int main()
{
    t_test test1,test2,test3;
    test1.id = 1;
    test2.id = 2;
    test3.id = 3;

    test1.i = 0;
    test2.i = 0;
    test3.i = 0;

    pthread_mutex_init(&test1.lock_test,NULL);
    pthread_mutex_init(&test2.lock_test,NULL);
    pthread_mutex_init(&test3.lock_test,NULL);

    test1.right = &test2.lock_test;
    test2.right = &test3.lock_test;
    test3.right = &test1.lock_test;

    pthread_create(&test1.pt,NULL,ic,&test1);
    pthread_create(&test2.pt,NULL,ic,&test1);
    pthread_create(&test3.pt,NULL,ic,&test1);


    pthread_join(test1.pt,NULL);
    pthread_join(test2.pt,NULL);
    pthread_join(test3.pt,NULL);


    // printf("%d",test1.i);
    // printf("%d",test1.i);

}