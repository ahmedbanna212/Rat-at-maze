#include<string>
using namespace std;
class MazeAI{
	// Maze size
	#define N 12
	#define M 18
	int countForSolution1 = 0;
	int countForSolution2 = 0;
	int oneStep = 1;
	
public:
	const string wall = "#";
	const string rightPath = ".";
	string MazeSolution1[N][M] = { {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
								   {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#" },
								   {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
								   {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#" },
								   {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
								   { "#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
								   {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#" },
								   {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
								   {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#" },
								   {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
		                           {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
								   {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"}};

	string MazeSolution2[N][M] ={{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
							     {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
							     {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
							     {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
							     {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
							     {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
							     {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
							     {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
							     {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
							     {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
							     {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},
							     {"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"}};
	bool withinBorders(int n, int m, int x, int y) {
		if (x == N - 1 && y == M - 1)
			return true;
		else
			return false;
	}

	//starting to solve the maze by moving right first
	bool moveRightSolve(string maze[N][M], int posX, int posY) {
		//check if the position of x and y is the goal (N, M)
		if (withinBorders(N, M, posX, posY) && maze[posX][posY] != wall) {
			MazeSolution1[posX][posY] = rightPath;
			return true;
		}

		//check if the position of x and y within the maze
		if (posX >= 0 && posX < N && posY >= 0 && posY < M && maze[posX][posY] != wall) {
			//check if the current position is already part of solution path.   
			if (MazeSolution1[posX][posY] == rightPath)
				return false;

			//set the current position as part of solution path
			MazeSolution1[posX][posY] = rightPath;

			//moving right direction
			if (moveRightSolve(maze, posX + oneStep, posY)) {
				countForSolution1++;
				return true;
			}
			//moving downwards if cannot move right
			if (moveRightSolve(maze, posX, posY + oneStep)) {
				countForSolution1++;
				return true;
			}
			//moving right if cannot move down
			if (moveRightSolve(maze, posX - oneStep, posY)) {
				countForSolution1++;
				return true;
			}
			//moving upwards if cannot move right
			if (moveRightSolve(maze, posX, posY - oneStep)) {
				countForSolution1++;
				return true;
			}
			//set the solution to 0 if cannot move any direction
			MazeSolution1[posX][posY] = wall;
			return false;
		}

		return false;
	}


	//starting to solve the maze by moving downwards first
	bool moveDownSolve(string maze[N][M], int posX, int posY) {
		//check if the position of x and y is open path while it is within the maze borders
		if (withinBorders(N, M, posX, posY) && maze[posX][posY] != wall) {
			MazeSolution2[posX][posY] = rightPath;
			return true;
		}

		//check if the position of x and y within the maze
		if (posX >= 0 && posX < N && posY >= 0 && posY < M && maze[posX][posY] != wall) {
			// Check if the current block is already part of solution path.   
			if (MazeSolution2[posX][posY] == rightPath)
				return false;

			//set the current position as part of solution path
			MazeSolution2[posX][posY] = rightPath;

			//moving downwards
			if (moveDownSolve(maze, posX, posY + oneStep)) {
				countForSolution2++;
				return true;
			}
			//moveing right if cannot move downwards
			if (moveDownSolve(maze, posX + oneStep, posY)) {
				countForSolution2++;
				return true;
			}
			//moving left if cannot move right
			if (moveDownSolve(maze, posX - oneStep, posY)) {
				countForSolution2++;
				return true;
			}
			//moving upwards if cannot move left
			if (moveDownSolve(maze, posX, posY - oneStep)) {
				countForSolution2++;
				return true;
			}
			//if cannot move at all then set the solution to  wall
			MazeSolution2[posX][posY] = wall;
			return false;
		}
		return false;
	}
	int getSolution1Steps() {
		return countForSolution1;
	}
	int getSolution2Steps() {
		return countForSolution2;
	}
};

