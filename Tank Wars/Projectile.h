//TANK WARS
#pragma once
//#4.
#include "object.h"
class Projectile:public GameObject
{
	//int pWidth;			//width of Projectile
	double headRatio;   //size of head(smaller values = bigger head)
	double boxColliderOffset;
	
	void init()
	{
		speed = 3;
		height = 30;
		width = 5;
		headRatio = 3.5;
		boxColliderOffset = 0.4;
	}
public:
	Projectile(double x=0,double y=0)
	{
		centre.x = x;
		centre.y = y;
		init();
	}
	Projectile(const Vector2 &point)
	{
		centre = point;
		init();
	}

	void MoveForward()  {state = FORWARD; }
	void MoveBackward() {state = BACKWARD; }
	
	//overrided func
	void Draw();
	void UpdatePos();
	Vector2 GetTopRight();    //returns topright point of player area
	Vector2 GetBottomLeft();   //returns bottomleft point of player area
};
//---------------------~>[ VOx Colliders ]<~---------------------
Vector2 Projectile::GetBottomLeft()   //returns bottomleft point of player area
{
	double x, y;
	if (state == FORWARD || state == BACKWARD)
	{
		x = centre.x - height / 2.0;
		y = centre.y - width / 2.0;
	}
	else if (state == UPWARD || state == DOWNWARD)
	{
		x = centre.x - width / 2.0;
		y = centre.y - height / 2.0;
	}
	
	x -= boxColliderOffset;
	y -= boxColliderOffset;
	Vector2 temp(x,y);
	return temp;
}
Vector2 Projectile::GetTopRight()   //returns bottomleft point of player area
{
	double x, y;
	if (state == FORWARD || state == BACKWARD)
	{
		x = centre.x + height / 2.0;
		y = centre.y + width / 2.0;
	}
	else if (state == UPWARD || state == DOWNWARD)
	{
		x = centre.x + width / 2.0;
		y = centre.y + height / 2.0;
	}

	x += boxColliderOffset;
	y += boxColliderOffset;

	Vector2 temp(x, y);
	return temp;
}
//---------------------~>[ UPDATE POSITION ]<~---------------------
void Projectile::UpdatePos()
{
	switch (state)
	{
	case FORWARD:
		if (centre.x < GAME_WIDTH+height)
			centre.x += speed;
		break;
	case BACKWARD:
		if (centre.x > -height)
			centre.x -= speed;
		break;
	case UPWARD:
		if (centre.y < GAME_HEIGHT+height)
			centre.y += speed;
		break;
	case DOWNWARD:
		if (centre.y > -height)
			centre.y -= speed;
		break;
	}
}
//---------------------~>[ Draw ]<~---------------------
void Projectile::Draw()
{
	this->color.SetGLColor();

	switch (state)
	{
	case FORWARD:
		glBegin(GL_QUADS);//back of arrow
		
		glVertex2d(centre.x-height/2,centre.y+width/2);
		glVertex2d(centre.x-height/2,centre.y-width/2);
		glVertex2d(centre.x+height/2-height/headRatio,centre.y-width/2);
		glVertex2d(centre.x+height/2-height/headRatio,centre.y+ width/2);
		glEnd();

		glBegin(GL_TRIANGLES);//arrowhead
		
		glVertex2d(centre.x + height / 2, centre.y);
		glVertex2d((centre.x + height / 2)-height/headRatio, centre.y+height/headRatio);
		glVertex2d((centre.x + height / 2)-height/headRatio, centre.y-height/headRatio);
		
		glEnd();
		break;
	case BACKWARD:
		glBegin(GL_QUADS);//back of arrow

		glVertex2d(centre.x - height / 2+height/headRatio, centre.y + width / 2);
		glVertex2d(centre.x - height / 2+height/headRatio, centre.y - width / 2);
		glVertex2d(centre.x + height / 2, centre.y - width / 2);
		glVertex2d(centre.x + height / 2, centre.y + width / 2);
		glEnd();

		glBegin(GL_TRIANGLES);//arrowhead

		glVertex2d(centre.x - height / 2, centre.y);
		glVertex2d((centre.x - height / 2) + height/headRatio, centre.y + height/headRatio);
		glVertex2d((centre.x - height / 2) + height/headRatio, centre.y - height/headRatio);

		glEnd();
		break;
	case UPWARD:
		glBegin(GL_QUADS);//back of arrow

		glVertex2d(centre.x - width / 2, centre.y - height / 2);
		glVertex2d(centre.x + width / 2, centre.y - height/ 2);
		glVertex2d(centre.x - width / 2, centre.y + height / 2-height/headRatio);
		glVertex2d(centre.x + width / 2, centre.y + height / 2-height/headRatio);
		glEnd();

		glBegin(GL_TRIANGLES);//arrowhead

		glVertex2d(centre.x, centre.y+height/2);
		glVertex2d(centre.x - height/headRatio, centre.y+height/2 - height/headRatio);
		glVertex2d(centre.x + height/headRatio, centre.y+height/2 - height/headRatio);

		glEnd();
		break;
	case DOWNWARD:
		glBegin(GL_QUADS);//back of arrow

		glVertex2d(centre.x - width / 2, centre.y - height / 2+height/headRatio);
		glVertex2d(centre.x + width / 2, centre.y - height / 2+height/headRatio);
		glVertex2d(centre.x - width / 2, centre.y + height / 2 );
		glVertex2d(centre.x + width / 2, centre.y + height / 2 );
		glEnd();

		glBegin(GL_TRIANGLES);//arrowhead

		glVertex2d(centre.x, centre.y - height / 2);
		glVertex2d(centre.x - height/headRatio, centre.y - height / 2 + height/headRatio);
		glVertex2d(centre.x + height/headRatio, centre.y - height / 2 + height/headRatio);

		glEnd();
		break;

	}
}
