/*
    Original Author: S. M. Shahriar Nirjon
    Modified by: Mohammad Saifur Rahman
	last Modified By: Simanta Deb Turja
    last modified: 29 Januray, 2017
    Version: 2.0
*/

# include "iGraphics.h"
# include <stdio.h>
# include <math.h>
/*LEVEL 1*/
int isettimernullfuncms;
int isettimernullfunc;
int isettimerbullet;
int isettimerasteriods;
int isettimerbackground;
int isettimerstone;
int isettimergalaxy;
int isettimerenemy1;
int isettimercomenemy;
int isettimermsenemy;
int isettimerenemy1bullet;
int collisionCheckNumber = 0;
int collisionenemy1shipNumber = 0;
int numberOfbombs = 0;
int isettimerbomb;
int isettimernullfuncenemy3;
int isettimerreleasebomb;
int isettimerenemy3;
int isettimerenemy2;
int isettimerenemy2bullet;
int callenemy2bullet;
int isettimerboss;

/*Constant Variables*/
#define max 100007
#define screenWidth 1200		
#define screenHeight 750
#define speedBullet 55
#define speedEnemy 15
#define speedAsteriods 8
#define speedStone 8
#define speedShip 50
#define speedComEnemy 10
#define speedBackground 5
#define totalbackground 12
#define totalAsteriods 5
#define totalStone 4
#define totalGalaxy 7
#define totalBullet 100001
#define constantbullet 52
#define constantbulletX 90
#define enemyNumber 12
#define speedEnemyBullet 30
#define enemyNumber2 4
#define bombNumber 5
#define enemyNumber3 12


/*Variables*/
int bombRandX;
int bombRandY;

/*AIRPLANE & BULLET & EXPLOSION*/
char imageship[30][30] = { "images//airplane//ship1.bmp", "images//airplane//ship2.bmp", "images//airplane//ship3.bmp",
"images//airplane//ship4.bmp", "images//airplane//ship5.bmp" };

struct Ship{
	int x;
	int y;
	int index;
}ship;

void setShip()
{
	ship.x = 30;
	ship.y = screenHeight - 440;
}

void showShip()
{
	ship.index++;
	if (ship.index > 4) {
		ship.index = 0;
	}
	iShowBMP2(ship.x, ship.y, imageship[ship.index], 0);
}


/*Bullets*/
char imagebullet[10][30] = { "images//bullet//guli1.bmp" };

struct Bullet{
	int x;
	int y;
	int index;
	bool show;
}bullet[totalBullet];
int numberOfBullets = 0;

void setBullet()
{
	for (int i = 0; i < totalBullet; i++) {
		bullet[i].show = true;
	}
}

void initializeBullet()
{
	numberOfBullets++;

	if (numberOfBullets >= totalBullet) {
		numberOfBullets = 0;
	}
	if (numberOfBullets != 0) {
		bullet[numberOfBullets - 1].x = ship.x + constantbulletX;
		bullet[numberOfBullets - 1].y = ship.y + constantbullet;
	}
	else {

		bullet[numberOfBullets].x = ship.x + constantbulletX;
		bullet[numberOfBullets].y = ship.y + constantbullet;
	}

}

void moveBullet()
{
	for (int i = 0; i < numberOfBullets; i++) {
		bullet[i].x += speedBullet;
		if (bullet[i].x > screenWidth)
			bullet[i].x = screenWidth + screenWidth;
	}
}

void showBullet()
{
	for (int i = 0; i < numberOfBullets; i++) {
		if (bullet[i].show)
			iShowBMP2(bullet[i].x, bullet[i].y, imagebullet[bullet[i].index], 0);
	}
}

void setBulletPos(int x)
{
	bullet[x].x = screenWidth + 30;
}


void showExplosion(int x, int y)
{
	iShowBMP2(x, y, "images//explosion//explosion.bmp", 0);
}
void showExplosion2(int x, int y)
{
	iShowBMP2(x, y, "images//explosion//4.bmp", 0);
}
/*FIXED BOMB*/

struct BOMBFIXED{
	int x;
	int y;
	int index;
	bool show;
}bombfixed[3];

void setbombfixed()
{
	for (int i = 0; i < 3; i++)
	{
		bombfixed[i].x = screenWidth;
		bombfixed[i].y = rand() % 600;
	}
}




/*LEVEL 1*/

/*BACKGROUND*/

char imagesbackground[13][31] = { "images//background//back1.bmp", "images//background//back2.bmp", "images//background//back3.bmp",
"images//background//back4.bmp", "images//background//back5.bmp", "images//background//back6.bmp", "images//background//back7.bmp",
"images//background//back8.bmp", "images//background//back9.bmp", "images//background//back10.bmp", "images//background//back11.bmp",
"images//background//back12.bmp" };


struct Background{
	int x;
	int y;
	bool show;
}background[13], background2[13], b, b1;

void setBackground()
{

	int add = 0;
	for (int i = 0; i < 12; i++){
		background[i].x = add;

		background[i].y = 0;

		add += 100;
	}
}

void showBackground()
{
	for (int i = 0; i < 12; i++){
		iShowBMP(background[i].x, background[i].y, imagesbackground[i]);
	}
}


void moveBackground()
{
	for (int i = 0; i < 12; i++){
		background[i].x -= speedBackground;

		if (background[i].x <= 0){
			background[i].x = screenWidth;

		}
	}
}



/*ASTERIODS*/

char imageasteriods[10][35] = { "images//asteriods//asteriods.bmp" };

struct Asteriods{
	int x;
	int y;
	int index;
}asteriods[6];

void setAsteriods()
{
	for (int i = 0; i < totalAsteriods; i++) {
		asteriods[i].x = rand() % screenWidth;
		asteriods[i].y = rand() % screenHeight;

	}
}

void moveAsteriods()
{
	for (int i = 0; i < totalAsteriods; i++) {
		asteriods[i].x -= speedAsteriods;
		if (asteriods[i].x <= 0) {
			asteriods[i].x = screenWidth;
			asteriods[i].y = rand() % screenHeight;
		}
	}

}

void showAsteriods()
{
	for (int i = 0; i < totalAsteriods; i++) {
		iShowBMP2(asteriods[i].x, asteriods[i].y, imageasteriods[asteriods[i].index], 0);
	}
}


/*STONE*/
char imageStone[50][50] = { "images//stone//stone1.bmp", "images//stone//stone2.bmp", "images//stone//stoneSmall.bmp", "images//stone//stonebrown.bmp" };

struct Stone{
	int x;
	int y;
}stone[10];
int add = 0;
void setStone()
{
	for (int i = 0; i < totalStone; i++) {
		stone[i].x = screenWidth + 20;
		stone[i].y = rand() % screenHeight;
	}
}

void showStone()
{
	for (int i = 0; i < totalStone; i++) {
		iShowBMP2(stone[i].x, stone[i].y, imageStone[i], 0);
	}
}

void moveStone()
{
	for (int i = 0; i < totalStone; i++) {
		stone[i].x -= speedStone;
		if (stone[i].x <= 0) {
			stone[i].x = screenWidth + add;
			stone[i].y = rand() % screenHeight - 300 + add;
			add += 50;
			if (add>300)
				add = 0;
		}
	}
}


/*Galaxy*/
char imagegalaxy[30][30] = { "images//galaxy//galaxy2.bmp", "images//galaxy//galaxy3.bmp", "images//galaxy//galaxy1.bmp", "images//galaxy//galaxy4.bmp",
"images//galaxy//galaxy1.bmp", "images//galaxy//galaxy4.bmp", "images//galaxy//bluedust.bmp" };

struct Galaxy{
	int x;
	int y;
}galaxy[10];

void setGalaxy()
{
	for (int i = 0; i < totalGalaxy; i++) {
		galaxy[i].x = rand() % screenWidth;
		galaxy[i].y = 100 + rand() % screenHeight;
	}
}



void moveGalaxy()
{

	for (int i = 0; i < totalGalaxy; i++)
	{
		galaxy[i].x -= speedAsteriods;
		if (galaxy[i].x <= 0)
			galaxy[i].x = screenWidth + rand() % screenWidth;
	}

}
void showGalaxy()
{
	for (int i = 0; i < totalGalaxy; i++)
		iShowBMP2(galaxy[i].x, galaxy[i].y, imagegalaxy[i], 0);
}


/*	#####################	ENEMY	#################*/
char imageenemy[30][30] = { "images//enemy//1.bmp", "images//enemy//2.bmp", "images//enemy//3.bmp", "images//enemy//4.bmp" };
/*char imageenemy2[100][100] = { "images//enemy2//1.bmp", "images//enemy2//2.bmp", "images//enemy2//3.bmp", "images//enemy2//4.bmp",
"images//enemy2//5.bmp", "images//enemy2//6.bmp", "images//enemy2//7.bmp", "images//enemy2//8.bmp", "images//enemy2//9.bmp",
"images//enemy2//10.bmp", "images//enemy2//11.bmp", "images//enemy2//12.bmp", "images//enemy2//13.bmp", "images//enemy2//14.bmp", "images//enemy2//15.bmp",
"images//enemy2//16.bmp", "images//enemy2//17.bmp", "images//enemy2//18.bmp", "images//enemy2//19.bmp", "images//enemy2//20.bmp",
"images//enemy2//21.bmp", "images//enemy2//22.bmp" };
*/
struct Enemy{
	int x;
	int y;
	int index;
	bool show;
}enemy[100];

void setEnemyPos(int x)
{
	enemy[x].x = screenWidth + 30;
	enemy[x].y = rand() % screenHeight - 100;
}



bool enemylevel1show = true;
void setEnemy()
{

	for (int i = 0; i < enemyNumber; i++) {
		enemy[i].x = screenWidth + rand() % screenWidth;
		enemy[i].y = rand() % 700;
		enemy[i].index = 0;
		enemy[i].show = true;
	}
}

void moveEnemy()
{
	for (int i = 0; i < enemyNumber; i++) {
		enemy[i].x -= speedEnemy;

		if (enemy[i].y < 50)
			enemy[i].y = 50;
		if (enemy[i].y > 550)
			enemy[i].y = 550;

		enemy[i].index++;
		if (enemy[i].index > 3) {
			enemy[i].index = 0;
		}
		if (enemy[i].x <= 0) {
			enemy[i].x = screenWidth + rand() % screenWidth - 200;
		}

	}

}
bool msshow = false;
void showEnemy()
{
	if (enemylevel1show)
	for (int i = 0; i < enemyNumber; i++) {
		if (enemy[i].show) {
			iShowBMP2(enemy[i].x, enemy[i].y, imageenemy[enemy[i].index], 0);
		}
	}
}

int enemyOnScreenCount = 0;
bool enemyOnScreen(int i)
{
	
		if (enemy[i].x < 0)
		{
			return true;
		}
	
		else {
			return false;
		}
}

/*void showExplosion()
{

	for (int i = 0; i < 15; i++) {
		explosion[i].index++;
		if (explosion[i].index > 14)
			explosion[i].index = 0;
		iShowBMP2(ship.x, ship.y, imageexplosion[explosion[i].index], 0);
	}
}*/

/*COMMUNICATION ENEMY SPACE*/

char imageComEnemy[30][30] = { "images//comenemy//1.bmp", "images//comenemy//2.bmp", "images//comenemy//3.bmp" };

struct ComEnemy{
	int x;
	int y;
	int index;
	bool comShip;
	bool posComEnemy;
}comenemy;

void setComEnemy()
{
	comenemy.x = screenWidth + 50;
	comenemy.y = 125;
	comenemy.comShip = true;
	comenemy.posComEnemy = true;
	comenemy.index = 0;
}

void showComEnemy()
{
	if (comenemy.comShip){
		iShowBMP2(comenemy.x, comenemy.y, imageComEnemy[comenemy.index], 0);
		comenemy.index++;
		if (comenemy.index > 2) {
			comenemy.index = 0;
		}
	}
}

void moveComEnemy()
{
	comenemy.x -= speedComEnemy;
	if (comenemy.x <= screenWidth - 320) {
		comenemy.posComEnemy = false;
		iPauseTimer(isettimercomenemy);
		iResumeTimer(isettimernullfunc);
	}

}

/*ENEMY BULLET*/

char imageenemybullet[20][39] = { "images//enemybullet//bulletcom.bmp" };
char imageenemybullet3[20][32] = { "images//enemybullet//guli2.bmp" };

struct EnemyBullet{
	int x;
	int y;
	int x2;
	int y2;
	int x3;
	int y3;
	int index;
	bool show;

}enemybullet[30];
int numberOfEnemyBullets = 0;
int numberOfEnemyBullets2 = 0;

void setEnemyBullet()
{
	for (int i = 0; i < 30; i++) {
		enemybullet[i].show = true;
	}
}

void initializeEnemyBullet()
{
	numberOfEnemyBullets++;

	if (numberOfEnemyBullets >= 20) {
		numberOfEnemyBullets = 0;
	}
	if (numberOfBullets != 0) {
		enemybullet[numberOfEnemyBullets - 1].x3 = comenemy.x + 150;
		enemybullet[numberOfEnemyBullets - 1].y3 = comenemy.y + 250;
		enemybullet[numberOfEnemyBullets - 1].x = comenemy.x + 150;
		enemybullet[numberOfEnemyBullets - 1].x2 = comenemy.x + 150;
		enemybullet[numberOfEnemyBullets - 1].y = comenemy.y + 300;
		enemybullet[numberOfEnemyBullets - 1].y2 = comenemy.y + 200;

	}
	else {
		enemybullet[numberOfEnemyBullets - 1].x3 = comenemy.x + 150;
		enemybullet[numberOfEnemyBullets - 1].y3 = comenemy.y + 250;
		enemybullet[numberOfEnemyBullets].x = comenemy.x + 150;
		enemybullet[numberOfEnemyBullets].x2 = comenemy.x + 150;
		enemybullet[numberOfEnemyBullets].y = comenemy.y + 300;
		enemybullet[numberOfEnemyBullets].y2 = comenemy.y + 200;
	}
}

bool enemybulletshow = true;
void moveEnemyBullet()
{
	for (int i = 0; i < numberOfEnemyBullets; i++) {
		if (comenemy.x >= ship.x && comenemy.y >= ship.y + 60 && comenemy.y <= ship.y) {
			enemybullet[i].x -= speedEnemyBullet;
			enemybullet[i].y -= speedEnemyBullet;
		}
		else {
			enemybullet[i].x -= speedEnemyBullet * cos(.436);
			enemybullet[i].y += speedEnemyBullet * sin(.12);
		}
	}
	for (int i = 0; i < numberOfEnemyBullets; i++) {
		if (comenemy.x >= ship.x && comenemy.y >= ship.y + 60 && comenemy.y <= ship.y) {
			enemybullet[i].x2 -= speedEnemyBullet;
			enemybullet[i].y2 -= speedEnemyBullet;
		}
		else {
			enemybullet[i].x2 -= speedEnemyBullet * cos(.436);
			enemybullet[i].y2 -= speedEnemyBullet * sin(.12);
		}
	}
	for (int i = 0; i < numberOfEnemyBullets; i++) {
		enemybullet[i].x3 -= speedEnemyBullet;
	}
}

void showEnemyBullet()
{
	if (enemybulletshow)
	for (int i = 0; i < numberOfEnemyBullets; i++) {
		if (enemybullet[i].show) {
			iShowBMP2(enemybullet[i].x, enemybullet[i].y, imageenemybullet[enemybullet[i].index], 0);
			iShowBMP2(enemybullet[i].x2, enemybullet[i].y2, imageenemybullet[enemybullet[i].index], 0);
			iShowBMP2(enemybullet[i].x3, enemybullet[i].y3, imageenemybullet3[enemybullet[i].index], 0);
		}
	}
}



/*##########	LEVEL 1 BOSS	#############*/

//MotherShip 
char imagems[30][30] = { "images//mothership//ms1.bmp", "images//mothership//ms2.bmp", "images//mothership//ms3.bmp" };
bool comenemyshow = false;
struct MS {
	int x;
	int y;
	int index;
	bool show;
}ms;

void setMs()
{
	ms.x = screenWidth + rand() % screenWidth;
	ms.y = 220;
	ms.show = true;
}

void showMs()
{
	if (ms.show)
		iShowBMP2(ms.x, ms.y, imagems[ms.index], 0);
}

void moveMs()
{
	ms.x -= 15;
	ms.index++;
	if (ms.index > 2)
		ms.index = 0;
	if (ms.x <= screenWidth - 219)
	{
		//ms.x = screenWidth - 219;
		iPauseTimer(isettimermsenemy);
	}
}

struct msBullet{
	int x;
	int y;
	int x2;
	int y2;
	int x3;
	int y3;
	int index;
	bool show;

}msBullet[30];

bool msbulletshow = true;
void initializeMsBullet()
{
	numberOfEnemyBullets2++;

	if (numberOfEnemyBullets2 >= 20) {
		numberOfEnemyBullets2 = 0;
	}
	if (numberOfEnemyBullets2 != 0) {
		msBullet[numberOfEnemyBullets2 - 1].x3 = ms.x;
		msBullet[numberOfEnemyBullets2 - 1].y3 = ms.y + 200;
		msBullet[numberOfEnemyBullets2 - 1].x = ms.x;
		msBullet[numberOfEnemyBullets2 - 1].x2 = ms.x;
		msBullet[numberOfEnemyBullets2 - 1].y = ms.y + 250;
		msBullet[numberOfEnemyBullets2 - 1].y2 = ms.y + 150;

	}
	else {
		msBullet[numberOfEnemyBullets2].x3 = ms.x;
		msBullet[numberOfEnemyBullets2].y3 = ms.y + 200;
		msBullet[numberOfEnemyBullets2].x = ms.x;
		msBullet[numberOfEnemyBullets2].x2 = ms.x;
		msBullet[numberOfEnemyBullets2].y = ms.y + 250;
		msBullet[numberOfEnemyBullets2].y2 = ms.y + 150;
	}
}

void showMsBullet()
{
	if (msbulletshow)
	for (int i = 0; i < numberOfEnemyBullets2; i++) {
		iShowBMP2(msBullet[i].x, msBullet[i].y, imageenemybullet[msBullet[i].index], 0);
		iShowBMP2(msBullet[i].x2, msBullet[i].y2, imageenemybullet[msBullet[i].index], 0);
		iShowBMP2(msBullet[i].x3, msBullet[i].y3, imageenemybullet3[msBullet[i].index], 0);
	}
}

void moveMsBullet()
{
	for (int i = 0; i < numberOfEnemyBullets2; i++) {
		if (ms.x >= ship.x && ms.y >= ship.y + 60 && ms.y <= ship.y) {
			msBullet[i].x -= speedEnemyBullet;
			msBullet[i].y -= speedEnemyBullet;
		}
		else {
			msBullet[i].x -= speedEnemyBullet * cos(.436);
			msBullet[i].y += speedEnemyBullet * sin(.12);
		}
	}
	for (int i = 0; i < numberOfEnemyBullets; i++) {
		if (ms.x >= ship.x && ms.y >= ship.y + 60 && ms.y <= ship.y) {
			msBullet[i].x2 -= speedEnemyBullet;
			msBullet[i].y2 -= speedEnemyBullet;
		}
		else {
			msBullet[i].x2 -= speedEnemyBullet * cos(.436);
			msBullet[i].y2 -= speedEnemyBullet * sin(.12);
		}
	}
	for (int i = 0; i < numberOfEnemyBullets2; i++) {
		msBullet[i].x3 -= speedEnemyBullet;
	}
}


char imageenemy3[30][30] = { "images//enemy3//1.bmp", "images//enemy3//2.bmp", "images//enemy3//3.bmp" };
/*char imageenemy2[100][100] = { "images//enemy2//1.bmp", "images//enemy2//2.bmp", "images//enemy2//3.bmp", "images//enemy2//4.bmp",
"images//enemy2//5.bmp", "images//enemy2//6.bmp", "images//enemy2//7.bmp", "images//enemy2//8.bmp", "images//enemy2//9.bmp",
"images//enemy2//10.bmp", "images//enemy2//11.bmp", "images//enemy2//12.bmp", "images//enemy2//13.bmp", "images//enemy2//14.bmp", "images//enemy2//15.bmp",
"images//enemy2//16.bmp", "images//enemy2//17.bmp", "images//enemy2//18.bmp", "images//enemy2//19.bmp", "images//enemy2//20.bmp",
"images//enemy2//21.bmp", "images//enemy2//22.bmp" };
*/
struct Enemy3{
	int x;
	int y;
	int index;
	bool show;
}enemy3[100];


bool enemy3level1show = true;
void setEnemy3()
{

	for (int i = 0; i < enemyNumber; i++) {
		enemy3[i].x = screenWidth + rand() % screenWidth;
		enemy3[i].y = rand() % 700;
		enemy3[i].index = 0;
		enemy3[i].show = false;
	}
}

void moveEnemy3()
{
	for (int i = 0; i < enemyNumber; i++) {
		enemy3[i].x -= speedEnemy;

		if (enemy3[i].y < 50)
			enemy3[i].y = 50;
		if (enemy3[i].y > 550)
			enemy3[i].y = 550;

		enemy3[i].index++;
		if (enemy3[i].index > 2) {
			enemy3[i].index = 0;
		}
		if (enemy3[i].x <= 0) {
			enemy3[i].x = screenWidth + rand() % screenWidth - 200;
			enemy3[i].y = rand() % 600;
		}

	}

}

void showEnemy3()
{
	for (int i = 0; i < enemyNumber; i++) {
		if (enemy3[i].show) {
			iShowBMP2(enemy3[i].x, enemy3[i].y, imageenemy3[enemy3[i].index], 0);
		}
	}
}

void setEnemyPos2(int x)
{
	enemy3[x].x = screenWidth + 30;
	enemy3[x].y = rand() % screenHeight - 100;
}



/*BOMB*/

char imagebomb[30][40] = { "images//bomb//1.bmp", "images//bomb//2.bmp", "images//bomb//3.bmp" };
struct BOMB {
	int x;
	int y;
	int x2;
	int y2;
	int index;
	bool show;
}bomb[bombNumber];
bool bombshow = false;
void initializeBomb()
{
	numberOfbombs++;
	if (numberOfbombs > 4)
	{
		numberOfbombs = 0;
	}
	if (numberOfbombs != 0)
	{
		bomb[numberOfbombs - 1].x = comenemy.x + 10;
		bomb[numberOfbombs - 1].y = comenemy.y + 250;
		bomb[numberOfbombs - 1].x2 = comenemy.x + 10;
		bomb[numberOfbombs - 1].y2 = comenemy.y + 250;
	}
	else {
		bomb[numberOfbombs].x = comenemy.x + 10;
		bomb[numberOfbombs].y = comenemy.y + 250;
		bomb[numberOfbombs].x2 = comenemy.x + 10;
		bomb[numberOfbombs].y2 = comenemy.y + 250;
	}
}

void showBomb()
{
	for (int i = 0; i < bombNumber; i++)
	{
		if (bomb[i].show) {
			iShowBMP2(bomb[i].x, bomb[i].y, imagebomb[bomb[i].index], 0);
			iShowBMP2(bomb[i].x2, bomb[i].y2, imagebomb[bomb[i].index], 0);
		}
	}
}

void moveBomb()
{
	for (int i = 0; i < bombNumber; i++)
	{
		bomb[i].x -= 20;
		bomb[i].y -= 10;
		bomb[i].x2 -= 20;
		bomb[i].y2 += 10;

	}
}


//LEVEL 2//

//ENEMY LEVEL 2//

char imageenemy2[40][40] = { "images//enemylevel2//1.bmp", "images//enemylevel2//2.bmp", "images//enemylevel2//3.bmp",
"images//enemylevel2//4.bmp", "images//enemylevel2//5.bmp", "images//enemylevel2//6.bmp", "images//enemylevel2//7.bmp",
"images//enemylevel2//8.bmp" };


struct Enemy2{
	int x;
	int y;
	int index;
	bool show;
	int hitEnemy2;
}enemy2[100], e;



void setEnemy2()
{
	int addX = 0;
	int addY = 650;
	for (int i = 0; i < enemyNumber2; i++) {
		enemy2[i].x = screenWidth + addX + rand() % screenWidth;
		enemy2[i].y = rand() % addY;
		enemy2[i].index = 0;
		add += 200;
		addY -= 100;
		enemy2[i].show = true;
		enemy2[i].hitEnemy2 = 0;

	}
	
}



void moveEnemy2()
{
	for (int i = 0; i < enemyNumber2; i++) {

		enemy2[i].x -= speedEnemy;

		enemy2[i].index++;
		if (enemy2[i].index > 7) {
			enemy2[i].index = 0;
		}
		if (enemy2[i].x <= 0) {
			enemy2[i].x = screenWidth + rand() % screenWidth - 200;
		}

	}

}

void showEnemy2()
{
	
	for (int i = 0; i < enemyNumber2; i++) {
		if (enemy2[i].show)
			iShowBMP2(enemy2[i].x, enemy2[i].y, imageenemy2[enemy[i].index], 0);
	}
}

void trueEnemy2()
{
	for (int i = 0; i < enemyNumber2; i++)
		enemy2[i].show = true;
}

/*ENEMY LEVEL 2 BULLET*/

char imageenemybullet2[50][50] = { "images//enemybullet//guli22.bmp" };

int numberOfEnemy2Bullets = 0;
struct ENEMY2BULLET{
	int x;
	int y;
	int index;
	bool show;
}enemy2bullet[enemyNumber][30];


void setenemy2bullet()
{
	for (int i = 0; i < enemyNumber2; i++)
	{
		for (int j = 0; j < numberOfEnemy2Bullets; j++)
		{
			enemy2bullet[i][j].show = true;
		}
	}
}

void initializeenemy2bullet()
{
	numberOfEnemy2Bullets++;
	if (numberOfEnemy2Bullets > 20)
	{
		numberOfEnemy2Bullets = 0;
	}
	for (int i = 0; i < enemyNumber2; i++)
	{
		if (numberOfEnemy2Bullets == 0)
		{
			enemy2bullet[i][numberOfEnemy2Bullets].x = enemy2[i].x;
			enemy2bullet[i][numberOfEnemy2Bullets].y = enemy2[i].y + 50 ;
		}
		else
		{
			enemy2bullet[i][numberOfEnemy2Bullets - 1].x = enemy2[i].x;
			enemy2bullet[i][numberOfEnemy2Bullets - 1].y = enemy2[i].y + 50;
		}
	}
}

void moveEnemyBullet2()
{
	for (int i = 0; i < enemyNumber2; i++) 
	{
		for (int j = 0; j < numberOfEnemy2Bullets; j++)
		{
			enemy2bullet[i][j].x -= speedEnemyBullet;
		}
		
	}
}

void showenemybullet2()
{
	if (!ms.show && !comenemy.comShip)
	for (int i = 0; i < enemyNumber2; i++) {
		for (int j = 0; j < numberOfEnemy2Bullets; j++){
			if (enemy2[i].show)
			iShowBMP2(enemy2bullet[i][j].x, enemy2bullet[i][j].y, imageenemybullet2[enemy2bullet[i][j].index], 0);
		}
	}
}

void callbulletEnemy2()
{
	initializeenemy2bullet();
}
/*CHECK ENEMY ON SCREEN*/

bool flag = false;
void checkEnemyOnScreen()
{
	for (int i = 0; i < enemyNumber; i++)
	{
		if (!enemy[i].show || enemy[i].x < 0 || enemy[i].x > screenWidth)
		{
			flag = true;
		}
		else
		{
			flag = false;
			break;
		}
	}
}

/*FINAL BOSS*/

char imagesboss[30][40] = { "images//boss//1.bmp", "images//boss//2.bmp", "images//boss//3.bmp", "images//boss//4.bmp",
"images//boss//5.bmp", "images//boss//6.bmp", "images//boss//7.bmp", "images//boss//8.bmp" };

struct BOSS{
	int x;
	int y;
	int index;
	bool show;
}boss;

void setBoss()
{
	boss.x = screenWidth + rand() % screenWidth;
	boss.y = 250;
	boss.show = false;
	boss.index = 0;
}


void showBoss()
{
	if (boss.show)
		iShowBMP2(500, 500,imagesboss[boss.index] , 0);
}

void moveBoss()
{
	boss.index++;
	if (boss.index > 7)
		boss.index = 0;
	boss.x -= 50;
}


/*COLLISION*/




void collisionCheck()
{
	for (int i = 0; i < enemyNumber; i++)
	{
		for (int j = 0; j < numberOfBullets; j++)
		{
			if (enemy[i].show)
			{
				if (bullet[j].x >= enemy[i].x && bullet[j].x <= enemy[i].x + 45)
				{
					if (bullet[j].y >= enemy[i].y && bullet[j].y <= enemy[i].y + 90)
					{
						
						showExplosion(enemy[i].x, enemy[i].y);
						enemy[i].show = false;
						bullet[j].show = false;
						setEnemyPos(i);
						enemy[i].show = true;
						setBulletPos(j);
						bullet[j].show = true;
						collisionCheckNumber++;
	
						if (collisionCheckNumber > 50)
						{
							if (comenemy.x <= 1081)
								comenemy.x += 20;	
							if (comenemy.x > 1082) {
								iResumeTimer(isettimernullfuncms);
								iResumeTimer(isettimernullfuncenemy3);
							}
							if (enemy[i].x > 0)
							{
								enemy[i].x -= 50;
								enemy[i].show = false;
							}
							
						}
						
					}
				}
			}
		}
	}
}

int collisionCheckNumber2 = 0;
void collisionCheck2()
{
	for (int i = 0; i < enemyNumber3; i++)
	{
		for (int j = 0; j < numberOfBullets; j++)
		{
			if (enemy3[i].show)
			{
				if (bullet[j].x >= enemy3[i].x && bullet[j].x <= enemy3[i].x + 45)
				{
					if (bullet[j].y >= enemy3[i].y && bullet[j].y <= enemy3[i].y + 90)
					{
						if (collisionCheckNumber2 % 10 == 0)
						{
							initializeEnemyBullet();
						}
						
						showExplosion(enemy3[i].x, enemy3[i].y);
						enemy3[i].show = false;
						bullet[j].show = false;
						setEnemyPos2(i);
						if (ms.show == true && comenemy.comShip == true)
						{
							enemy3[i].show = true;
						}
						setBulletPos(j);
						bullet[j].show = true;
						collisionCheckNumber2++;
						
						if (collisionCheckNumber2 > 10)
						{
							comenemy.x += 20;
							ms.x += 20;
							if (enemy3[i].x < 0)
							{
								enemy3[i].show = false;
							}
							if (comenemy.x > screenWidth + 20)
							{
								comenemy.comShip = false;
							}
							if (ms.x > screenWidth + 20)
							{
								ms.show = false;
							}
						}

					}
				}
			}
		}
	}
}

void entryEnemy2()
{
	if (!ms.show && !comenemy.comShip)
	{
		iResumeTimer(isettimerenemy2);
		iResumeTimer(isettimerenemy2bullet);
		iResumeTimer(callenemy2bullet);
	}
}


int bombCount = 0;
void releaseBomb()
{
	bombCount++;
	if (bombCount % 8 == 0)
		initializeBomb();
}

/*LEVEL 1 COLLISION*/

void collisionenemy1ship()
{
	for (int i = 0; i < enemyNumber; i++)
	{
		if (enemy[i].show)
		{
			if (ship.x + 180 >= enemy[i].x && ship.x + 180 <= enemy[i].x + 45)
			{
				if ((ship.y >= enemy[i].y  && ship.y <= enemy[i].y + 40) || (ship.y <= enemy[i].y && ship.y + 120 >= enemy[i].y))
				{
					enemy[i].show = false;
					setEnemyPos(i);
					showExplosion2(ship.x + 60, ship.y-20);
					enemy[i].show = true;
				}
			}
		}
	}
}

void collisionComShip()
{
	for (int i = 0; i < numberOfEnemyBullets; i++)
	{
		if (enemy3[i].show)
		{
			if (ship.x + 120 >= enemybullet[i].x && ship.x <= enemybullet[i].x + 20)
			{
				if ((ship.y >= enemybullet[i].y && ship.y <= enemybullet[i].y + 30) || (ship.y <= enemybullet[i].y && ship.y + 120 >= enemybullet[i].y))
				{
					enemybullet[i].show = false;
					showExplosion2(ship.x + 50, ship.y - 30);
				}
			}
			if (ship.x + 120 >= enemybullet[i].x2 && ship.x <= enemybullet[i].x2 + 20)
			{
				if ((ship.y >= enemybullet[i].y2 && ship.y <= enemybullet[i].y2 + 30) || (ship.y <= enemybullet[i].y2 && ship.y + 120 >= enemybullet[i].y2))
				{
					enemybullet[i].show = false;
					showExplosion2(ship.x + 50, ship.y - 30);
				}
			}
			if (ship.x + 120 >= enemybullet[i].x3 && ship.x <= enemybullet[i].x3 + 20)
			{
				if ((ship.y >= enemybullet[i].y3 && ship.y <= enemybullet[i].y3 + 30) || (ship.y <= enemybullet[i].y3 && ship.y + 120 >= enemybullet[i].y3))
				{
					enemybullet[i].show = false;
					showExplosion2(ship.x + 50, ship.y - 30);
				}
			}
		}
	}
}

void collisionEnemy2Bullet()
{
	for (int i = 0; i < enemyNumber2; i++)
	{
		for (int j = 0; j < numberOfEnemy2Bullets; j++)
		{
			if (enemy2[i].show && enemy2bullet[i][j].show)
			if (ship.x + 180 >= enemy2bullet[i][j].x && ship.x <= enemy2bullet[i][j].x + 30)
			{
				if((ship.y >= enemy2bullet[i][j].y && ship.y <= enemy2bullet[i][j].y + 30) || (ship.y <= enemy2bullet[i][j].y && ship.y + 120 >= enemy2bullet[i][j].y))
				{
					enemy2bullet[i][j].show = false;
					showExplosion2(ship.x + 50, ship.y - 30);
				}
			}
		}
	}
}
int collisionCheck3number = 0;
void collisionCheck3()
{
	for (int i = 0; i < enemyNumber2; i++)
	{
		for (int j = 0; j < numberOfBullets; j++)
		{
			if (enemy2[i].show)
			{
				if (bullet[j].x >= enemy2[i].x && bullet[j].x <= enemy2[i].x + 50)
				{
					if (bullet[j].y >= enemy2[i].y && bullet[j].y <= enemy2[i].y + 100)
					{
						showExplosion(enemy2[i].x, enemy2[i].y);
						enemy2[i].show = false;
						collisionCheck3number++;
						if (collisionCheck3number > 3)
						{
							boss.show = true;
						}
						
					}
				}
			}
		}
	}
}


/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	
	iClear();
	/*LEVEL 1*/
	/*SHOW*/
	
	showBackground();
	showGalaxy();
	showAsteriods();
	showStone();
	showEnemy();
	showEnemyBullet();
	showMs();
	showComEnemy();
	showenemybullet2();
	showEnemy2();
	showBullet();
	showShip();
	showBomb();
	showEnemy3();
	showBoss();
	/*CollisionCheck*/
	collisionCheck();
	collisionenemy1ship();
	collisionComShip();
	collisionCheck2();
	entryEnemy2();
	collisionEnemy2Bullet();
	collisionCheck3();
	
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		initializeBullet();
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 /*mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 //else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'w')
	{
		ship.y += speedShip;

		if (ship.y > screenHeight - 150) {

			ship.y = screenHeight - 150;
		}
	}
	if (key == 's')
	{
		ship.y -= speedShip;
		if (ship.y < 0) {
			ship.y = 0;
		}
	}
	if (key == 'a')
	{
		ship.x -= speedShip;
		if (ship.x < 0)
			ship.x = 0;
	}
	if (key == 'd')
	{
		ship.x += speedShip;
		if (ship.x > screenWidth - 150)
			ship.x = screenWidth - 150;
	}
	if (key == ' ')
		initializeBomb();
	
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}
//
int nullFuncCallCount = 0;
int nullfuncMSENEMYCount = 0;
int nullfuncenemy3Count = 0;
void nullfunc()
{
	nullFuncCallCount++;
	if (nullFuncCallCount > 8) {
		iResumeTimer(isettimerenemy1);
		iPauseTimer(isettimernullfunc);
	}
}

void nullfuncMSENEMY()
{
	nullfuncMSENEMYCount++;
	if (nullfuncMSENEMYCount > 8)
	{
		iResumeTimer(isettimermsenemy);
		iResumeTimer(isettimercomenemy);
		iPauseTimer(isettimernullfuncms);
	}
}

void nullfuncenemy3()
{
	for (int i = 0; i < enemyNumber3; i++)
	{
		enemy3[i].show = true;
	}
	nullfuncenemy3Count++;
	if (nullfuncenemy3Count > 8)
	{
		iResumeTimer(isettimerbomb);
		iResumeTimer(isettimerenemy3);
		iPauseTimer(isettimernullfuncenemy3);
	}
}

int main()
{
	
	/*Null iSettimer*/
	isettimernullfunc = iSetTimer(25, nullfunc);
	isettimernullfuncms = iSetTimer(25, nullfuncMSENEMY);
	/*SET*/
	setShip();
	setBullet();
	setAsteriods();
	setBackground();
	setStone();
	setGalaxy();
	setEnemy();
	setComEnemy();
	setMs();
	setEnemyBullet();
	setEnemy3();
	/*iSetTimer*/
	isettimerbullet = iSetTimer(25, moveBullet);
	isettimerasteriods = iSetTimer(25, moveAsteriods);
	isettimerbackground = iSetTimer(25, moveBackground);
	isettimergalaxy = iSetTimer(25, moveGalaxy);
	isettimerstone = iSetTimer(25, moveStone);
	isettimerenemy1 = iSetTimer(25, moveEnemy);
	isettimercomenemy = iSetTimer(25, moveComEnemy);
	isettimermsenemy = iSetTimer(25, moveMs);
	isettimerenemy1bullet = iSetTimer(25, moveEnemyBullet);
	isettimerbomb = iSetTimer(25, moveBomb);
	isettimernullfuncenemy3 = iSetTimer(25, nullfuncenemy3);
	isettimerreleasebomb = iSetTimer(25, releaseBomb);
	isettimerenemy3 = iSetTimer(25, moveEnemy3);
	/*iPauseTimer*/
	iPauseTimer(isettimernullfunc);
	iPauseTimer(isettimernullfuncms);
	iPauseTimer(isettimermsenemy);
	iPauseTimer(isettimerenemy1);
	iPauseTimer(isettimerbomb);
	iPauseTimer(isettimernullfuncenemy3);
	iPauseTimer(isettimerreleasebomb);
	iPauseTimer(isettimerenemy3);
	

	/*LEVEL 2*/
	
	/*SET*/
	setEnemy2();
	setenemy2bullet();

	/*isettimer*/
	isettimerenemy2 = iSetTimer(25, moveEnemy2);
	isettimerenemy2bullet = iSetTimer(25, moveEnemyBullet2);
	callenemy2bullet = iSetTimer(1000, callbulletEnemy2);
	/*iPausetimer*/
	iPauseTimer(isettimerenemy2);
	iPauseTimer(isettimerenemy2bullet);
	iPauseTimer(callenemy2bullet);
	/*Boss*/
	isettimerboss = iSetTimer(25, moveBoss);
	iInitialize(screenWidth, screenHeight, "SAVE THE PROGRAMMER");
	return 0;
}
