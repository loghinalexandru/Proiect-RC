/* servTCPConcTh2.c - Exemplu de server TCP concurent care deserveste clientii
   prin crearea unui thread pentru fiecare client.
   Asteapta un numar de la clienti si intoarce clientilor numarul incrementat.
	Intoarce corect identificatorul din program al thread-ului.
  
   
   Autor: Lenuta Alboaie  <adria@infoiasi.ro> (c)2009
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>

/* portul folosit */
#define PORT 2024
#define MAX_GAME_HOSTED 40
#define RED_PLAYER  2
#define YELLOW_PLAYER  3

/* codul de eroare returnat de anumite apeluri */
extern int errno;

typedef struct thData{
	int idThread; //id-ul thread-ului tinut in evidenta de acest program
	int player_one;
  int player_two; //descriptorul intors de accept
}thData;

static void *treat(void *); /* functia executata de fiecare thread ce realizeaza comunicarea cu clientii */
void raspunde(void *);

int main ()
{
  struct sockaddr_in server;	// structura folosita de server
  struct sockaddr_in player_one;	
  struct sockaddr_in player_two;	
  int number_of_players = 0;
  int nr;		//mesajul primit de trimis la client 
  int sd;		//descriptorul de socket 
  int pid;
  pthread_t th[100];    //Identificatorii thread-urilor care se vor crea
	int i=0;
  

  /* crearea unui socket */
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("[server]Eroare la socket().\n");
      return errno;
    }
  /* utilizarea optiunii SO_REUSEADDR */
  int on=1;
  setsockopt(sd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
  
  /* pregatirea structurilor de date */
  memset(&server , 0 , sizeof(server));
  memset(&player_one, 0 , sizeof(player_one));
  memset(&player_two, 0 , sizeof(player_two));
  

  /* umplem structura folosita de server */
  /* stabilirea familiei de socket-uri */
    server.sin_family = AF_INET;	
  /* acceptam orice adresa */
    server.sin_addr.s_addr = htonl (INADDR_ANY);
  /* utilizam un port utilizator */
    server.sin_port = htons (PORT);
  
  /* atasam socketul */
  if (bind (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)
    {
      perror ("[server]Eroare la bind().\n");
      return errno;
    }

  /* punem serverul sa asculte daca vin clienti sa se conecteze */
  if (listen (sd, 40) == -1)
    {
      perror ("[server]Eroare la listen().\n");
      return errno;
    }
  /* servim in mod concurent clientii...folosind thread-uri */
  while (1)
    {
      int fd_player_one;
      int fd_player_two;
      char set_color = rand() % 45 + 1;
      thData * td; //parametru functia executata de thread     
      int length_player_one = sizeof(player_one);
      int length_player_two = sizeof(player_two);
      

      printf ("[server]Asteptam la portul %d...\n",PORT);
      fflush (stdout);

	//client= malloc(sizeof(int));
      /* acceptam un client (stare blocanta pina la realizarea conexiunii) */
  
  if ( (fd_player_one = accept (sd, (struct sockaddr *) &player_one, &length_player_one)) < 0)
	{
	  perror ("[server]Eroare la accept().\n");
	  continue;
	}
  else{
    char first_or_second = set_color & 1;
    write(fd_player_one , &first_or_second , 1);
    first_or_second = set_color & 0;
    write(fd_player_one , &first_or_second , 1);
      ++number_of_players;
  }
  if ( (fd_player_two = accept (sd, (struct sockaddr *) &player_two, &length_player_two)) < 0)
	{
	  perror ("[server]Eroare la accept().\n");
	  continue;
	}
  else{
   char first_or_second = set_color & 0;
    write(fd_player_two , &first_or_second , 1);
    first_or_second = set_color & 1;
    write(fd_player_two , &first_or_second , 1);
      ++number_of_players;
  }
  /* s-a realizat conexiunea, se astepta mesajul */
    
	int idThread; //id-ul threadului
	int cl; //descriptorul intors de accept

	td=(struct thData*)malloc(sizeof(struct thData));	
	td->idThread=i++;
	td->player_one = fd_player_one;
  td->player_two = fd_player_two;
  if(number_of_players == 2){
    number_of_players = 0;
	  pthread_create(&th[i], NULL, &treat, td);	   
  }	
	}//while    
};				
static void *treat(void * arg)
{		
    char game_matrix[7][8];
    int win_condition = 0, random_exit = 0;
    int turn_number = 0;
		struct thData* game_info;
    memset(game_matrix , 0 , sizeof(game_matrix));
		game_info = (struct thData*) arg;
    while(!win_condition || !random_exit){
          char a[20];
          printf("%i\n" , turn_number);
          fflush(stdout);
          char player_turn = turn_number % 2;
          memset(a , 0 , sizeof(a));
          write(game_info->player_one , &player_turn , 1);
          player_turn = (turn_number + 1) % 2;
          write(game_info->player_two , &player_turn , 1);

          if(turn_number % 2 == 1){
              read(game_info->player_one , a , sizeof(a));
              int i;
              int x = -1 , y =  -1;
              x = a[1] - 48;
              y = a[3] - 48;
              printf("%i %i\n" ,x , y);
              for(int i = x; i <= 5; ++i){
                  if(game_matrix[i+1][y] == 0){
                    ++x;
                  }
                  else
                    break;
              }
       
              game_matrix[x][y] = RED_PLAYER;
              int j;
              for(int i = 1; i <= 6; ++i){
                  for(int j = 1 ; j <= 7 ;++j){
                    printf("%i" , (int) game_matrix[i][j]);
                  }
                  printf("\n");
              } 
              printf("%s\n" , a); 
              a[1] = x + 48;
              printf("%s\n" , a);     
              fflush(stdout);
              write(game_info->player_two , a , sizeof(a));
              write(game_info->player_one , a , sizeof(a));
            
          }
          else{
            read(game_info->player_two , a , sizeof(a));
            int i;
              int x = -1 , y =  -1;
              x = a[1] - 48;
              y = a[3] - 48;
              printf("%i %i\n" ,x , y);
              for(int i = x ; i < 6; ++i){
                  if(game_matrix[i + 1][y] == 0){
                    ++x;
                  }
                  else {
                    break;
                  }
              }
              game_matrix[x][y] = YELLOW_PLAYER;
              int j;
              for(int i = 1; i <= 6; ++i){
                  for(int j = 1 ; j <= 7 ;++j){
                    printf("%i" , (int) game_matrix[i][j]);
                  }
                  printf("\n");
              }              
              printf("%s\n" , a);
              a[1] = x + 48;
              printf("%s\n" , a);     
              fflush(stdout);
              write(game_info->player_one , a , sizeof(a));
              write(game_info->player_two , a , sizeof(a));              
                   
          }
          ++turn_number;
    }
    close(game_info->player_one);
    close(game_info->player_two);
		return(NULL);	
  		
};

