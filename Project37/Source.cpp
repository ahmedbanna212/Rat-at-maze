#include <iostream>
#include<string>
#include"MazeAI.h"
using namespace std;
int correctsteps=0;
#define N 12
#define M 18
//Print out the array of solution
void printMazeSolution(string maze[N][M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << maze[i][j] << ' ';
		cout << endl;
	}
}

// Inserting the maze to solve
int main(){
	MazeAI mazeAI;

	string maze[N][M] = { { ".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".","#"},
						   {".",".",".",".","#","#","#",".","#","#","#","#","#","#",".",".",".","#"},
						   {"#","#","#",".","#",".",".",".",".",".","#",".","#","#",".","#",".","#"},
						   {"#","#","#",".","#",".","#","#","#",".",".",".",".",".",".","#",".","#"},
						   {"#","#","#",".","#",".","#","#","#",".","#","#","#","#","#","#","#","#"},
						   {"#",".",".",".","#",".","#","#","#",".","#",".",".",".","#","#","#","#"},
						   {"#",".","#","#","#","#","#","#","#",".","#","#","#",".",".","#","#","#"},
						   {".",".",".","#","#","#","#","#","#",".","#","#","#",".","#","#","#","#"},
						   {"#",".","#","#","#","#",".",".",".",".",".",".",".",".","#",".",".","#"},
						   {"#",".",".",".",".",".",".","#","#",".","#","#","#",".","#",".","#","#"},
						   {"#","#",".",".","#","#",".",".",".",".","#","#","#",".",".",".",".","#"},
						   {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",".","."} };

	string maze2[N][M] = { { ".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".","."},// this maze has two correct paths, our code can detect which path has less steps
						   {".",".",".",".","#","#","#",".","#","#","#","#","#","#",".",".",".","." },
						   {"#","#","#",".","#",".",".",".",".",".","#",".","#","#",".","#",".","."},
						   {"#","#","#",".","#",".","#","#","#",".",".",".",".",".",".","#",".","." },
						   {"#","#","#",".","#",".","#","#","#",".","#","#","#","#","#","#","#","."},
						   { "#",".",".",".",".",".","#","#","#",".","#",".",".",".","#","#","#","."},
						   {"#",".","#","#","#","#","#","#","#",".","#","#","#",".",".","#","#","."},
						   {".",".",".","#","#","#","#","#","#",".","#","#","#",".","#","#","#","."},
						   {"#",".","#","#","#","#",".",".",".",".",".",".",".",".","#",".",".","."},
						   {"#","#","#",".",".",".",".","#","#",".","#","#","#",".","#",".","#","."},
						   {"#","#","#",".","#","#",".",".",".",".","#","#","#",".",".",".",".","."},
						   {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",".","."} };

	

	printf("THIS IS THE MAZE :");
	printf("\n");
	printMazeSolution(maze);
	printf("\n");
	printf("THIS IS THE SHORTEST MAZE SOLUTION:");
	printf("\n");
	
	if (mazeAI.moveRightSolve(maze, 0, 0) == false) {
		printf("Solution doesn't exist");
		return false;
	}
	if (mazeAI.moveDownSolve(maze, 0, 0) == false) {
		printf("Solution doesn't exist");
		return false;
	}
	//check the least number of steps for each solution
	if (mazeAI.getSolution1Steps() < mazeAI.getSolution2Steps()) {
		printMazeSolution(mazeAI.MazeSolution1);
		cout<<"Number of steps :"<<mazeAI.getSolution1Steps() << endl;
		
	}
	else {
		printMazeSolution(mazeAI.MazeSolution2);
		cout << "Number of steps :" << mazeAI.getSolution2Steps() << endl;
		
	}
	return 0;
} 