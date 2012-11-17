#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define MAX  424967295
#define THREADS 5

int set_not_prime(unsigned int  n);
int is_prime(unsigned int n);
void *thread_code(void * id);
int print_primes();
void *progress_bar(void *id);
int draw_progress_bar(int len, double percent,int length);
unsigned int next_number();

unsigned int next_num = 2;
int number_of_threads = THREADS;
unsigned int number_checking[THREADS];
char *prime = new char[MAX/8+1];
unsigned int max_number = MAX;
/* mutex will only allow one thread to next its checking number */
pthread_mutex_t next_number_mutex;
/* mutex will prevent overwriting bytes */
pthread_mutex_t *prime_mutex = new pthread_mutex_t[MAX/64+1];

int main(int argc, char const *argv[]){
	double elapTime;
  clock_t beginT, endT;

	pthread_t threads[number_of_threads];
	pthread_t progress_thread;
  pthread_attr_t attr;
	
	/* get start time */
	beginT = clock();
	
	/* Set 0 and 1 as not prime of course you can tell by function name */
	set_not_prime(0);
	set_not_prime(1);

	/* pre-set array so next_number() will work */
	for(int i = 0; i < number_of_threads; i++){
		number_checking[i] = 2;
	}
	
	/* Set prime numbers for threads to start */
	for(int i = 1; i < number_of_threads; i++){
		number_checking[i] = next_number();
	}
	
	/* Set up mutexs */
	pthread_mutex_init(&next_number_mutex, NULL);
	for (int i = 0; i < MAX/64+1; i++ ){
		pthread_mutex_init(&prime_mutex[i], NULL);
	}

	/* setup attr for pthreads */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	for (long i = 0; i < number_of_threads; i++){
		pthread_create(&threads[i], &attr, thread_code, (void *)i);
	}
	
	/* I got bored and want to print a progess bar */
	//pthread_create(&progress_thread, &attr, progress_bar, (void *)0);

	/* join all threads back together*/
	for (int i=0; i<number_of_threads; i++) {
		pthread_join(threads[i], NULL);
	}
	//pthread_join(progress_thread, NULL);

	/* Clean up pthreads */
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&next_number_mutex);
	for (int i = 0; i < MAX/64+1; i++ ){
		pthread_mutex_destroy(&prime_mutex[i]);
	}
	
	/* end clock */
	endT = clock();

	/* Print time and number of threads */
	elapTime = ((double)(endT - beginT))/CLOCKS_PER_SEC/number_of_threads;
  std::cout << number_of_threads << ", " << elapTime << std::endl;

	/* prints primes duh */
	print_primes();

	/* free allocated data */
	free(prime);
	free(prime_mutex);

	return 0;
}

/* print primes
 * Note: only works after find all primes
 */
int print_primes(){
	std::cout << "start print" << std::endl;
	unsigned int i;
	long count = 0;
	for( i = 2; i < max_number; i++){
		if (is_prime(i) == 0){
			std::cout  << i << std::endl;
			count ++;
		}
	}
	std::cout << count << std::endl;
}


/* The code for thread that are finding primes */
void *thread_code(void *id){
	long thread_id = (long)id;
	unsigned long i;
	do{
		/* number_checking is a prime number */
		i = number_checking[thread_id];
		/* first multiple of prime number checking */
		i += number_checking[thread_id];
		while(i < max_number){
			/* set that number as not prime */
			set_not_prime(i);
			i += number_checking[thread_id];
		}
		
		/* request another number to check */
		pthread_mutex_lock(&next_number_mutex);
			number_checking[thread_id] = next_number();
		pthread_mutex_unlock(&next_number_mutex);
	} while (number_checking[thread_id] != 0);
	pthread_exit(NULL);
}

unsigned int next_number(){
	unsigned long i;
	/* next_num will only be 0 when there is not next number to check*/
	if(next_num == 0){
		return 0;
	}
	
	/* Find next prime and return it*/
	for(i = next_num; i < max_number; i++){
		/* this number has been check as not prime */
		if(is_prime(i) == 1){
			continue;
		}
		
		/* double check if the number is about to be checked by another thread */
		bool multiple = false;
		for(int j = 0; j < number_of_threads; j++){
			if (number_checking[j] == 0){
				break;
			}
			if(i%number_checking[j]==0){
				multiple = true;
				break;
			}
		}
		if(multiple){
			continue;
		}
		next_num = i+2;
		/* returns the next prime */
		return i;
	}
	/* no primes left */
	next_num = 0;
	return(0);
}

/* set n as not prime */
int set_not_prime(unsigned int  n){
	unsigned int index = n/8;
	/* lock 8 bytes for writing */
	pthread_mutex_lock(&prime_mutex[index/8]);
		prime[index] |= (1 << (n%8));
	pthread_mutex_unlock(&prime_mutex[index/8]);
	
	return(0);
}

/* check if n is a prime or not 
 * 1 is not prime 
 * 0 is prime
 */
int is_prime(unsigned int n){
	/* returns nth bit */
	return (prime[n/8] & (1 << (n%8))) >> (n%8);
}

/* progess bar stuff */
void *progress_bar(void *id){
	int length = -1;
	while(next_num != 0){
		length = draw_progress_bar(80,next_num*1.0/max_number,length);	
		sleep(1);
	}
	draw_progress_bar(80,1,-1);
	pthread_exit(NULL);
}

int draw_progress_bar(int len, double percent,int length){
	if(length == static_cast<int>(len*percent)){
		return length;
	}
	length = static_cast<int>(len*percent);
	std::cout << "\x1B[2K";
	std::cout << "\x1B[0E";
	std::string progress;
	for (int i = 0; i < len; i++ ){
		if (i < length){
			progress += "=";
		} else {
			progress += " ";
		}
	}
	std::cout << "[" << progress << "]" << static_cast<int>(100*percent) << "% " << next_num;
	flush(std::cout);
	return length;
}
