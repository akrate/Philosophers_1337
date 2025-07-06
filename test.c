// #include "philosophers.h"

// typedef struct s_info
// {
//     int philo; //nbr fhilo
//     int die; // w9t ila mklach fih khaso imout 
//     int eating; // w9t li khas ib9a iyakol fih
//     int sleeping; // w9t li khaso in3s fih
//     int nbr_eat; // nbr ta3 chehal mn mra khaso iyakol
//     int overflow; // hada drto 3la hsab overflow fi atoi
//     unsigned long start_time; // BACH N9DR NHSB W9T.
//     int dead; // FALG BACH N3RF BLI CHI PHILO MAT.
//     pthread_mutex_t lock_print; //BACH NPRINTI BLAMA IW93 LIYA MOCHKIL.
//     pthread_mutex_t lock_dead; // BACH MCHOF WACH MAT LIYA CHI PHILO BLAMA IW93 CHIMOCHKIL.
// } t_info;

// typedef struct s_philo
// {
//     int id; // hada id ta3 filo
//     unsigned long last_eat; // w9t ta3 akhir mra kla fiha
//     int nbr_eating;
//     t_info *info;
//     pthread_t philo;
//     pthread_mutex_t left_fork; 
//     pthread_mutex_t *right_fork;
    
// } t_philo;

// int main(int ac,char **av)
// {
//     if (ac < 5 || ac > 6)
//         return (write (2,"error\n",6),1);
//     t_info info;
//     t_philo *philosophers;
//     pthread_t monitor;
//     int i;

//     i = 0;
    
//     info = init_struct(ac,av);
//     if (info.overflow == 1)
//         return (1);
//     philosophers = init_data(info);
//     if (philosophers == NULL)
//         return (1);
//     init_info_and_link_philos(philosophers,&info);
//     while (i < info.philo)
//     {
//         pthread_create(&philosophers[i].philo,NULL,&routine_philo,&philosophers[i]);
//         i++;
//     }
//     pthread_create(&monitor,NULL,&monitor_thread,philosophers);
//     i = 0;
//     while (i < info.philo)
//     {
//         pthread_join(philosophers[i].philo,NULL);
//         i++;
//     }
//     return (0);
// }

// t_info init_struct(int ac,char **av)
// {
//     t_info info;

//     info.philo = ft_atoi_use(av[1]); // chehal mn philo 3ndi
//     info.die = ft_atoi_use(av[2]); // w9t li radi imot fih ila mklach
//     info.eating = ft_atoi_use(av[3]); // w9t li khaso iyakol fih
//     info.sleeping = ft_atoi_use(av[4]);// w9t li aykhso isleepi fih
//     info.dead = 0;
//     if (ac == 6)
//         info.nbr_eat = ft_atoi_use(av[5]);// chehal mn mra ayakol 3ad imot
//     else
//         info.nbr_eat = -1;
//     if (check_int(ac,info) == 1)
//         info.overflow = 1;
//     else 
//         info.overflow = 0;
//     return (info);
// }

// t_philo *init_data(t_info info)
// {
//     t_philo *philo;
//     int i;

//     philo = malloc(sizeof(t_philo) * info.philo);
//     if (philo ==  NULL)
//         return (NULL);
//     i = 0;
//     while(i < info.philo)
//     {
//         philo[i].id = i + 1;
//         pthread_mutex_init(&philo[i].left_fork,NULL);
//         i++;
//     }
//     i = 0;
//     while (i < info.philo)
//     {
//         philo[i].right_fork = &philo[(i + 1) % info.philo].left_fork;
//         i++;
//     }
//     return (philo);
// }

// void init_info_and_link_philos(t_philo *philo,t_info *info)
// {
//     int i;
    
//     i = 0;
//     pthread_mutex_init(&info->lock_dead,NULL);
//     pthread_mutex_init(&info->lock_print,NULL);
//     info->start_time = get_time_ms();
//     while (i < info->philo)
//     {
//         philo[i].info = info;
//         philo[i].nbr_eating = 0;
//         i++;
//     }
// }
// void *routine_philo(void *arg)
// {
//     t_philo *philo;
    
//     philo = (t_philo *)arg;
//     philo->last_eat = get_time_ms();
    
//     if (philo->id % 2 == 0)
//         usleep(500);
//     while (1)
//     {
//         if (philo->id % 2 != 0)
//         {
//             pthread_mutex_lock(&philo->left_fork);
//                 print_status(philo,"has taken a fork\n");
//             pthread_mutex_lock(philo->right_fork);
//                 print_status(philo,"has taken a fork\n");
//         }
//         else
//         {
//             pthread_mutex_lock(philo->right_fork);
//                 print_status(philo,"has taken a fork\n");
//             pthread_mutex_lock(&philo->left_fork);
//                 print_status(philo,"has taken a fork\n");
//         }
//             print_status(philo,"is eating\n");
//             ft_usleep(philo->info->eating);
//             philo->nbr_eating++;
//         pthread_mutex_unlock(&philo->left_fork);
//         pthread_mutex_unlock(philo->right_fork);
//         print_status(philo,"is sleeping\n");
//         ft_usleep(philo->info->sleeping);
//         print_status(philo,"is thinking\n");
//     }
// }

// void *monitor_thread(void *arg)
// {
//     t_philo *philo;
//     int i;

//     philo = (t_philo *)arg;
//     while (1)
//     {
//         i = 0;
//         if (philo->info->nbr_eat != -1)
//         {
//             while (i < philo->info->philo)
//             {
//                 if (philo[i].nbr_eating == philo->info->nbr_eat)
//                     return (philo[i].info->dead = 1,NULL);
//                 i++;
//             }
//             i = 0;
//         }
//         while (i < philo->info->philo)
//         {
//             if (get_time_ms() - philo[i].last_eat > philo->info->die)
//             {
//                 print_status(&philo[i],"died");
//                 return (philo[i].info->dead = 1,NULL);
//             }
//             i++;
//         }
//     }
//     return (NULL);
// }
// long	ft_atoi_use(char *str)
// {
// 	int	i;
// 	long	result;

//     if (checking_nbr(str) == 1)
//         return (-1);
// 	i = 0;
// 	result = 0;
// 	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
// 		i++;
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result *= 10;
// 		result += str[i] - '0';
//         if (result > 2147483647)
//         {
//             printf("nbr is long\n");
//             return (-1);
//         }
// 		i++;
// 	}
// 	return (result);
// }
// int checking_nbr(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//     {
//         if (str[i] < '0' || str[i] > '9')
//         {
//             write (2,"this number is not correct\n",27);
//             return (1);
//         }
//         i++;
//     }
//     return (0);
// }
// unsigned long get_time_ms()
// {
//     struct timeval tv;
    
//     gettimeofday(&tv,NULL);
//     return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)); // had return ky 3tina w9t b millisecond ==> kt3ni parti mn taniya.
// }

// void print_status(t_philo *philo,char *str)
// {
//     pthread_mutex_lock(&philo->info->lock_print);
//         printf("%ld %d %s\n",get_time_ms() - philo->info->start_time,philo->id,str);
//     pthread_mutex_unlock(&philo->info->lock_print);
// }
// void ft_usleep(unsigned long time)
// {
//     unsigned long start;
    
//     start = get_time_ms();
//     while(get_time_ms() - start < time)
//     {
//         usleep(100);
//     }
// }
// int check_int(int ac,t_info test)
// {
//     if (test.eating == -1)
//         return (1);
//     if (test.philo == -1)
//         return (1);
//     if (test.sleeping == -1)
//         return (1);
//     if (test.die == -1)
//         return (1);
//     if (ac == 6)
//     {
//         if (test.nbr_eat == -1)
//             return (1);
//     }
//     return (0);
// }