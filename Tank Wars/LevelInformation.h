#pragma once
#include "GameManager.h"
#include "player.h"
#include "Obstacle.h"
#include "Projectile.h"
#include "GameArea.h"

//This File Contains Information about the Level Design of the Game
//We can design our Own Custom Maps Here,I have designed maps taking width=1355,height=720;
//so don't change the width and height to play these maps
//if u want to change then play only BasicLevel which is not dependent on the width and height
//THANKYOU


//static Class
class Level
{	
	static int Count;
	static int LevelsCount;
	static void InitLevelState(vector<Obstacle*> &obstacle);
public:
	static void RandomLevel(vector<Obstacle*> &obstacle);

	//MAPS
	static void BasicLevel(vector<Obstacle*> &obstacle);
	static void Mall_Arena(vector<Obstacle*> &obstacle);
	static void Devsrena(vector<Obstacle*> &obstacle);
	static void LabyRinth(vector<Obstacle*> &obstacle);
};
int Level::Count;
int Level::LevelsCount=4;

//boundary of the game
void Level:: InitLevelState(vector<Obstacle*> &obstacle)
{
	//clears previous obstacle
	obstacle.clear();

	obstacle.push_back(new Obstacle(GAME_WIDTH / 2, GAME_HEIGHT - GAME_MENU_AREA, 2, GAME_WIDTH));
	obstacle[obstacle.size()-1]->SetColor(Color::RED());
	obstacle[obstacle.size()-1]->SetInternalColor(Color::RED());
}

//---------------------~>[ RANDOM LEVEL SELECTION  (1) ]<~---------------------
//
void Level::RandomLevel(vector<Obstacle*> &obstacle)
{
	InitLevelState(obstacle);
	switch (Count++ % LevelsCount)
	{
	case 0:
		BasicLevel(obstacle);
		break;
	case 1:
		Mall_Arena(obstacle);
		break;
	case 2:
		Devsrena(obstacle);
		break;
	case 3:
		LabyRinth(obstacle);
		break;
	}
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
//					:~>  WORLD_MAPS <~:
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//


//---------------------~>[ BASIC LEVEL  (0) ]<~---------------------
//this function will initialize all the obstacle in the Level1
void Level::BasicLevel(vector<Obstacle*> &obstacle)
{
	//doing this map design manually
	InitLevelState(obstacle);

	obstacle.push_back(new Obstacle(GAME_WIDTH/2.0 , GAME_HEIGHT/2.0+120,120,40));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(GAME_WIDTH / 2.0 , GAME_HEIGHT / 2.0-120,120 , 40));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

}
//---------------------~>[ MALL_ARENA  (0) ]<~---------------------
//this function will initialize all the obstacle in the Level1
void Level:: Mall_Arena(vector<Obstacle*> &obstacle)
{
	InitLevelState(obstacle);

	obstacle.push_back(new Obstacle(GAME_WIDTH/2-250,GAME_HEIGHT/2-120,60,220));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(GAME_WIDTH / 2 + 250, GAME_HEIGHT / 2 + 65, 60, 220));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(787.5,504,218,60));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(506,126,172,61));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(1198, 87, 172, 60));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(142, 577, 172, 60));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(439, 515, 35, 201));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(875, 154, 35, 201));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

}

//---------------------~>[ DEVS_ARENA  (2) ]<~---------------------
//this function will initialize all the obstacle in the Level1
void Level:: Devsrena(vector<Obstacle*> &obstacle)
{
	InitLevelState(obstacle);

	//DRAWING S(SHUBAM_SHARMA)
	obstacle.push_back(new Obstacle(406,505, 44, 224));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(318, 412, 143, 47));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(406, 321, 44, 224));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());
	
	obstacle.push_back(new Obstacle(494, 229, 143, 47));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(405, 137, 44, 224));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	//drawing A(AKASH_SANGWAN)
	obstacle.push_back(new Obstacle(767, 321, 411, 43));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(1035, 321, 411, 43));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(900, 325, 45, 141));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(901, 505, 44, 227));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());
}

//---------------------~>[ LABYRINTH  (3) ]<~---------------------
//this function will initialize all the obstacle in the Level1
void Level::LabyRinth(vector<Obstacle*> &obstacle)
{
	InitLevelState(obstacle);

	obstacle.push_back(new Obstacle(667,212,26,775));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(152, 306, 482, 25));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

	obstacle.push_back(new Obstacle(1182, 306, 482, 25));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());


	obstacle.push_back(new Obstacle(1067, 264, 130, 25));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());


	obstacle.push_back(new Obstacle(268,264, 130, 25));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());


	obstacle.push_back(new Obstacle(987, 559, 26, 416));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());


	obstacle.push_back(new Obstacle(351, 559, 26, 421));
	obstacle[obstacle.size() - 1]->SetColor(Color::OBSTACLE_DARK());
	obstacle[obstacle.size() - 1]->SetInternalColor(Color::OBSTACLE_LIGHT());

}