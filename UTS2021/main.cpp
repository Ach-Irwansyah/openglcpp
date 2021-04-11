#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include<iostream>

using namespace std;

float posX = 0.0;
float posY = 0.0;
float sx = 0.0;
float sy = 0.0;
float ra = 0.0;
int warna =1;
void abu(int r, int g, int b){
    //abu2
    glBegin(GL_POLYGON);
        glColor3ub(r,g,b);
        glVertex2f(0+posX,7.1+posY);
        glVertex2f(-6+posX,4.1+posY);
        glVertex2f(-6+posX,5+posY);
        glVertex2f(0+posX,8+posY);
        glVertex2f(6+posX,5+posY);
        glVertex2f(6+posX,4.1+posY);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-6+posX,3.1+posY);
        glVertex2f(-5.2+posX,3.5+posY);
        glVertex2f(-5.2+posX,-1.45+posY);
        glVertex2f(-6+posX,-1.05+posY);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(6+posX,3.1+posY);
        glVertex2f(5.2+posX,3.5+posY);
        glVertex2f(5.2+posX,-1.45+posY);
        glVertex2f(6+posX,-1.05+posY);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(-4.4+posX,3.9+posY);
        glVertex2f(-3.6+posX,4.3+posY);
        glVertex2f(-3.6+posX,-2.29+posY);
        glVertex2f(-4.4+posX,-1.89+posY);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(4.4+posX,3.9+posY);
        glVertex2f(3.6+posX,4.3+posY);
        glVertex2f(3.6+posX,-2.29+posY);
        glVertex2f(4.4+posX,-1.89+posY);
    glEnd();
}
void merah(int r, int g, int b){
    //merah
    glBegin(GL_POLYGON);
        glColor3ub(r,g,b);
        glVertex2f(-2.8+posX,4.71+posY);
        glVertex2f(-2+posX,5.11+posY);
        glVertex2f(-2+posX,-3.1+posY);
        glVertex2f(-2.8+posX,-2.7+posY);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-2+posX,0.7+posY);
        glVertex2f(-2+posX,1.22+posY);
        glVertex2f(0.4+posX,1.22+posY);
        glVertex2f(0.4+posX,0.7+posY);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.4+posX,2.89+posY);
        glVertex2f(1.2+posX,2.89+posY);
        glVertex2f(1.2+posX,-3.495+posY);
        glVertex2f(0.4+posX,-3.9+posY);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.4+posX,3.91+posY);
        glVertex2f(0.4+posX,5.92+posY);
        glVertex2f(1.2+posX,5.53+posY);
        glVertex2f(1.2+posX,3.91+posY);
    glEnd();
}
void oren(int r, int g, int b){
    //oren
    glBegin(GL_POLYGON);
        glColor3ub(r,g,b);
        glVertex2f(-1.2+posX,-3.495+posY);
        glVertex2f(-1.2+posX,0.45+posY);
        glVertex2f(-0.4+posX,0.45+posY);
        glVertex2f(-0.4+posX,-3.9+posY);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-1.2+posX,1.5+posY);
        glVertex2f(-1.2+posX,5.515+posY);
        glVertex2f(-0.4+posX,5.93+posY);
        glVertex2f(-0.4+posX,1.5+posY);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.4+posX,3.14+posY);
        glVertex2f(-0.4+posX,3.695+posY);
        glVertex2f(2+posX,3.695+posY);
        glVertex2f(2+posX,3.14+posY);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(2+posX,-3.1+posY);
        glVertex2f(2+posX,5.11+posY);
        glVertex2f(2.795+posX,4.71+posY);
        glVertex2f(2.795+posX,-2.7+posY);
    glEnd();
}
void display(){
    //gunakan wasd dan fgvb untuk pindah posisi
    //gunakan r untuk random warna
    //gunakan zx untuk rotasi
    //gunakan opklnm untuk skala
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
    glScaled(1+sx,1+sy,0);
    glRotated(ra,0,0,1);
    abu(96*warna,97*warna,97*warna);
    merah(167*warna,30*warna,34*warna);
    oren(165*warna,90*warna,38*warna);
    glPopMatrix();
	glFlush();
}

void inputan(unsigned char key, int x, int y){

    //warna
    if(key == 'r' || key == 'R'){
        warna=rand()%256;
        cout<<"warna acak:"<<warna<<endl;
        display();
    }

    //posisi x dan y
    if(key == 'd' || key == 'D'){
        posX += 0.2;
        cout << "posisi X ="<< posX << endl;
        display();
    }
    if(key == 'a' || key == 'A'){
        posX -= 0.2;
        cout << "posisi X ="<< posX << endl;
        display();
    }
    if(key == 'w' || key == 'W'){
        posY += 0.2;
        cout << "posisi Y ="<< posY << endl;
        display();
        }
    if(key == 's' || key == 'S'){
        posY -= 0.2;
        cout << "posisi Y ="<< posY << endl;
        display();
    }

    //posisi XY
    if(key == 'g' || key == 'G'){
        posY += 0.2;
        posX += 0.2;
        cout << "posisi XY ="<<posX;
        cout <<", "<<posY<< endl;
        display();
    }
    if(key == 'v' || key == 'V'){
        posY -= 0.2;
        posX -= 0.2;
        cout << "posisi XY ="<<posX;
        cout <<", "<<posY<< endl;
        display();
    }
    if(key == 'b' || key == 'B'){
        posY -= 0.2;
        posX += 0.2;
        cout << "posisi XY ="<<posX;
        cout <<", "<<posY<< endl;
        display();
    }
    if(key == 'f' || key == 'F'){
        posY += 0.2;
        posX -= 0.2;
        cout << "posisi XY ="<<posX;
        cout <<", "<<posY<< endl;
        display();
    }

    //scale
    if(key == 'o' || key == 'O'){
        sx -= 0.2;
        cout << "scale ="<< sx << endl;
        display();
    }
    if(key == 'p' || key == 'P'){
        sx += 0.2;
        cout << "scale ="<< sx << endl;
        display();
    }

    if(key == 'k' || key == 'K'){
        sy -= 0.2;
        cout << "scale ="<< sy << endl;
        display();
    }
    if(key == 'l' || key == 'L'){
        sy += 0.2;
        cout << "scale ="<< sy << endl;
        display();
    }

    if(key == 'n' || key == 'N'){
        sx -= 0.1;
        sy -= 0.1;
        cout << "scale ="<< sx;
        cout <<", "<<sy<< endl;
        display();
    }
    if(key == 'm' || key == 'M'){
        sx += 0.1;
        sy += 0.1;
        cout << "scale ="<< sx;
        cout <<", "<<sy<< endl;
        display();
    }


    if(key == 'z' || key == 'Z'){
        ra -= 1;
        cout << "rotate ="<< ra << endl;
        display();
    }
    if(key == 'x' || key == 'X'){
        ra += 1;
        cout << "rotate ="<< ra << endl;
        display();
    }
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0,10.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,1.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700,700);
	//glutInitWindowPosition(100,100);
	glutCreateWindow("Logo");
	glutDisplayFunc(display);
	glutKeyboardFunc(inputan);
	myinit();
	glutMainLoop();

	return 0;
}
