#include <iostream>
#include<fstream>
#include <cmath>
#include <gl/glut.h>
#include <ctime>
#include <windows.h>
#include <gl/gl.h>
#include <conio.h>
#include<thread>
#include<string>
using namespace std;

float Fall1 = 0;
float Fall2 = 0;
float Fall3 = 0;
float Fall4 = 0;
float Fall5 = 0;
float Fall6 = 0;
float Fall7 = 0;
float Fall8 = 0;
float Fall9 = 0;
float up = 0;
float rect1x1 = 0.1, rect1y1 = 1.2, rect1x2 = -0.1, rect1y2 = 1;
float rect2x1 = 0.1, rect2y1 = 1.2, rect2x2 = -0.1, rect2y2 = 1;
float rect3x1 = 0.1, rect3y1 = 1.2, rect3x2 = -0.1, rect3y2 = 1;
float rect4x1 = 0.1, rect4y1 = 1.2, rect4x2 = -0.1, rect4y2 = 1;
float rect5x1 = 0.1, rect5y1 = 1.2, rect5x2 = -0.1, rect5y2 = 1;
float rect6x1 = 0.1, rect6y1 = 1.2, rect6x2 = -0.1, rect6y2 = 1;
float rect7x1 = 0.1, rect7y1 = 1.2, rect7x2 = -0.1, rect7y2 = 1;
float rect8x1 = 0.1, rect8y1 = 1.2, rect8x2 = -0.1, rect8y2 = 1;
float rect9x1 = 0.1, rect9y1 = 1.2, rect9x2 = -0.1, rect9y2 = 1;
float cloudx1 = -0.65, cloudy1 = -0.85, cloudx2 = -0.95, cloudy2 = -1.1;
float scloudx1 = 0.35, scloudy1 = 0, scloudx2 = -0.35, scloudy2 = -0.45;
float menux1 = -0.2, menuy1 = 0.6, menux2 = 0.1, menuy2= 0.45 ;
float menu2x1 = -0.3, menu2y1 = 0.3, menu2x2 = 0.25, menu2y2 = 0.15;
float menu3x1 = -0.3, menu3y1 = 0.1, menu3x2 = 0.25, menu3y2 = -0.05; 
float menu4x1 = -0.3, menu4y1 = -0.09, menu4x2 = 0.25, menu4y2 = -0.2;
float menu5x1 = -0.15, menu5y1 = -0.43, menu5x2 = 0.15, menu5y2 = -0.53;
float rp1, rp2, rp3, rp4, rp5, rp6, rp7, rp8, rp9;
float R;
int R2;
float Time = 0;
float circlex=0, circley=0;
float a, b;
float m, l;
float c, d;
GLfloat radius;
bool loss=true;
int score;
int neme_ya_bata;
const wchar_t* path1 = L"C:\\Users\\USER\\Desktop\\Sounds csc271\\Twinkle-twinkle-Little-Star.wav";
const wchar_t* path2 = L"C:\\Users\\USER\\Desktop\\Sounds csc271\\fail-trombone-03.wav";
const wchar_t* path3 = L"C:\\Users\\USER\\Desktop\\Sounds csc271\\Baby Remix.wav";
string s3 = "Score: ";
int level = 1;
bool mainpage = true;
bool welcome = true;
bool levelupanimation = false;
bool instructionbool = false;
bool mute = false;
int vv1 = 0, vv2 = 0, vv3 = 0, vv4 = 0, vv5 = 0, vv6 = 0, vv7 = 0, vv8 = 0, vv9 = 0;

void reset() {
	 score = 0;
	 Time = 0;
     Fall1 = 0;
	 Fall2 = 0;
	 Fall3 = 0;
	 Fall4 = 0;
	 Fall5 = 0;
	 Fall6 = 0;
	 Fall7 = 0;
	 Fall8 = 0;
	 Fall9 = 0;
	 level = 1;
	 loss = false;
	 vv1 = 0, vv2 = 0, vv3 = 0, vv4 = 0, vv5 = 0, vv6 = 0, vv7 = 0, vv8 = 0, vv9 = 0;
	 circlex = 0;
	 circley = 0;
	R = 0;
}

void text(void* font, string s, float x, float y)
{

	unsigned int i;
	glColor3ub(255, 255,255 );
	glRasterPos2f(x, y);
	for (i = 0; i < s.length(); i++)
		glutBitmapCharacter(font, s[i]);

}

void text2(void* font, string s, float x, float y)
{

	unsigned int i;
	glColor3ub(0, 0, 255);
	glRasterPos2f(x, y);
	for (i = 0; i < s.length(); i++)
		glutBitmapCharacter(font, s[i]);

}

void text3(void* font, string s, float x, float y)
{

	unsigned int i;
	glColor3ub(0, 255, 255);
	glRasterPos2f(x, y);
	for (i = 0; i < s.length(); i++)
		glutBitmapCharacter(font, s[i]);

}

void text4(void* font, string s, float x, float y)
{

	unsigned int i;
	glColor3ub(0, 0, 255);
	glRasterPos2f(x, y);
	for (i = 0; i < s.length(); i++)
		glutBitmapCharacter(font, s[i]);

}



void timecount()
{
	up:
	
	while (welcome == true)
	{
		Sleep(500);
	}
	
		Time += 1;
	//	cout<< int(((Time * 1.55) / 100) / 60) << "min " << (fmod(((Time * 1.55) / 100), 60)) << "s"<<endl;
		Sleep(10);
		
	goto up;
}
void RANDOM()
{
here:
	while (welcome != false)
	{
		Sleep(500);

	}

		
			R2 = rand();
			R = ((R2 % 10 - 4.5) / 5.0);
			neme_ya_bata = R2 % 4000;
			Sleep(1);
			goto here;
	
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1, timer, 0);
}

void stars()
{
	glColor3ub(255,255,255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(-0.9,0.85);
	glVertex2f(-0.9,0.75);
	glEnd();
	glColor3ub(255,255,255);
	glBegin(GL_LINES);
	glVertex2f(-0.95,0.8);
	glVertex2f(-0.85,0.8);
	glEnd();
	glColor3ub(255,255,255);
	glBegin(GL_LINES);
	glVertex2f(-0.95,0.75);
	glVertex2f(-0.85,0.85);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(-0.6, 0.85);
	glVertex2f(-0.6, 0.75);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.65, 0.8);
	glVertex2f(-0.55, 0.8);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.65, 0.75);
	glVertex2f(-0.55, 0.85);
	glEnd();

	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.65, 0.65);
	glVertex2f(-0.75, 0.55);
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.75, 0.6);
	glVertex2f(-0.65, 0.6);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.7, 0.65);
	glVertex2f(-0.7, 0.55);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(-0.6, 0.85);
	glVertex2f(-0.6, 0.75);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.65, 0.8);
	glVertex2f(-0.55, 0.8);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.65, 0.75);
	glVertex2f(-0.55, 0.85);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(-0.4, 0.75);
	glVertex2f(-0.4, 0.65);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.45, 0.7);
	glVertex2f(-0.35, 0.7);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.45, 0.65);
	glVertex2f(-0.35, 0.75);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(-0.95, 0.05);
	glVertex2f(-0.85, 0.15);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.9, 0.15);
	glVertex2f(-0.9, 0.05);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.95, 0.1);
	glVertex2f(-0.85, 0.1);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(-0.95, 0.4);
	glVertex2f(-0.85, 0.4);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.9, 0.35);
	glVertex2f(-0.9, 0.45);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.95, 0.35);
	glVertex2f(-0.85, 0.45);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(-0.75, 0.3);
	glVertex2f(-0.65, 0.3);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.7, 0.35);
	glVertex2f(-0.7, 0.25);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.75, 0.25);
	glVertex2f(-0.65, 0.35);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(-0.55, 0.1);
	glVertex2f(-0.45, 0.1);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.5, 0.15);
	glVertex2f(-0.5, 0.05);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.55, 0.05);
	glVertex2f(-0.45, 0.15);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(-0.3, 0.25);
	glVertex2f(-0.3, 0.15);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.35, 0.2);
	glVertex2f(-0.25, 0.2);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.25, 0.25);
	glVertex2f(-0.35, 0.15);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(-0.2, 0.45);
	glVertex2f(-0.2, 0.35);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.25, 0.4);
	glVertex2f(-0.15, 0.4);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.15, 0.45);
	glVertex2f(-0.25, 0.35);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(-0.4, 0.75);
	glVertex2f(-0.4, 0.65);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.45, 0.7);
	glVertex2f(-0.35, 0.7);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.35, 0.75);
	glVertex2f(-0.45, 0.65);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(-0.15, 0.85);
	glVertex2f(-0.25, 0.75);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.25, 0.8);
	glVertex2f(-0.15, 0.8);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.2, 0.85);
	glVertex2f(-0.2, 0.75);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(-0.4, 0.55);
	glVertex2f(-0.4, 0.45);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.45, 0.5);
	glVertex2f(-0.35, 0.5);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(-0.35, 0.55);
	glVertex2f(-0.45, 0.45);
	glEnd();




	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(0.9, 0.85);
	glVertex2f(0.9, 0.75);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.95, 0.8);
	glVertex2f(0.85, 0.8);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.95, 0.75);
	glVertex2f(0.85, 0.85);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(0.6, 0.85);
	glVertex2f(0.6, 0.75);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.65, 0.8);
	glVertex2f(0.55, 0.8);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.65, 0.75);
	glVertex2f(0.55, 0.85);
	glEnd();

	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.65, 0.65);
	glVertex2f(0.75, 0.55);
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.75, 0.6);
	glVertex2f(0.65, 0.6);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.7, 0.65);
	glVertex2f(0.7, 0.55);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(0.6, 0.85);
	glVertex2f(0.6, 0.75);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.65, 0.8);
	glVertex2f(0.55, 0.8);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.65, 0.75);
	glVertex2f(0.55, 0.85);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(0.4, 0.75);
	glVertex2f(0.4, 0.65);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.45, 0.7);
	glVertex2f(0.35, 0.7);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.45, 0.65);
	glVertex2f(0.35, 0.75);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(0.95, 0.05);
	glVertex2f(0.85, 0.15);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.9, 0.15);
	glVertex2f(0.9, 0.05);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.95, 0.1);
	glVertex2f(0.85, 0.1);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(0.95, 0.4);
	glVertex2f(0.85, 0.4);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.9, 0.35);
	glVertex2f(0.9, 0.45);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.95, 0.35);
	glVertex2f(0.85, 0.45);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(0.75, 0.3);
	glVertex2f(0.65, 0.3);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.7, 0.35);
	glVertex2f(0.7, 0.25);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.75, 0.25);
	glVertex2f(0.65, 0.35);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(0.55, 0.1);
	glVertex2f(0.45, 0.1);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.5, 0.15);
	glVertex2f(0.5, 0.05);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.55, 0.05);
	glVertex2f(0.45, 0.15);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(0.3, 0.25);
	glVertex2f(0.3, 0.15);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.35, 0.2);
	glVertex2f(0.25, 0.2);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.25, 0.25);
	glVertex2f(0.35, 0.15);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(0.2, 0.45);
	glVertex2f(0.2, 0.35);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.25, 0.4);
	glVertex2f(0.15, 0.4);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.15, 0.45);
	glVertex2f(0.25, 0.35);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(0.4, 0.75);
	glVertex2f(0.4, 0.65);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.45, 0.7);
	glVertex2f(0.35, 0.7);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.35, 0.75);
	glVertex2f(0.45, 0.65);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(0.15, 0.85);
	glVertex2f(0.25, 0.75);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.25, 0.8);
	glVertex2f(0.15, 0.8);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.2, 0.85);
	glVertex2f(0.2, 0.75);
	glEnd();

	glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(0.4, 0.55);
	glVertex2f(0.4, 0.45);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.45, 0.5);
	glVertex2f(0.35, 0.5);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2f(0.35, 0.55);
	glVertex2f(0.45, 0.45);
	glEnd();
}


void rectangles()
{           // x1     y1              x2      y2
	glColor3f(1, 0.3f, 0.95f);
	glRectf(rect1x1 + rp1, rect1y1 + Fall1, rect1x2 + rp1, rect1y2 + Fall1);
	glColor3f(0.349f, 0.8235f, 0.83137f);
	glRectf(rect2x1 + rp2, rect2y1 + Fall2, rect2x2 + rp2, rect2y2 + Fall2);
	glColor3f(1, 0.21f, 0.95f);
	glRectf(rect3x1 + rp3, rect3y1 + Fall3, rect3x2 + rp3, rect3y2 + Fall3);
	glColor3f(1, 0.21f, 0.95f);
	glRectf(rect4x1 + rp4, rect4y1 + Fall4, rect4x2 + rp4, rect4y2 + Fall4);
	glColor3f(0.349f, 0.8235f, 0.83137f);
	glRectf(rect5x1 + rp5, rect5y1 + Fall5, rect5x2 + rp5, rect5y2 + Fall5);
	glColor3f(1,1,1);
	glRectf(rect6x1 + rp6, rect6y1 + Fall6, rect6x2 + rp6, rect6y2 + Fall6);
	glColor3f(1, 0.3f, 0.95f);
	glRectf(rect7x1 + rp7, rect7y1 + Fall7, rect7x2 + rp7, rect7y2 + Fall7);
	glColor3f(0.349f, 0.8235f, 0.83137f);
	glRectf(rect8x1 + rp8, rect8y1 + Fall8, rect8x2 + rp8, rect8y2 + Fall8);
	glColor3f(1, 0.3f, 0.95f);
	glRectf(rect9x1 + rp9, rect9y1 + Fall9, rect9x2 + rp9, rect9y2 + Fall9);

}
void tireyabata()
{
	
	while (up - 1.5 < 2) {
		
		up = up + 0.01; 
		Sleep(1);
		glutPostRedisplay();
	}
	up = 0;
	levelupanimation = false;
}


//condition for a random position for the first time lal cube
void fall1()
{
	while(true)
	{
		while (welcome != false)
		{
			Sleep(500);
		}
		/*if (loss == false)
		{
			level = level + 1;
		}*/
		while (loss != true)
		{
			if (vv1 == 0) {
				rp1 = R;
				vv1++;
			}
			if (levelupanimation) {
				rp1 = R;
				Fall1 = 0;
				while (levelupanimation)
				{

					Sleep(500);
				}
				Sleep(neme_ya_bata);
			}

			Fall1 = Fall1 - 0.01;
			glFlush();
			Sleep(10);
			if (rect1y1 + Fall1 <= -1)
			{

				rp1 = R;
				Fall1 = 0;
				Sleep(400);
				score = score + 1;
				cout << score << endl;
				Sleep(neme_ya_bata);
			}
		}
	}
}
void fall2()
{
	while(true)
	{
		while (welcome != false)
		{
			Sleep(500);
		}

		while (level < 2)
		{
			Sleep(500);
		}

		
		while (loss != true)
		{

			if (vv2 == 0) {
				rp2 = R;
				vv2++;
			}
			
			if (levelupanimation) {
				rp2 = R;
				Fall2 = 0;
				while (levelupanimation)
				{

					Sleep(500);
				}
				Sleep(neme_ya_bata);
			}
			Fall2 = Fall2 - 0.01;
			glFlush();
			Sleep(10);
			if (rect2y1 + Fall2 <= -1)
			{
				rp2 = R;
				Fall2 = 0;
				Sleep(750);
				score = score + 1;
				cout << score << endl;
				Sleep(neme_ya_bata);
			}

		}
	}
}

void fall3()
{
	while (true)
	{
		while (welcome != false)
		{
			Sleep(500);
		}

		while (level < 3)
		{
			Sleep(500);
		}


		while (loss != true)
		{

			if (vv3 == 0) {
				rp3 = R;
				vv3++;
			}

			if (levelupanimation) {
				rp3 = R;
				Fall3 = 0;
				while (levelupanimation)
				{

					Sleep(500);
				}
				Sleep(neme_ya_bata);
			}
			Fall3 = Fall3 - 0.01;
			glFlush();
			Sleep(10);
			if (rect3y1 + Fall3 <= -1)
			{
				rp3 = R;
				Fall3 = 0;
				Sleep(750);
				score = score + 1;
				cout << score << endl;
				Sleep(neme_ya_bata);
			}

		}
	}
}

void fall4()
{
	while (true)
	{
		while (welcome != false)
		{
			Sleep(500);
		}

		while (level < 4)
		{
			Sleep(500);
		}


		while (loss != true)
		{

			if (vv4 == 0) {
				rp4 = R;
				vv4++;
			}

			if (levelupanimation) {
				rp4 = R;
				Fall4 = 0;
				while (levelupanimation)
				{

					Sleep(500);
				}
				Sleep(neme_ya_bata);
			}
			Fall4 = Fall4 - 0.01;
			glFlush();
			Sleep(10);
			if (rect4y1 + Fall4 <= -1)
			{
				rp4 = R;
				Fall4 = 0;
				Sleep(750);
				score = score + 1;
				cout << score << endl;
				Sleep(neme_ya_bata);
			}

		}
	}
}

void fall5()
{
	while (true)
	{
		while (welcome != false)
		{
			Sleep(500);
		}

		while (level < 5)
		{
			Sleep(500);
		}


		while (loss != true)
		{

			if (vv5 == 0) {
				rp5 = R;
				vv5++;
			}

			if (levelupanimation) {
				rp5 = R;
				Fall5 = 0;
				while (levelupanimation)
				{

					Sleep(500);
				}
				Sleep(neme_ya_bata);
			}
			Fall5 = Fall5 - 0.01;
			glFlush();
			Sleep(10);
			if (rect5y1 + Fall5 <= -1)
			{
				rp5 = R;
				Fall5 = 0;
				Sleep(750);
				score = score + 1;
				cout << score << endl;
				Sleep(neme_ya_bata);
			}

		}
	}
}

void fall6()
{
	while (true)
	{
		while (welcome != false)
		{
			Sleep(500);
		}

		while (level < 6)
		{
			Sleep(500);
		}


		while (loss != true)
		{

			if (vv6 == 0) {
				rp6 = R;
				vv6++;
			}

			if (levelupanimation) {
				rp6 = R;
				Fall6 = 0;
				while (levelupanimation)
				{

					Sleep(500);
				}
				Sleep(neme_ya_bata);
			}
			Fall6 = Fall6 - 0.01;
			glFlush();
			Sleep(10);
			if (rect6y1 + Fall6 <= -1)
			{
				rp6 = R;
				Fall6 = 0;
				Sleep(750);
				score = score + 1;
				cout << score << endl;
				Sleep(neme_ya_bata);
			}

		}
	}
}


void fall7()
{
	while (true)
	{
		while (welcome != false)
		{
			Sleep(500);
		}

		while (level < 7)
		{
			Sleep(500);
		}


		while (loss != true)
		{

			if (vv7 == 0) {
				rp7 = R;
				vv7++;
			}

			if (levelupanimation) {
				rp7 = R;
				Fall7 = 0;
				while (levelupanimation)
				{

					Sleep(500);
				}
				Sleep(neme_ya_bata);
			}
			Fall7 = Fall7 - 0.01;
			glFlush();
			Sleep(10);
			if (rect7y1 + Fall7 <= -1)
			{
				rp7 = R;
				Fall7 = 0;
				Sleep(750);
				score = score + 1;
				cout << score << endl;
				Sleep(neme_ya_bata);
			}

		}
	}
}

void fall8()
{
	while (true)
	{
		while (welcome != false)
		{
			Sleep(500);
		}

		while (level < 8)
		{
			Sleep(500);
		}


		while (loss != true)
		{

			if (vv8 == 0) {
				rp8 = R;
				vv8++;
			}

			if (levelupanimation) {
				rp8 = R;
				Fall8 = 0;
				while (levelupanimation)
				{

					Sleep(500);
				}
				Sleep(neme_ya_bata);
			}
			Fall8 = Fall8 - 0.01;
			glFlush();
			Sleep(10);
			if (rect8y1 + Fall8 <= -1)
			{
				rp8 = R;
				Fall8 = 0;
				Sleep(750);
				score = score + 1;
				cout << score << endl;
				Sleep(neme_ya_bata);
			}

		}
	}
}

void fall9()
{
	while (true)
	{
		while (welcome != false)
		{
			Sleep(500);
		}

		while (level < 9)
		{
			Sleep(500);
		}


		while (loss != true)
		{

			if (vv9 == 0) {
				rp9 = R;
				vv9++;
			}

			if (levelupanimation) {
				rp9 = R;
				Fall9 = 0;
				while (levelupanimation)
				{

					Sleep(500);
				}
				Sleep(neme_ya_bata);
			}
			Fall9 = Fall9 - 0.01;
			glFlush();
			Sleep(10);
			if (rect9y1 + Fall9 <= -1)
			{
				rp9 = R;
				Fall9 = 0;
				Sleep(750);
				score = score + 1;
				cout << score << endl;
				Sleep(neme_ya_bata);
			}

		}
	}
}

void levelup()
{
	while (true)
	{
	up:
		while (loss == true)
		{
			Sleep(500);
		}
		{
			//cout << "level " << level << endl;
			while (((Time * 1.55) / 100) < 15)
			{
				Sleep(500);
				if (loss == true) {
					goto up;
				}
			}
			if (loss == false)
			{

				levelupanimation = true;
				tireyabata();
			}
			level += 1;
			while (((Time * 1.55) / 100) < 40)
			{
				Sleep(500);
				if (loss == true) {
					goto up;
				}
			}
		
			if (loss == false)
			{

				levelupanimation = true;
				tireyabata();
			}
			level += 1;
			while (((Time * 1.55) / 100) < 60)
			{
				Sleep(500);
				if (loss == true) {
					goto up;
				}
			}
			
			if (loss == false)
			{

				levelupanimation = true;
				tireyabata();
			}
			level += 1;
			while (((Time * 1.55) / 100) < 80)
			{
				Sleep(500); if (loss == true) {
					goto up;
				}
			}
			
			if (loss == false)
			{

				levelupanimation = true;
				tireyabata();
			}
			level += 1;
			while (((Time * 1.55) / 100) < 100)
			{
				Sleep(500);
				if (loss == true) {
					goto up;
				}
			}
			
			if (loss == false)
			{

				levelupanimation = true;
				tireyabata();
			}
			level += 1;
			while (((Time * 1.55) / 100) < 130)
			{
				Sleep(500);
				if (loss == true) {
					goto up;
				}
			}
			
			if (loss == false)
			{

				levelupanimation = true;
				tireyabata();
			}
			level += 1;
			while (((Time * 1.55) / 100) < 150)
			{
				Sleep(500);
				if (loss == true) {
					goto up;
				}
			}
			
			if (loss == false)
			{

				levelupanimation = true;
				tireyabata();
			}
			level += 1;
			while (((Time * 1.55) / 100) < 180)
			{
				Sleep(500); if (loss == true) {
					goto up;
				}
			}
		
			if (loss == false)
			{

				levelupanimation = true;
				tireyabata();
			}
			level += 1;
			while (loss == false) { Sleep(500); }
		}
	}
}

void smiley()
{
	float j;
	float PI = 3.1416;

	
	int triangleAmount = 40;
	GLfloat twicePi = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,0);
	a = 0.5+circlex ; b =-0.9+circley ; radius = 0.09;
	twicePi = 2.0 * PI;
	glVertex2f(a, b); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			a + (radius * cos(j * twicePi / triangleAmount)),
			b + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();

	glColor3ub(1, 1, 1);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(0.47+circlex,-0.87+circley);
	glVertex2f(0.43+circlex,-0.87 + circley);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(0.52 + circlex, -0.87 + circley);
	glVertex2f(0.56 + circlex, -0.87 + circley);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(0.47 + circlex, -0.94 + circley);
	glVertex2f(0.52 + circlex, -0.94 + circley);
	glEnd();
}


void clouds()
{
	glPushMatrix();
	glTranslatef(0, 0, 0);
	float j;
	float PI = 3.1416;


	int triangleAmount = 40;
	GLfloat twicePi = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.95; l = -0.9; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();


	int triangleAmount2 = 40;
	GLfloat twicePi2 = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.65; l = -0.9; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();

	int triangleAmount3 = 40;
	GLfloat twicePi3 = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.8; l = -0.8; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();

	glColor3f(255, 255, 255);
	glRectf(cloudx1, cloudy1, cloudx2, cloudy2);
	glPopMatrix();
}

void clouds2()
{
	glPushMatrix();
	glTranslatef(0.9, 0, 0);
	float j;
	float PI = 3.1416;


	int triangleAmount = 40;
	GLfloat twicePi = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.95; l = -0.9; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();


	int triangleAmount2 = 40;
	GLfloat twicePi2 = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.65; l = -0.9; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();

	int triangleAmount3 = 40;
	GLfloat twicePi3 = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.8; l = -0.8; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();

	glColor3f(255, 255, 255);
	glRectf(cloudx1, cloudy1, cloudx2, cloudy2);
	glPopMatrix();
}

void clouds3()
{
	glPushMatrix();
	glTranslatef(1.35, 0, 0);
	float j;
	float PI = 3.1416;


	int triangleAmount = 40;
	GLfloat twicePi = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.95; l = -0.9; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();


	int triangleAmount2 = 40;
	GLfloat twicePi2 = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.65; l = -0.9; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();

	int triangleAmount3 = 40;
	GLfloat twicePi3 = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.8; l = -0.8; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();

	glColor3f(255, 255, 255);
	glRectf(cloudx1, cloudy1, cloudx2, cloudy2);
	glPopMatrix();
}

void clouds4()
{
	glPushMatrix();
	glTranslatef(0.45, 0, 0);
	float j;
	float PI = 3.1416;


	int triangleAmount = 40;
	GLfloat twicePi = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.95; l = -0.9; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();


	int triangleAmount2 = 40;
	GLfloat twicePi2 = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.65; l = -0.9; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();

	int triangleAmount3 = 40;
	GLfloat twicePi3 = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.8; l = -0.8; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();

	glColor3f(255, 255, 255);
	glRectf(cloudx1, cloudy1, cloudx2, cloudy2);
	glPopMatrix();
}

void clouds5()
{
	glPushMatrix();
	glTranslatef(1.8, 0, 0);
	float j;
	float PI = 3.1416;


	int triangleAmount = 40;
	GLfloat twicePi = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.95; l = -0.9; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();


	int triangleAmount2 = 40;
	GLfloat twicePi2 = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.65; l = -0.9; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();

	int triangleAmount3 = 40;
	GLfloat twicePi3 = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	m = -0.8; l = -0.8; radius = 0.1;
	twicePi = 2.0 * PI;
	glVertex2f(m, l); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			m + (radius * cos(j * twicePi / triangleAmount)),
			l + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();

	glColor3f(255, 255, 255);
	glRectf(cloudx1, cloudy1, cloudx2, cloudy2);
	glPopMatrix();
}



void levelcloud()
{

glPushMatrix();
glTranslatef(0, up - 1.5, 0);
{float a1, b1, j1;
float PI = 3.1416;

GLfloat radius;
int triangleAmount = 40;
GLfloat twicePi = 2.0 * PI;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(255, 255, 255);
a1 = 0; b1 = 0; radius = 0.3;
twicePi = 2.0 * PI;
glVertex2f(a1, b1); // center of circle
for (j1 = 0; j1 <= triangleAmount; j1++)
{
	glVertex2f(
		a1 + (radius * cos(j1 * twicePi / triangleAmount)),
		b1 + (radius * sin(j1 * twicePi / triangleAmount))
	);
}
glEnd(); }

{float a1, b1, j1;
float PI = 3.1416;

GLfloat radius;
int triangleAmount = 40;
GLfloat twicePi = 2.0 * PI;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(255, 255, 255);
a1 = 0.4; b1 = -0.15; radius = 0.3;
twicePi = 2.0 * PI;
glVertex2f(a1, b1); // center of circle
for (j1 = 0; j1 <= triangleAmount; j1++)
{
	glVertex2f(
		a1 + (radius * cos(j1 * twicePi / triangleAmount)),
		b1 + (radius * sin(j1 * twicePi / triangleAmount))
	);
}
glEnd(); }

{float a1, b1, j1;
float PI = 3.1416;

GLfloat radius;
int triangleAmount = 40;
GLfloat twicePi = 2.0 * PI;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(255, 255, 255);
a1 = -0.4; b1 = -0.15; radius = 0.3;
twicePi = 2.0 * PI;
glVertex2f(a1, b1); // center of circle
for (j1 = 0; j1 <= triangleAmount; j1++)
{
	glVertex2f(
		a1 + (radius * cos(j1 * twicePi / triangleAmount)),
		b1 + (radius * sin(j1 * twicePi / triangleAmount))
	);
}
glEnd(); }

glColor3f(255, 255, 255);
glRectf(scloudx1, scloudy1, scloudx2, scloudy2);


text3(GLUT_BITMAP_TIMES_ROMAN_24, "LEVELED UP!", -0.2, -0.15);
glPopMatrix();

}

//" PLAY ", -0.15, 0.5);
//" LEADERBOARD ", -0.3, 0.2);
//" INSTRUCTIONS ", -0.3, 0);
//" SOUND: ON  ", -0.25, -0.17);
//" SOUND: OFF ", -0.25, -0.17);
//"QUIT ", -0.1, -0.5);

void display();
void instructions();

void MOUSE(int button, int state, int x, int y)
{
	//GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, or GLUT_RIGHT_BUTTON
	//GLUT_UP or GLUT_DOWN
	float mainX = (x / 350.0) - 1;
	float mainY = (-y / 350.0) + 1;

	if (instructionbool == false&&welcome==true) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if ((mainX >= -0.2) && (mainX <= 0.1) && (mainY <= 0.6) && (mainY >= 0.45))
			{
				reset();
				welcome = false;
				glutDisplayFunc(display);
				cout << "click";
				glutPostRedisplay();
			}

			if ((mainX >= -0.3) && (mainX <= 0.25) && (mainY <= 0.1) && (mainY >= -0.05))
			{
				//welcome = false;
				instructionbool = true;
				glutDisplayFunc(instructions);
				glutPostRedisplay();
			}
			if ((menu4x2 >= mainX) && (mainX >= menu4x1) && (menu4y2 <= mainY) && (mainY <= menu4y1)) {
				mute = !mute;
				cout << "\nclick " << mute << endl;
			}
			if ((menu5x2 >= mainX) && (mainX >= menu5x1) && (menu5y2 <= mainY) && (mainY <= menu5y1)) {
				exit(0);
				
			}
		}
		cout << mainX << "     " << mainY << endl;
		glutPostRedisplay();
	}
}

void menukeys(unsigned char key, int x, int y) {
	
		if (key ==27 && welcome==true && instructionbool==false) {
			exit(0);
		}
	
}

void keys(int key, int x, int y)
{
	if (loss != true)
	{
		switch (key)
		{
			
		case GLUT_KEY_RIGHT:
			if (circlex < 0.4)
			{
				circlex = circlex + 0.05;
			}

			break;
		case GLUT_KEY_LEFT:
			if (circlex > -1.35)
			{
				circlex = circlex - 0.05;
			}
			break;
		case GLUT_KEY_UP:
			if (circley < 1.75)
			{
				circley = circley + 0.05;
			}
			break;
		case GLUT_KEY_DOWN:
			if (circley > 0.04)
			{
				circley = circley - 0.05;
			}
			break;
		}

	}
	
}
void welcomeDisplay();
void instkeys(unsigned char key, int x, int y) {
	if (key == 27&&instructionbool==true) {
		instructionbool = false;
		glutDisplayFunc(welcomeDisplay);
		
		glutPostRedisplay();
	}
}

void menu()
{
	float j;
	float PI = 3.1416;


	int triangleAmount = 40;
	GLfloat twicePi = 2.0 * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255, 255, 255);
	c = 0 ; d = 0; radius = 0.7;
	twicePi = 2.0 * PI;
	glVertex2f(c, d); // center of circle
	for (j = 0; j <= triangleAmount; j++)
	{
		glVertex2f(
			c + (radius * cos(j * twicePi / triangleAmount)),
			d + (radius * sin(j * twicePi / triangleAmount))
		);
	}
	glEnd();


	if (instructionbool != true)
	{
		glColor3f(255, 255, 255);
		glRectf(menux1, menuy1, menux2, menuy2);



		glColor3f(255, 255, 255);
		glRectf(menu3x1, menu3y1, menu3x2, menu3y2);

		glColor3f(255, 255, 255);
		glRectf(menu4x1, menu4y1, menu4x2, menu4y2);

		glColor3f(255, 255, 255);
		glRectf(menu5x1, menu5y1, menu5x2, menu5y2);
	}
	glutKeyboardFunc(menukeys);
}
void dispkeys(unsigned char key, int x, int y) {

	if (key==27) {
		loss = true;
		welcome = true;
		glutDisplayFunc(menu);
		glutPostRedisplay();
	}

}

void display()
{
	glClearColor(0, 0, 0.2f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
//welcomeDisplay();
	text(GLUT_BITMAP_HELVETICA_18, "Score: "+to_string(score), -0.2, 0.9);
	text(GLUT_BITMAP_HELVETICA_18, "Time: "+to_string( int(((Time * 1.55) / 100) / 60))+" min " + to_string(int(fmod(((Time * 1.55) / 100), 60))) + " sec", 0.4, 0.9);
	text(GLUT_BITMAP_HELVETICA_18, "Level: "+to_string(level), -0.9, 0.9);
	clouds();
	clouds2();
	clouds3();
	clouds4();
	clouds5();;
	stars();
	rectangles();
	smiley();
	levelcloud();
	glutSpecialFunc(keys);
	glutKeyboardFunc(dispkeys);
	glFlush();//zhare bhal meena
}
void welcomeDisplay()
{
	glClearColor(0, 0, 0.2f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glRasterPos3f(0, 0, 0);
	clouds();
	clouds2();
	clouds3();
	clouds4();
	clouds5();
	stars();
	menu();
	text2(GLUT_BITMAP_TIMES_ROMAN_24, " PLAY ", -0.15, 0.5);
	text2(GLUT_BITMAP_TIMES_ROMAN_24, " INSTRUCTIONS ", -0.3, 0);
	
	if (mute == false) { text2(GLUT_BITMAP_TIMES_ROMAN_24, " SOUND: ON  ", -0.25, -0.17); }
	else { text2(GLUT_BITMAP_TIMES_ROMAN_24, " SOUND: OFF ", -0.25, -0.17); }
	text2(GLUT_BITMAP_TIMES_ROMAN_24, "QUIT ", -0.1, -0.5);
	//glutMouseFunc();
	glFlush();
	
	glutMouseFunc(MOUSE);
	
	glutPostRedisplay();
}
void instructions()
{
	glClearColor(0, 0, 0.2f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glRasterPos3f(0, 0, 0);
	clouds();
	clouds2();
	clouds3();
	clouds4();
	clouds5();
	stars();
	menu();
	text4(GLUT_BITMAP_TIMES_ROMAN_24, " BUDDY is sleepy! ", -0.3, 0.4);
	text4(GLUT_BITMAP_TIMES_ROMAN_24, " Using the arrows keys,  ", -0.35, 0.2);
	text4(GLUT_BITMAP_TIMES_ROMAN_24, "help BUDDY avoid the bad nightmares. ", -0.5, 0);
	text4(GLUT_BITMAP_TIMES_ROMAN_24, " Then try beating the highscore for a surprise! ", -0.65, -0.2);
	text4(GLUT_BITMAP_HELVETICA_18, " Dear parents there's no actual highscore. ", -0.5, -0.3);
	text4(GLUT_BITMAP_HELVETICA_18, " It's a tricky game for your kids to sleep faster.  ", -0.55, -0.4);
	//glutMouseFunc();
	glFlush();
	glutKeyboardFunc(instkeys);
	glutMouseFunc(MOUSE);
	glutPostRedisplay();
}
void gameOver()
{
	up:
	while (welcome != false)
	{
		Sleep(500);
	}
	while (loss != true) {

		if ((((a + radius) < (rect1x1 + rp1)) && ((a + radius) > (rect1x2 + rp1)) && ((b + radius) <= (rect1y1 + Fall1)) && ((b + radius) > (rect1y2 + Fall1))) || (((a + radius) < (rect1x1 + rp1)) && ((a + radius) > (rect1x2 + rp1)) && ((b - radius) < (rect1y1 + Fall1)) && ((b - radius) > (rect1y2 + Fall1))) || (((a - radius) < (rect1x1 + rp1)) && ((a - radius) > (rect1x2 + rp1)) && ((b + radius) < (rect1y1 + Fall1)) && ((b + radius) > (rect1y2 + Fall1))) || (((a - radius) < (rect1x1 + rp1)) && ((a - radius) > (rect1x2 + rp1)) && ((b - radius) < (rect1y1 + Fall1)) && ((b - radius) > (rect1y2 + Fall1))))
		{
			cout << "Game over1!!!";
			loss = true;
			path2;
			if(mute==false)
			PlaySound(path2, NULL, SND_FILENAME | SND_ASYNC | NULL);
		}
		if ((((a + radius) < (rect2x1 + rp2)) && ((a + radius) > (rect2x2 + rp2)) && ((b + radius) < (rect2y1 + Fall2)) && ((b + radius) > (rect2y2 + Fall2))) || (((a + radius) < (rect2x1 + rp2)) && ((a + radius) > (rect2x2 + rp2)) && ((b - radius) < (rect2y1 + Fall2)) && ((b - radius) > (rect2y2 + Fall2))) || (((a - radius) < (rect2x1 + rp2)) && ((a - radius) > (rect2x2 + rp2)) && ((b + radius) < (rect2y1 + Fall2)) && ((b + radius) > (rect2y2 + Fall2))) || (((a - radius) < (rect2x1 + rp2)) && ((a - radius) > (rect2x2 + rp2)) && ((b - radius) < (rect2y1 + Fall2)) && ((b - radius) > (rect2y2 + Fall2))))
		{
			cout << "Game over2!!!";
			loss = true;
			path2;
			if (mute == false)
			PlaySound(path2, NULL, SND_FILENAME | SND_ASYNC | NULL);
		}
		if ((((a + radius) < (rect3x1 + rp3)) && ((a + radius) > (rect3x2 + rp3)) && ((b + radius) < (rect3y1 + Fall3)) && ((b + radius) > (rect3y2 + Fall3))) || (((a + radius) < (rect3x1 + rp3)) && ((a + radius) > (rect3x2 + rp3)) && ((b - radius) < (rect3y1 + Fall3)) && ((b - radius) >= (rect3y2 + Fall3))) || (((a - radius) < (rect3x1 + rp3)) && ((a - radius) > (rect3x2 + rp3)) && ((b + radius) < (rect3y1 + Fall3)) && ((b + radius) > (rect3y2 + Fall3))) || (((a - radius) < (rect3x1 + rp3)) && ((a - radius) > (rect3x2 + rp3)) && ((b - radius) < (rect3y1 + Fall3)) && ((b - radius) > (rect3y2 + Fall3))))
		{
			cout << "Game over3!!!";
			loss = true;
			path2;
			if (mute == false)
			PlaySound(path2, NULL, SND_FILENAME | SND_ASYNC | NULL);
		}
		if ((((a + radius) < (rect4x1 + rp4)) && ((a + radius) > (rect4x2 + rp4)) && ((b + radius) < (rect4y1 + Fall4)) && ((b + radius) > (rect4y2 + Fall4))) || (((a + radius) < (rect4x1 + rp4)) && ((a + radius) > (rect4x2 + rp4)) && ((b - radius) < (rect4y1 + Fall4)) && ((b - radius) > (rect4y2 + Fall4))) || (((a - radius) < (rect4x1 + rp4)) && ((a - radius) > (rect4x2 + rp4)) && ((b + radius) < (rect4y1 + Fall4)) && ((b + radius) > (rect4y2 + Fall4))) || (((a - radius) < (rect4x1 + rp4)) && ((a - radius) > (rect4x2 + rp4)) && ((b - radius) < (rect4y1 + Fall4)) && ((b - radius) > (rect4y2 + Fall4))))
		{
			cout << "Game over4!!!";
			loss = true;
			path2;
			if (mute == false)
			PlaySound(path2, NULL, SND_FILENAME | SND_ASYNC | NULL);
		}
		if ((((a + radius) < (rect5x1 + rp5)) && ((a + radius) > (rect5x2 + rp5)) && ((b + radius) < (rect5y1 + Fall5)) && ((b + radius) > (rect5y2 + Fall5))) || (((a + radius) < (rect5x1 + rp5)) && ((a + radius) > (rect5x2 + rp5)) && ((b - radius) < (rect5y1 + Fall5)) && ((b - radius) > (rect5y2 + Fall5))) || (((a - radius) < (rect5x1 + rp5)) && ((a - radius) > (rect5x2 + rp5)) && ((b + radius) < (rect5y1 + Fall5)) && ((b + radius) > (rect5y2 + Fall5))) || (((a - radius) < (rect5x1 + rp5)) && ((a - radius) > (rect5x2 + rp5)) && ((b - radius) < (rect5y1 + Fall5)) && ((b - radius) > (rect5y2 + Fall5))))
		{
			cout << "Game over5!!!";
			loss = true;
			path2;
			if (mute == false)
			PlaySound(path2, NULL, SND_FILENAME | SND_ASYNC | NULL);
		}
		if (loss) {
			welcome = true;
			glutDisplayFunc(welcomeDisplay);
			glutPostRedisplay();
		}
		//if (loss == true) { welcome = true; Fall1 = 0; Fall2 = 0; loss = false; Time = 0; score = 0;level=0 ; glutDisplayFunc(welcomeDisplay); glutPostRedisplay(); }
	}goto up;
}
void Play_sound()
{
	up:
	while (loss == true||mute)	{Sleep(500);}
	if (mute == false&&welcome==false) {
		PlaySound(path1, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	while (mute == false&&welcome==false) { Sleep(500); }
	if (mute == true) {
		PlaySound(NULL, NULL, NULL);
	}

		while (loss!=true)
		{
			Sleep(2000);
		}
	goto up;
}
/*
face	top=b+radius		    bot=b-radius		    left=a-radius		    right=a+radius
rect1	top= rect1y1 + Fall1	bot= rect1y2 + Fall1 	left=rect1x2 + rp1		right=rect1x1 + rp1	
rect2	top=rect2y1 + Fall2 	bot=rect2y2 + Fall2	    left=rect2x2 + rp2		right=rect2x1 + rp2	
rect3	top=rect3y1 + Fall3		bot=rect3y2 + Fall3 	left=rect3x2 + rp3		right=rect3x1 + rp3
*/


int main(int argc, char** argv) {
	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(350, 0);
	glutInitWindowSize(700,700);
	glutCreateWindow("Sleeping Buddy");
	glutDisplayFunc(welcomeDisplay);
	thread random(RANDOM);
	thread f1(fall1);
	thread f2(fall2);
	thread f3(fall3);
	thread f4(fall4);
	thread f5(fall5);
	thread f6(fall6);
	thread f7(fall7);
	thread f8(fall8);
	thread f9(fall9);
	thread over(gameOver);
	thread Time (timecount);
	thread playsound(Play_sound);
	thread LEVELUP(levelup);
	
		
	
	
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}
