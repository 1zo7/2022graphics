#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <GL/glut.h>
#include <stdio.h>
#include "glm.h"

GLMmodel * pmodel = NULL;
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * Larm = NULL;
GLMmodel * Rarm = NULL;
GLMmodel * Lhand = NULL;
GLMmodel * Rhand = NULL;
GLMmodel * Lleg = NULL;
GLMmodel * Rleg = NULL;
GLMmodel * Lfoot = NULL;
GLMmodel * Rfoot = NULL;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


float angle[20], oldX=0;
int angleID=0; ///0:第0個關節，1:第一個關節，2:第二個關節
FILE * fout = NULL, * fin = NULL;


void myWrite()
{
    if(fout==NULL) fout=fopen("file.txt", "w+");
    for(int i=0; i<20; i++){
        fprintf(fout, "%.2f", angle[i]);
    }
    printf("\n");
    fprintf(fout, "\n");
}
void myRead()
{
    if(fout!=NULL)
    {
        fclose(fout);
        fout=NULL;
    }
    if(fin==NULL) fin=fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        fscanf(fin, "%f", &angle[i]);
    }
    glutPostRedisplay();///重畫畫面
}
void keyboard(unsigned char key,int x,int y)
{
    ///printf("hollow world:%c\n",key);測試用
    if(key=='r')myRead();
    if(key=='s')myWrite();///save
    if(key=='0')angleID=0;///預設這是第一個
    if(key=='1')angleID=1;
    if(key=='2')angleID=2;
    if(key=='3')angleID=3;
    if(key=='4')angleID=4;
    if(key=='5')angleID=5;
    if(key=='6')angleID=6;
    if(key=='7')angleID=7;
    if(key=='8')angleID=8;
    if(key=='9')angleID=9;
}///用keyboard的按鍵，來決定等一下mption()裡要動哪個部位

void mouse(int button, int state , int x, int y)///mouse按下去
{
    oldX = x;
}
void motion(int x,int y)
{
    angle[angleID] += (x-oldX);
    ///myWrite();///沒必要一直寫檔
    oldX=x;
    glutPostRedisplay();
}
GLMmodel * myReadOne(char * filename)
{
    GLMmodel * one = NULL;
    if(one == NULL)
    {
        one = glmReadOBJ(filename);
        glmUnitize(one);
        glmFacetNormals(one);
        glmVertexNormals(one, 90);
    }
    return one;
}

void display()///最新的display
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(0,0.3,0);
        glRotatef(180,0,1,0);
        if(body==NULL) body= myReadOne("data/body.obj");
        glmDraw(body, GLM_SMOOTH);

        glPushMatrix();
            glTranslatef(0,0.16,0.1);
            glRotatef(angle[0],0,1,0);
            glScaled(1.9,1.9,1.9);
            if(head==NULL) head = myReadOne("data/head.obj");
            glmDraw(head, GLM_SMOOTH );
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.24,-0.14,0);
            glRotatef(angle[1],1,0,0);
            if(Rarm==NULL) Rarm= myReadOne("data/Rarm.obj");
            glmDraw(Rarm, GLM_SMOOTH);

            glPushMatrix();
                glTranslatef(0.06,-0.22,0);
                glRotatef(angle[3],0,1,0);
                glScaled(0.8,0.8,0.8);
                if(Rhand==NULL) Rhand= myReadOne("data/Rhand.obj");
                glmDraw(Rhand, GLM_SMOOTH);
            glPopMatrix();

        glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.24,-0.14,0);
            glRotatef(angle[2],1,0,0);
            if(Larm==NULL) Larm= myReadOne("data/Larm.obj");
            glmDraw(Larm, GLM_SMOOTH);

            glPushMatrix();
                glTranslatef(-0.06,-0.22,0);
                glScaled(0.8,0.8,0.8);
                glRotatef(angle[4],0,1,0);
                if(Lhand==NULL) Lhand= myReadOne("data/Lhand.obj");
                glmDraw(Lhand, GLM_SMOOTH);
            glPopMatrix();

        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.09,-0.57,0);
            glRotatef(angle[5],1,0,0);
            glScaled(0.21,0.21,0.21);
            if(Rleg==NULL) Rleg= myReadOne("data/Rleg.obj");
            glmDraw(Rleg, GLM_SMOOTH);

            glPushMatrix();
                glTranslatef(0.11,-1.35,0);
                glRotatef(angle[7],1,0,0);
                glScaled(1.78,1.78,1.78);
                if(Rfoot==NULL) Rfoot= myReadOne("data/Rfoot.obj");
                glmDraw(Rfoot, GLM_SMOOTH);
                glPopMatrix();

        glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.105 ,-0.57,0);
            glRotatef(angle[6],1,0,0);
            glScaled(0.15,0.15,0.15);
            if(Lleg==NULL) Lleg= myReadOne("data/Lleg.obj");
            glmDraw(Lleg, GLM_SMOOTH);

            glPushMatrix();
                glTranslatef(-0.13,-1.85,0);
                glRotatef(angle[8],1,0,0);
                glScaled(2.5,2.5,2.5);
                if(Lfoot==NULL) Lfoot= myReadOne("data/Lfoot.obj");
                glmDraw(Lfoot, GLM_SMOOTH);
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();

}
/*void displayNotParts()///把舊的改名
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(pmodel == NULL)
    {
        pmodel = glmReadOBJ("data/Gundam.obj");
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel,90);
    }
    glmDraw(pmodel,GLM_SMOOTH);
    glutSwapBuffers();
}
void displayOld()///把display改名
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3,0.5,-0.3,-0.2);///身體,瘦身
    glPushMatrix();///右半邊，掛的位置也改了
        glTranslatef(0.3,0.5,0);///等下要掛在0.5,0.5
        glRotatef(angle[0],0,0,1);///(2)旋轉
        glTranslatef(-0.3,-0.4,0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3,0.5,0.8,0.3);///右上手臂
        glPushMatrix();
        glTranslatef(0.8,0.4,0);///(3)把下手肘掛在關節上
        glRotatef(angle[1],0,0,1);///(2)旋轉
        glTranslatef(-0.8,-0.4,0);///(1)再畫下手肘
        glColor3f(0,1,0);///綠色的
        glRectf(0.8,0.5,1.1,0.3);///再畫右下手肘
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();///左半邊，掛的位置也改了
        glTranslatef(-0.3,0.5,0);///等下要掛在0.5,0.5
        glRotatef(angle[2],0,0,1);///(2)旋轉
        glTranslatef(+0.3,-0.4,0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(-0.3,0.5,-0.8,0.3);///左上手臂
        glPushMatrix();
        glTranslatef(-0.8,0.4,0);///(3)把下手肘掛在關節上
        glRotatef(angle[3],0,0,1);///(2)旋轉
        glTranslatef(+0.8,-0.4,0);///(1)再畫下手肘
        glColor3f(0,1,0);///綠色的
        glRectf(-0.8,0.5,-1.1,0.3);///再畫左下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
*/
void myLighting()
{
    glEnable(GL_DEPTH_TEST);///開啟3D功能
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}
int main(int argc,char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Week15 homework gundam parts2");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);

    myLighting();


    glutMainLoop();
}
