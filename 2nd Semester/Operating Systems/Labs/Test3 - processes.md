Scrieti un program in C care primeste un numar intreg pozitiv N de la linia de comanda. Programul va crea un lant de N procese, fiecare proces avand un singur copil (cu exceptia ultimului). Primul proces (parintele) citeste un sir de caractere de la tastatura, apoi il transmite copilului sau printr-un pipe. Fiecare proces primeste mesajul de la parintele sau, il modifica inlocuind aleator un caracter cu altul (caractere ASCII vizibile), si il transmite mai departe copilului. Ultimul proces transmite mesajul inapoi, prin lantul invers de pipe-uri, pana cand ajunge din nou la procesul initial. La final, parintele afiseaza mesajul final pe ecran. Programul nu trebuie sa aiba erori de compilare, warnings sau probleme de memorie de orice natura.

```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv){
	if(argc!=2) {
		printf("Provide n from command line.\n");
		exit(1);
	}
	int n=atoi(argv[1]);
	printf("Received n from command line: %d\n",n);
	if(n<=0) {
		printf("Please provide a positive integer\n");
		exit(1);
	}
	// declare pipes
	int p2c[2];
	int c2p[2];
	// parent_read and parent_write used to keep track of the hierarchy
	int parent_read=-1;
	int parent_write=-1;
	int level=0;//keep track   of the level
	for(int i=1; i<n; i++) { // create n processes
		if(pipe(p2c)<0){ // error at pipe
			perror("pipe");
			exit(1);
		}
		if(pipe(c2p)<0){
			perror("pipe");
			exit(1);
		}
		pid_t f=fork(); // each process has one child
		if(f<0) { // error at fork
			perror("fork");
			exit(1);
		}
		if(f>0){ // it's parent
			close(p2c[0]);
			close(c2p[1]);
			break;
		}
		if(f==0) { // child
			if(parent_read!=-1) // we don't use the read end
				close(parent_read);
			if(parent_write!=-1) // we don't use the write end
				close(parent_write);
			// close what we don't use
			close(p2c[1]);
			close(c2p[0]);
			//u[pdate what we use
			parent_read=p2c[0];
			parent_write=c2p[1];
			level=i; // update the level we're currently at.
		}
	}
		//randomize the position at which we'll change the character
		srand(time(NULL)^getpid());
		int len;
		char s[256];
		if(level==0) { // parent reads string
			printf("Give string: ");
	                scanf("%s",s);
        	        len=strlen(s);
			if(n==1) {// for the first process
				if(len>0) { // randomize the position
					int pos=rand()%len;
		                        char c=rand()%95+32;// ascii from 32-126
                		        s[pos]=c; // change that character
				}
				printf("Final string: %s\n",s);
				return 0;
			}
			write(p2c[1],&len,sizeof(int)); // parent writes to child
			write(p2c[1],s,len*sizeof(char));
			// new parent reads from last child
			read(c2p[0],&len,sizeof(int));
			read(c2p[0],s,len*sizeof(char));
			s[len]='\0';//terminate the string
			printf("Final string: %s\n",s);
			//close what we actually used.
			close(p2c[1]);
			close(c2p[0]);
			wait(0);
		}
		else {//middle
			read(parent_read,&len,sizeof(int));
			read(parent_read,s,len*sizeof(char));
			s[len]='\0'; // terminate the string (the one from if(len>) from the previous branch)
			if(len>0) {// string is not empty
				int pos=rand()%len; // randomize
                                char c=rand()%95+32;
                                s[pos]=c;
			}
			if(level==n-1) {//last process
				write(parent_write,&len,sizeof(int));
				write(parent_write,s,len*sizeof(char));
			}
			else {//middle
				write(p2c[1],&len,sizeof(int));
                		write(p2c[1],s,len*sizeof(char));
				read(c2p[0],&len,sizeof(int));
				read(c2p[0],s,len*sizeof(char));
				s[len]='\0';
				write(parent_write,&len,sizeof(int));
				write(parent_write,s,len*sizeof(char));
				close(p2c[1]);
				close(c2p[0]);
				wait(0);
			}
		close(parent_read);
		close(parent_write);
	}
	return 0;
}
```