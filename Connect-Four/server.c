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
#include <fcntl.h>

/* portul folosit */
#define PORT 2024
#define MAX_GAME_HOSTED 40
#define RED_PLAYER  2
#define YELLOW_PLAYER  3
#define MAX_ROW 7 
#define MAX_COL 8
#define PLAYERS_DRAW 5

/* codul de eroare returnat de anumite apeluri */
extern int errno;

typedef struct thData{
	int idThread; //id-ul thread-ului tinut in evidenta de acest program
	int player_one;
  int player_two; //descriptorul intors de accept
  int first_player_color;
}thData;



static void *treat(void *); /* functia executata de fiecare thread ce realizeaza comunicarea cu clientii */

int game_function();

int check_file_descriptor(int file_descriptor)
{
  return fcntl(file_descriptor , F_GETFD) == -1 || errno == EBADF;
}


int check_win_condition(char playing_matrix[MAX_ROW][MAX_COL]) { 
     for(int i = 0 ; i < MAX_ROW ; ++i){
       for(int j = 0 ; j < MAX_COL; ++j){
         printf("%i" , (int) playing_matrix[i][j]);
       }
       printf("\n");
     }
     for (int i = 1; i < MAX_ROW; ++i) {
     for (int j = 1; j < MAX_COL; ++j) {
     char sum_line = 1, sum_col = 1, sum_dig = 1, sum_dig_rev = 1;
     if (playing_matrix[i][j] !=  0) {
     for (int t = 1; t < 4; ++t) {
     if (j + t < MAX_COL) {
          if (playing_matrix[i][j + t] == playing_matrix[i][j])
                sum_line++; 
     }
     if (i + t < MAX_ROW) {
         if (playing_matrix[i + t][j] == playing_matrix[i][j])
             sum_col++;
     }
     if (i + t < MAX_ROW && j - t > 0) {
         if (playing_matrix[i + t][j - t] == playing_matrix[i][j])
              sum_dig++;
     }
     if (i + t < MAX_ROW && j + t < MAX_ROW) {
          if (playing_matrix[i + t][j + t] == playing_matrix[i][j])
                          sum_dig_rev++;
     }
     }
      if (sum_line >= 4 || sum_col >= 4 || sum_dig >= 4 || sum_dig_rev >= 4) 
              return playing_matrix[i][j];
     }
     }
      
}
        return 0;
}

int main ()
{
  struct sockaddr_in server;	// structura folosita de server
  struct sockaddr_in player_one;	
  struct sockaddr_in player_two;	
  int number_of_players = 0;
  signal(SIGPIPE, SIG_IGN);
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

      ++number_of_players;
  }
  if ( (fd_player_two = accept (sd, (struct sockaddr *) &player_two, &length_player_two)) < 0)
	{
	  perror ("[server]Eroare la accept().\n");
	  continue;
	}
  else{

      ++number_of_players;
  }
  /* s-a realizat conexiunea, se astepta mesajul */
    
	int idThread; //id-ul threadului
	int cl; //descriptorul intors de accept


  if(number_of_players == 2){
    printf("%i\n" , check_file_descriptor(fd_player_one));
    printf("%i\n" , check_file_descriptor(fd_player_two));
    fflush(stdout);
    td=(struct thData*)malloc(sizeof(struct thData));	
	  td->idThread=i++;
	  td->player_one = fd_player_one;
    td->player_two = fd_player_two;
    number_of_players = 0;
	  pthread_create(&th[i], NULL, &treat, td);	   
  }	
	}//while    
};				


char* integer_to_ascii(int p){
  char t[1];
  char* x[2][2];
  *t = p + 48;
  x[0][0] = t;
  printf("%s" , x[0][0]);

}
static void *treat(void * arg)
{		

    int player_one_points = 0, player_two_points = 0;
    int result;
    char play_again_player_one = 1, play_again_player_two = 1;
    pthread_detach(pthread_self());
    struct thData * game_info = (struct thData *) arg;
    integer_to_ascii(9);
    while(play_again_player_one && play_again_player_two){
       printf("\nPLAYING AGAIN\t%i\n" , game_info->idThread);
        if(result = game_function(arg , &player_one_points , &player_two_points) == -1){
            break;
        }
        read(game_info->player_one , &play_again_player_one , 1);
        printf("PRIMU JOACA DIN NOU CU : %i" , player_one_points);
        read(game_info->player_two , &play_again_player_two , 1);   
        printf("AL DOILEA JOACA DIN NOU CU : %i" , player_two_points);
           
    }
    close(game_info->player_one);
    close(game_info->player_two);
    return(NULL);
   
  		
};



int game_function(void * arg , int * player_one_score , int * player_two_score)
{
   char set_color = rand() % 80;
    char game_matrix[MAX_ROW][MAX_COL];
    char win_condition = 0, random_exit = 0;
    char turn_number = rand() % 80 ; 
    turn_number = turn_number % 2;
		struct thData* game_info;
    memset(game_matrix , 0 , sizeof(game_matrix));
		game_info = (struct thData*) arg;
    char first_or_second = set_color % 2;
    write(game_info->player_one , &first_or_second , 1);
    first_or_second = (set_color + 1) % 2;
    write(game_info->player_one , &first_or_second , 1);
    first_or_second = (set_color + 1) % 2;
    write(game_info->player_two , &first_or_second , 1);
    first_or_second = set_color % 2;
    write(game_info->player_two , &first_or_second , 1);
    game_info->first_player_color = set_color % 2;
    while(!win_condition  && !random_exit && turn_number != 42){
          char a[20];
          fflush(stdout);
          char player_turn = turn_number % 2;
          memset(a , 0 , sizeof(a));
          if(write(game_info->player_one , &player_turn , 1) == -1){
            random_exit = 1;
            if(game_info->first_player_color != 0){
                win_condition = YELLOW_PLAYER;
            }
            else{
                win_condition = RED_PLAYER;
            }
            break;
          }
          write(game_info->player_one , &turn_number , 1);
          player_turn = (turn_number + 1) % 2;
          if(write(game_info->player_two , &player_turn , 1) == -1){
            random_exit = 1;
            if(game_info->first_player_color == 0){
                win_condition = YELLOW_PLAYER;
            }
            else{
                win_condition = RED_PLAYER;
            }
            break;
          }
          write(game_info->player_two , &turn_number , 1);
          if(turn_number % 2 == 1){
              read(game_info->player_one , a , sizeof(a));
              int i;
              int x = -1 , y =  -1;
              x = a[1] - 48;
              y = a[3] - 48;
              for(int i = x; i < 6; ++i){
                  if(game_matrix[i+1][y] == 0){
                    ++x;
                  }
                  else  
                    break;
              }
              if(game_info->first_player_color == 0){
                  game_matrix[x][y] = YELLOW_PLAYER; 
              }
              else{
                  game_matrix[x][y] = RED_PLAYER;
              } 
              a[1] = x + 48;
              win_condition = check_win_condition(game_matrix);
              printf("\nWIN CONDITION : %i" , win_condition);  
              write(game_info->player_two , a , sizeof(a));
              write(game_info->player_one , a , sizeof(a));
          }
          else{
              read(game_info->player_two , a , sizeof(a));
              int i;
              int x = -1 , y = -1;
              x = a[1] - 48;
              y = a[3] - 48;
              for(int i = x ; i < 6; ++i){
                  if(game_matrix[i + 1][y] == 0){
                    ++x;
                  }
                  else {
                    break;
                  }
              }
              if(game_info->first_player_color != 0){
                  game_matrix[x][y] = YELLOW_PLAYER; 
              }
              else{
                  game_matrix[x][y] = RED_PLAYER;
              }   
              a[1] = x + 48;
              win_condition = check_win_condition(game_matrix);
              printf("\nWIN CONDITION : %i" , win_condition);
              write(game_info->player_two , a , sizeof(a)); 
              write(game_info->player_one , a , sizeof(a));          
          }
          ++turn_number;
    }
    if(turn_number == 42){
      win_condition = PLAYERS_DRAW; 
    }
    printf("\n");
    printf("%i" ,(int)write(game_info->player_two , &win_condition , sizeof(win_condition)));
    printf("%i" , (int)write(game_info->player_one , &win_condition , sizeof(win_condition)));
    fflush(stdout);
    if(game_info->first_player_color == 0 && win_condition == RED_PLAYER){
          ++(*player_one_score);
    }
    else{
          ++(*player_two_score);
    } 
    if(random_exit == 1){
      return -1;
    }
}