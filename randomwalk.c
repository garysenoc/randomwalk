#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	
	char pos[10][10];
	char start = 'A';
	int i,j,letter,x,y,move;
	
	srand(time(NULL));
	
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			pos[i][j] = '.';
	
	x = rand() % 10;
	y = rand() % 10;
	
	pos[x][y] = start++;
		
	while(start <= 'Z'){
		move = rand() % 4;
		if( move == 0 && pos[x+1][y] == '.'&& x < 9){
			x+=1;
			pos[x][y] = start++;
		}
		else if( move == 1 && pos[x][y+1] == '.'&& y < 9){
			y+=1;
			pos[x][y] = start++;
		}
		else if(  move == 2 && pos[x-1][y] == '.'&& x >0){
			x-=1;
			pos[x][y] = start++;
		}
		else if( move == 3 && pos[x][y-1] == '.'&& y >0){
			y-=1;
			pos[x][y] = start++;
		}
		if((y==0 && x==0 && pos[x+1][y] != '.' && pos[x][y+1] != '.' ) ||(y==0 && x==9 && pos[x-1][y]  != '.' && pos[x][y+1] != '.' )||(x==0 && y==9 && pos[x+1][y]  != '.' &&pos[x][y-1]  != '.' )||(x==9 && y==9 && pos[x-1][y]  != '.' && pos[x][y-1] != '.' )||
		(x>0 && x<9 && y==0 && pos[x-1][y] != '.'  && pos[x+1][y]  != '.' && pos[x][y+1] != '.' )||(x>0 && x<9 && y==9 && pos[x-1][y] != '.' &&pos[x+1][y] != '.' &&pos[x][y-1] != '.' )||
		(x==0 && y>0 && y<9 && pos[x+1][y] != '.'  && pos[x][y+1] != '.'  && pos[x][y-1] != '.' )||(x==9 && y>0 && y<9 && pos[x-1][y] != '.' &&pos[x][y-1] != '.'  && pos[x][y+1] != '.' )
		||(x>0 && x<9 && y>0 && y<9 && pos[x+1][y] != '.' && pos[x-1][y] != '.' &&pos[x][y+1] != '.'&&pos[x][y-1] != '.' ))
			break;
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++)
			printf("%c ",pos[i][j]);
		printf("\n");
	}	
	return 0;
}
