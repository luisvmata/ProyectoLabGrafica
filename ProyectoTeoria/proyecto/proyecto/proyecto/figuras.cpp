#include "figuras.h"


const double PI = 3.1415926535897;
float text_der = 1.0;
float text_izq = 0.0;

void CFiguras::skybox(float largo, float altura, float profundidad, GLuint text, GLuint text2)  //Funcion creacion cielo
{

	GLfloat vertice [8][3] = {
				{0.5*largo ,-0.5*altura, 0.5*profundidad},    //Coordenadas Vértice 1 V1
				{-0.5*largo ,-0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 2 V2
				{-0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 3 V3
				{0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 4 V4
				{0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 5 V5
				{0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 6 V6
				{-0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 7 V7
				{-0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 8 V8
				};

		glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);		//0,0
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);		//0,1
			glTexCoord2f(0.75f, 1.0f); glVertex3fv(vertice[7]);		//1,1
			glTexCoord2f(0.75f, 0.0f); glVertex3fv(vertice[1]);		//1,0
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);		//0,0	
			glTexCoord2f(0.25f, 0.0f); glVertex3fv(vertice[3]);		//1,0
			glTexCoord2f(0.25f, 1.0f); glVertex3fv(vertice[5]);		//1,1
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);		//0,1 se giro
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,1.0f);
			glTexCoord2f(0.5f, 1.0f); glVertex3fv(vertice[6]);		//0,1
			glTexCoord2f(0.25f, 1.0f); glVertex3fv(vertice[5]);		//1,1
			glTexCoord2f(0.25f, 0.0f); glVertex3fv(vertice[3]);		//1,0
			glTexCoord2f(0.5f, 0.0f); glVertex3fv(vertice[2]);		//0,0 
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.75f, 0.0f); glVertex3fv(vertice[1]);		//1,0
			glTexCoord2f(0.75f, 1.0f); glVertex3fv(vertice[7]);		//1,1
			glTexCoord2f(0.5f, 1.0f); glVertex3fv(vertice[6]);		//0,1
			glTexCoord2f(0.5f, 0.0f); glVertex3fv(vertice[2]);		//0,0 se giro 
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text2);
		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
        	glVertex3fv(vertice[7]);
		glEnd();
}

void CFiguras::skybox2 (float altura, float largo, float profundidad, GLuint text)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5*largo ,-0.5*altura, 0.5*profundidad},    //Coordenadas Vértice 1 V1
				{-0.5*largo ,-0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 2 V2
				{-0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 3 V3
				{0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 4 V4
				{0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 5 V5
				{0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 6 V6
				{-0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 7 V7
				{-0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 8 V8
				};

		glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(0.0f, 3.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(3.0f, 3.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(3.0f, 3.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 3.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(3.0f, 3.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 3.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();
}



void CFiguras::prisma (float altura, float largo, float profundidad, GLuint text)  //Funcion creacion prisma
{
	//Se reserva para entrada la entrada 
	GLfloat vertice [8][3] = {
				{0.5*largo ,-0.5*altura, 0.5*profundidad},    //Coordenadas Vértice 1 V1
				{-0.5*largo ,-0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 2 V2
				{-0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 3 V3
				{0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 4 V4
				{0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 5 V5
				{0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 6 V6
				{-0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 7 V7
				{-0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 8 V8
				};

		glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);		//0
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);		//4
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);		//7
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);		//1
		glEnd();

		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);		//4
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[6]);		//5
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);		//6
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);		//7
		glEnd();
		
}

void CFiguras::prisma2 (GLuint text, GLuint text2)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		
		glBindTexture(GL_TEXTURE_2D, text2);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
		glEnd();
	
		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f,1.0f, 0.0f);
			glTexCoord2f(50.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(50.0f, 50.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 50.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
}

void CFiguras::prisma_anun (GLuint text, GLuint text2)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		
		glBindTexture(GL_TEXTURE_2D, text2);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
		glEnd();
	
		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
		glNormal3f( 0.0f,1.0f, 0.0f);
			glTexCoord2f(text_der, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(text_der, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(text_izq, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(text_izq, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
}


void CFiguras::esfera(GLfloat radio, int meridianos, int paralelos, GLuint text )
{
	GLdouble theta, phi;

	float ctext_s = 1.0/meridianos;
	float ctext_t = 1.0/paralelos;

	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.

	float v1[]={0.0, 0.0, 0.0};
	float v2[]={0.0, 0.0, 0.0};
	float v3[]={0.0, 0.0, 0.0};
	float v4[]={0.0, 0.0, 0.0};
	int i, j;
	float angulom, angulop;
	angulom=2*3.141592654/meridianos;
	angulop=3.141592654/paralelos; 
	for(i=0;i<meridianos;i++)
	{
		for(j=0;j<paralelos;j++)
		{
			v1[0]=radio*cos(angulom*i)*sin(angulop*j);
			v1[1]=radio*cos(angulop*j);
			v1[2]=radio*sin(angulom*i)*sin(angulop*j);
			
			v2[0]=radio*cos(angulom*i)*sin(angulop*(j+1));
			v2[1]=radio*cos(angulop*(j+1));
			v2[2]=radio*sin(angulom*i)*sin(angulop*(j+1));
			
			v3[0]=radio*cos(angulom*(i+1))*sin(angulop*(j+1));
			v3[1]=radio*cos(angulop*(j+1));
			v3[2]=radio*sin(angulom*(i+1))*sin(angulop*(j+1));

			v4[0]=radio*cos(angulom*(i+1))*sin(angulop*j);
			v4[1]=radio*cos(angulop*j);
			v4[2]=radio*sin(angulom*(i+1))*sin(angulop*j);
			
			glBegin(GL_POLYGON);
				glNormal3fv(v1);
				glTexCoord2f(ctext_s*i, -ctext_t*j);	
				glVertex3fv(v1);
				glNormal3fv(v2);
				glTexCoord2f(ctext_s*i, -ctext_t*(j+1));	
				glVertex3fv(v2);
				glNormal3fv(v3);
				glTexCoord2f(ctext_s*(i+1), -ctext_t*(j+1));	
				glVertex3fv(v3);
				glNormal3fv(v4);
				glTexCoord2f(ctext_s*(i+1), -ctext_t*j);	
				glVertex3fv(v4);
			glEnd();
		}
	}
}

void CFiguras::torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos, GLuint text)
{

	float R = 0;
	float r = 0;

	float v1[]={0.0, 0.0, 0.0};
	float v2[]={0.0, 0.0, 0.0};
	float v3[]={0.0, 0.0, 0.0};
	float v4[]={0.0, 0.0, 0.0};

	int i,j;

	GLdouble angulop = 2*3.1415/paralelos;
	GLdouble angulom = 2*3.1415/meridianos;

	r = (radioM - radiom)/2;
	R = radiom + r;
	glBindTexture(GL_TEXTURE_2D, text);
	for(i=0;i<meridianos;i++)
	{
		for(j=0;j<paralelos;j++)
		{
			/*if (j == 3) {
				glBindTexture(GL_TEXTURE_2D, text);
			}
			else {
				glBindTexture(GL_TEXTURE_2D, NULL);
			}*/
			v1[0]=R*cos(angulom*i) + r*cos(angulom*i)*cos(angulop*j);
			v1[2]=R*sin(angulom*i)+ r*sin(angulom*i)*cos(angulop*j);
			v1[1]=r*sin(angulop*j);

			glNormal3f(v1[0], v1[1], v1[2]);
			
			v2[0]=R*cos(angulom*i) + r*cos(angulom*i)*cos(angulop*(j+1));
			v2[2]=R*sin(angulom*i) + r*sin(angulom*i)*cos(angulop*(j+1));
			v2[1]=r*sin(angulop*(j+1));

			glNormal3f(v2[0], v2[1], v2[2]);

			v3[0]=R*cos(angulom*(i+1)) + r*cos(angulom*(i+1))*cos(angulop*(j+1));
			v3[2]=R*sin(angulom*(i+1)) + r*sin(angulom*(i+1))*cos(angulop*(j+1));
			v3[1]=r*sin(angulop*(j+1));

			glNormal3f(v3[0], v3[1], v3[2]);

			v4[0]=R*cos(angulom*(i+1)) + r*cos(angulom*(i+1))*cos(angulop*j);
			v4[2]=R*sin(angulom*(i+1)) + r*sin(angulom*(i+1))*cos(angulop*j);
			v4[1]=r*sin(angulop*j);

			glNormal3f(v4[0], v4[1], v4[2]);
			
			glBegin(GL_POLYGON);
			
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(v1);//0,0
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(v2);//1,0
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(v3);//0,1
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(v4);//1,1
			glEnd();
		}
	}
}

void CFiguras::cono(float altura, float radio, int resolucion, GLuint text)
{
	
	float v1[]={0.0, 0.0, 0.0};
	float v2[]={0.0, 0.0, 0.0};
	float v3[]={0.0, 0.0, 0.0};
	float v4[]={0.0, 0.0, 0.0};

	float angulo=2*3.14/resolucion;
	float ctext_s = 1.0/resolucion;
	
	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	for(int i=0; i <resolucion; i++)
	{
		
		v2[0]=radio*cos(angulo*i);
		v2[1]=0;
		v2[2]=radio*sin(angulo*i);

		v3[0]=radio*cos(angulo*(i+1));
		v3[1]=0;
		v3[2]=radio*sin(angulo*(i+1));
		
		//glBegin(GL_LINE_LOOP);
        glBegin(GL_POLYGON); //Construye Base
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3f(0.0,0.0,0.0);
			glVertex3fv(v2);
			glVertex3fv(v3);
		glEnd();


		glBindTexture(GL_TEXTURE_2D, text);
		glBegin(GL_TRIANGLES);
			glNormal3f( v2[0], 0.0f, v2[2]);
			glTexCoord2f(ctext_s*i, 0.0f);		glVertex3fv(v2);
			glTexCoord2f(ctext_s*(i+1), 0.0f);	glVertex3fv(v3);
			glTexCoord2f(ctext_s*i, 1.0f);	glVertex3f(0.0,altura,0.0);
		glEnd();
	}
}

void CFiguras::cilindro(float radio, float altura, int resolucion, GLuint text)
{
	
	float v1[]={0.0, 0.0, 0.0};
	float v2[]={0.0, 0.0, 0.0};
	float v3[]={0.0, 0.0, 0.0};
	float v4[]={0.0, 0.0, 0.0};
	float v5[]={0.0, 0.0, 0.0};

	float angulo=2*3.14/resolucion;

	//float ctext_s = 1/resolucion-1;
	float ctext_s = 80.0/resolucion;
	float ctext_t = 0.0;

	
	for(int i=0; i <resolucion; i++)
	{
		 
		v2[0]=radio*cos(angulo*i);
		v2[1]=0;
		v2[2]=radio*sin(angulo*i);

		v3[0]=radio*cos(angulo*(i+1));
		v3[1]=0;
		v3[2]=radio*sin(angulo*(i+1));
	
		v4[0]=radio*cos(angulo*i);
		v4[1]=altura;
		v4[2]=radio*sin(angulo*i);

		v5[0]=radio*cos(angulo*(i+1));
		v5[1]=altura;
		v5[2]=radio*sin(angulo*(i+1));

		glBegin(GL_POLYGON);
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3f(0.0,0.0,0.0);
			glVertex3fv(v2);
			glVertex3fv(v3);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, text);
		glBegin(GL_POLYGON);
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, altura, 0.0);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(v4);
			glTexCoord2f(1.0f, 0.5f); glVertex3fv(v5);
		glEnd();

		
		glBegin(GL_POLYGON);
			glNormal3f( v2[0], 0.0f, v2[2]);
			glTexCoord2f(ctext_s*i, 0.0f);		glVertex3fv(v2);
			glTexCoord2f(ctext_s*(i+1), 0.0f);	glVertex3fv(v3);
			glTexCoord2f(ctext_s*(i+1), 1.0f);	glVertex3fv(v5);
			glTexCoord2f(ctext_s*i, 1.0f);		glVertex3fv(v4);
		glEnd();
	}
}	

void CFiguras::prisma3(GLuint text, GLuint text2)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, text2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();

	
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);  //0   Se rotaron estas texturas 
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);	//3		Valores comentados eran los originales
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);	//5
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);	//4
	glEnd();
	
	
	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text);
	glBegin(GL_POLYGON);  //Left      
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);  //1
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);  //7
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);  //6
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);  //2
	glEnd();

	
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text2);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void CFiguras::logobatman(GLuint text)  
{	
	glLineWidth(5);
	glBindTexture(GL_TEXTURE_2D, text);
	glBegin(GL_LINE_LOOP);
		glVertex3f(0, .03, 0);
		glVertex3f(.01, .03, 0);
		glVertex3f(.015, .035, 0);
		glVertex3f(.02, .04, 0);
		glVertex3f(.02, .03, 0);
		glVertex3f(.02, .02, 0);
		glVertex3f(.02, .01, 0); 
		glVertex3f(.025, .01, 0);
		glVertex3f(.03, .01, 0);
		glVertex3f(.035, .01, 0);
		glVertex3f(.04, .01, 0);
		glVertex3f(.045, .01, 0);
		glVertex3f(.05, .01, 0);
		glVertex3f(.055, .01, 0);
		glVertex3f(.06, .01, 0);  
		glVertex3f(.06, .02, 0);
		glVertex3f(.06, .03, 0);
		glVertex3f(.055, .035, 0);
		glVertex3f(.05, .04, 0);
		glVertex3f(.045, .045, 0);
		glVertex3f(.04, .05, 0);
		glVertex3f(.035, .055, 0);
		glVertex3f(.03, .06, 0);
		glVertex3f(.04, .06, 0);
		glVertex3f(.045, .055, 0);
		glVertex3f(.05, .05, 0);
		glVertex3f(.055, .045, 0);
		glVertex3f(.06, .04, 0);
		glVertex3f(.065, .035, 0);
		glVertex3f(.07, .03, 0);
		glVertex3f(.075, .025, 0);
		glVertex3f(.08, .02, 0);
		glVertex3f(.085, .015, 0);
		glVertex3f(.09, .01, 0);
		glVertex3f(.095, .005, 0);
		glVertex3f(.095, 0, 0); 
		glVertex3f(.095, -.005, 0);
		glVertex3f(.09, -.01, 0);
		glVertex3f(.085, -.015, 0);
		glVertex3f(.08, -.02, 0);
		glVertex3f(.075, -.025, 0);
		glVertex3f(.07, -.03, 0);
		glVertex3f(.065, -.035, 0);
		glVertex3f(.06, -.04, 0);
		glVertex3f(.055, -.045, 0); 
		glVertex3f(.055, -.04, 0);
		glVertex3f(.06, -.035, 0);
		glVertex3f(.065, -.03, 0);
		glVertex3f(.06, -.03, 0);
		glVertex3f(.05, -.03, 0);
		glVertex3f(.04, -.04, 0);
		glVertex3f(.03, -.03, 0);
		glVertex3f(.02, -.03, 0);
		glVertex3f(.015, -.035, 0);
		glVertex3f(.01, -.04, 0);
		glVertex3f(.005, -.045, 0);
		glVertex3f(0, -.05, 0);   

		glVertex3f(-.005, -.045, 0);
		glVertex3f(-.01, -.04, 0);
		glVertex3f(-.015, -.035, 0);
		glVertex3f(-.02, -.03, 0);
		glVertex3f(-.03, -.03, 0);
		glVertex3f(-.04, -.04, 0);
		glVertex3f(-.05, -.03, 0);
		glVertex3f(-.06, -.03, 0);
		glVertex3f(-.065, -.03, 0);
		glVertex3f(-.06, -.035, 0);
		glVertex3f(-.055, -.04, 0);
		glVertex3f(-.055, -.045, 0);
		glVertex3f(-.06, -.04, 0);
		glVertex3f(-.065, -.035, 0);
		glVertex3f(-.07, -.03, 0);
		glVertex3f(-.075, -.025, 0);
		glVertex3f(-.08, -.02, 0);
		glVertex3f(-.085, -.015, 0);
		glVertex3f(-.09, -.01, 0);
		glVertex3f(-.095, -.005, 0);
		glVertex3f(-.095, 0, 0);
		glVertex3f(-.095, .005, 0);
		glVertex3f(-.09, .01, 0);
		glVertex3f(-.085, .015, 0);
		glVertex3f(-.08, .02, 0);
		glVertex3f(-.075, .025, 0);
		glVertex3f(-.07, .03, 0);
		glVertex3f(-.065, .035, 0);
		glVertex3f(-.06, .04, 0);
		glVertex3f(-.055, .045, 0);
		glVertex3f(-.05, .05, 0);
		glVertex3f(-.045, .055, 0);
		glVertex3f(-.04, .06, 0);
		glVertex3f(-.03, .06, 0);
		glVertex3f(-.035, .055, 0);
		glVertex3f(-.04, .05, 0);
		glVertex3f(-.045, .045, 0);

		glVertex3f(-.05, .04, 0);
		glVertex3f(-.055, .035, 0);
		glVertex3f(-.06, .03, 0);
		glVertex3f(-.06, .02, 0);
		glVertex3f(-.06, .01, 0);
		glVertex3f(-.055, .01, 0);
		glVertex3f(-.05, .01, 0);
		glVertex3f(-.045, .01, 0);
		glVertex3f(-.04, .01, 0);
		glVertex3f(-.035, .01, 0);
		glVertex3f(-.03, .01, 0);
		glVertex3f(-.025, .01, 0);
		glVertex3f(-.02, .01, 0); 
		glVertex3f(-.02, .02, 0);
		glVertex3f(-.02, .03, 0);
		glVertex3f(-.02, .04, 0);
		glVertex3f(-.015, .035, 0);
		glVertex3f(-.01, .03, 0);
		glVertex3f(0, .03, 0);
	glEnd();

}
void CFiguras::prisma5(float altura, float largo, float profundidad, GLuint text, GLuint text2)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5*largo ,-0.5*altura, 0.5*profundidad},    //Coordenadas Vértice 1 V1
				{-0.5*largo ,-0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 2 V2
				{-0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 3 V3
				{0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 4 V4
				{0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 5 V5
				{0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 6 V6
				{-0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 7 V7
				{-0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 8 V8
	};

	glBindTexture(GL_TEXTURE_2D, text);
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]); //0
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]); //4
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]); //7
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]); //1
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, text2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Right
	//glColor3f(0.0,0.0,1.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Back
	//glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]); //6
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]); //5
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[6]); //3
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]); //2
	glEnd();

	//glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Left
	//glColor3f(1.0,1.0,1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	//glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);  //0 2
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[2]);	//1 3
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);	//2 0
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);	//3 1
	glEnd();

	//glBindTexture(GL_TEXTURE_2D, NULL);
	//glBindTexture(GL_TEXTURE_2D, text);
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]); //4
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);	//5
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);	//6
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]); //7
	glEnd();
	glBindTexture(GL_TEXTURE_2D, NULL);
}
void CFiguras::persona(GLuint text, GLuint text2, GLuint text3, GLuint text4, float angulo, float sentarse1, float sentarse2, float sentarse3, float sentarse4, float caminar1, float caminar2)  //Funcion creacion prisma
{
	float altura = 5;
	float newaltura = altura / 1;
	float largo = 5;
	float profundidad = 2;
	int meridianos = 30;
	int paralelos = 30;
	float ctext_s = 1.0 / meridianos;
	float ctext_t = 1.0 / paralelos;
	float v1[] = { 0.0, 0.0, 0.0 };
	float v2[] = { 0.0, 0.0, 0.0 };
	float v3[] = { 0.0, 0.0, 0.0 };
	float v4[] = { 0.0, 0.0, 0.0 };
	int i, j;
	float angulom, angulop;
	angulom = 2 * 3.141592654 / meridianos;
	angulop = 3.141592654 / paralelos;
	GLfloat radio = 5;
	GLdouble theta, phi;
	GLfloat vertice[48][3] = {
				//Cuello
				{0.5*largo ,-0.5*altura, 0.5*profundidad},    //Coordenadas Vértice 1 V0
				{-0.5*largo ,-0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 2 V1
				{-0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 3 V2
				{0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 4 V3
				{0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 5 V4
				{0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 6 V5
				{-0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 7 V6
				{-0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 8 V7
				//Cuerpo
				{1.25*largo ,-1.25*altura, 1.25*profundidad},    //Coordenadas Vértice 1 V8
				{-1.25*largo ,-1.25*altura , 1.25*profundidad},    //Coordenadas Vértice 2 V9
				{-1.25*largo ,-1.25*altura , -1.25*profundidad},    //Coordenadas Vértice 3 V10
				{1.25*largo ,-1.25*altura , -1.25*profundidad},    //Coordenadas Vértice 4 V11
				{1.25*largo ,1.25*altura , 1.25*profundidad},    //Coordenadas Vértice 5 V12
				{1.25*largo ,1.25*altura , -1.25*profundidad},    //Coordenadas Vértice 6 V13
				{-1.25*largo ,1.25*altura , -1.25*profundidad},    //Coordenadas Vértice 7 V14
				{-1.25*largo ,1.25*altura , 1.25*profundidad},    //Coordenadas Vértice 8 V15
				//Cabeza
				{0.75*largo ,-0.75*altura, 0.75*profundidad},    //Coordenadas Vértice 1 V16
				{-0.75*largo ,-0.75*altura , 0.75*profundidad},    //Coordenadas Vértice 2 V17
				{-0.75*largo ,-0.75*altura , -0.75*profundidad},    //Coordenadas Vértice 3 V18
				{0.75*largo ,-0.75*altura , -0.75*profundidad},    //Coordenadas Vértice 4 V19
				{0.75*largo ,0.75*altura , 0.75*profundidad},    //Coordenadas Vértice 5 V20
				{0.75*largo ,0.75*altura , -0.75*profundidad},    //Coordenadas Vértice 6 V21
				{-0.75*largo ,0.75*altura , -0.75*profundidad},    //Coordenadas Vértice 7 V22
				{-0.75*largo ,0.75*altura , 0.75*profundidad},    //Coordenadas Vértice 8 V23
				//Coxis
				{1.25*largo ,-1.25*newaltura, 1.25*profundidad},    //Coordenadas Vértice 1 V24
				{-1.25*largo ,-1.25*newaltura , 1.25*profundidad},    //Coordenadas Vértice 2 V25
				{-1.25*largo ,-1.25*newaltura , -1.25*profundidad},    //Coordenadas Vértice 3 V26
				{1.25*largo ,-1.25*newaltura , -1.25*profundidad},    //Coordenadas Vértice 4 V27
				{1.25*largo ,1.25*newaltura , 1.25*profundidad},    //Coordenadas Vértice 5 V28
				{1.25*largo ,1.25*newaltura , -1.25*profundidad},    //Coordenadas Vértice 6 V29
				{-1.25*largo ,1.25*newaltura , -1.25*profundidad},    //Coordenadas Vértice 7 V30
				{-1.25*largo ,1.25*newaltura , 1.25*profundidad},    //Coordenadas Vértice 8 V31
				//Pie derecho e izquierdo 
				{0.5*largo ,-1.5*altura, 1.25*profundidad},    //Coordenadas Vértice 1 V32
				{-0.5*largo ,-1.5*altura , 1.25*profundidad},    //Coordenadas Vértice 2 V33
				{-0.5*largo ,-1.5*altura , -1.25*profundidad},    //Coordenadas Vértice 3 V34
				{0.5*largo ,-1.5*altura , -1.25*profundidad},    //Coordenadas Vértice 4 V35
				{0.5*largo ,1.5*altura , 1.25*profundidad},    //Coordenadas Vértice 5 V36
				{0.5*largo ,1.5*altura , -1.25*profundidad},    //Coordenadas Vértice 6 V37
				{-0.5*largo ,1.5*altura , -1.25*profundidad},    //Coordenadas Vértice 7 V38
				{-0.5*largo ,1.5*altura , 1.25*profundidad},    //Coordenadas Vértice 8 V39
				//Pie izquierdo No usado, reservado para brazos 
				{0.5*largo ,-1.5*altura, 1.25*profundidad},    //Coordenadas Vértice 1 V40
				{-0.5*largo ,-1.5*altura , 1.25*profundidad},    //Coordenadas Vértice 2 V41
				{-0.5*largo ,-1.5*altura , -1.25*profundidad},    //Coordenadas Vértice 3 V42
				{0.5*largo ,-1.5*altura , -1.25*profundidad},    //Coordenadas Vértice 4 V43
				{0.5*largo ,1.5*altura , 1.25*profundidad},    //Coordenadas Vértice 5 V44
				{0.5*largo ,1.5*altura , -1.25*profundidad},    //Coordenadas Vértice 6 V45
				{-0.5*largo ,1.5*altura , -1.25*profundidad},    //Coordenadas Vértice 7 V46
				{-0.5*largo ,1.5*altura , 1.25*profundidad},    //Coordenadas Vértice 8 V47

				
	};
			glPushMatrix();
				//Cuello
				glBindTexture(GL_TEXTURE_2D, text3);
				glBegin(GL_POLYGON);	//Front
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
				glEnd();

				glBegin(GL_POLYGON);	//Right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
				glEnd();

				glBegin(GL_POLYGON);	//Back
				//glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
				glEnd();

				glBegin(GL_POLYGON);  //Left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
				glEnd();

				glBegin(GL_POLYGON);  //Bottom
				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);  //0
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);	//1
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[0]);	//2
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);	//3
				glEnd();

				glBegin(GL_POLYGON);  //Top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
				glEnd();

				// Cuerpo
				glTranslatef(0, -6.25, 0);
				glBindTexture(GL_TEXTURE_2D, text);
				glBegin(GL_POLYGON);	//Front
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[8]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[12]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[15]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[9]);
				glEnd();

				glBegin(GL_POLYGON);	//Right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[8]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[11]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[13]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[12]);
				glEnd();

				glBegin(GL_POLYGON);	//Back
				//glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[14]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[13]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[11]);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[10]);
				glEnd();

				glBegin(GL_POLYGON);  //Left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[9]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[15]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[14]);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[10]);
				glEnd();

				glBegin(GL_POLYGON);  //Bottom
				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[10]);  //0
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[11]);	//1
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[8]);	//2
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[9]);	//3
				glEnd();

				glBegin(GL_POLYGON);  //Top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[12]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[13]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[14]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[15]);
				glEnd();

				//Cabeza
				glTranslatef(0, 12, 0);
				glRotatef(90, 0, 1, 0);
				glBindTexture(GL_TEXTURE_2D, text2);   // choose the texture to use.
				for (i = 0; i < meridianos; i++)
				{
					for (j = 0; j < paralelos; j++)
					{
						v1[0] = radio * cos(angulom*i)*sin(angulop*j);
						v1[1] = radio * cos(angulop*j);
						v1[2] = radio * sin(angulom*i)*sin(angulop*j);

						v2[0] = radio * cos(angulom*i)*sin(angulop*(j + 1));
						v2[1] = radio * cos(angulop*(j + 1));
						v2[2] = radio * sin(angulom*i)*sin(angulop*(j + 1));

						v3[0] = radio * cos(angulom*(i + 1))*sin(angulop*(j + 1));
						v3[1] = radio * cos(angulop*(j + 1));
						v3[2] = radio * sin(angulom*(i + 1))*sin(angulop*(j + 1));

						v4[0] = radio * cos(angulom*(i + 1))*sin(angulop*j);
						v4[1] = radio * cos(angulop*j);
						v4[2] = radio * sin(angulom*(i + 1))*sin(angulop*j);

						glBegin(GL_POLYGON);
						glNormal3fv(v1);
						glTexCoord2f(ctext_s*i, -ctext_t * j);
						glVertex3fv(v1);
						glNormal3fv(v2);
						glTexCoord2f(ctext_s*i, -ctext_t * (j + 1));
						glVertex3fv(v2);
						glNormal3fv(v3);
						glTexCoord2f(ctext_s*(i + 1), -ctext_t * (j + 1));
						glVertex3fv(v3);
						glNormal3fv(v4);
						glTexCoord2f(ctext_s*(i + 1), -ctext_t * j);
						glVertex3fv(v4);
						glEnd();
					}
				}
			glPopMatrix();
			glPushMatrix();
				// Coxis
				glTranslatef(0, -11.25, 0);
				glRotatef(-angulo, 1, 0, 0);   //animacion
				glTranslatef(0, sentarse1, sentarse2); // animacion  sentarse
				glBindTexture(GL_TEXTURE_2D, text);
				glBegin(GL_POLYGON);	//Front
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[16+8]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[20+8]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[23+8]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[17+8]);
				glEnd();

				glBegin(GL_POLYGON);	//Right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[16+8]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19+8]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[21+8]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[20+8]);
				glEnd();

				glBegin(GL_POLYGON);	//Back
				//glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[22+8]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[21+8]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19+8]);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18+8]);
				glEnd();

				glBegin(GL_POLYGON);  //Left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[17+8]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[23+8]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[22+8]);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18+8]);
				glEnd();

				glBegin(GL_POLYGON);  //Bottom
				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18+8]);  //0
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19+8]);	//1
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[16+8]);	//2
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[17+8]);	//3
				glEnd();

				glBegin(GL_POLYGON);  //Top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[20+8]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[21+8]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[22+8]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[23+8]);
				glEnd();
				//glTranslatef(0, 9.25, 0);
			glPopMatrix();
			//Pies
			//Derecho
			
			glPushMatrix();
				glTranslatef(3.75, -25, 0);
				//glRotatef(-angulo, 1, 0, 0);   //animacion
				glTranslatef(0, sentarse3, sentarse4); // animacion  sentarse
				glRotatef(caminar1, 1, 0, 0);
				glRotatef(-caminar2, 0, 0, 1);
				glBindTexture(GL_TEXTURE_2D, text3);
				glBegin(GL_POLYGON);	//Front
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[16 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[20 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[23 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[17 + 16]);
				glEnd();

				glBegin(GL_POLYGON);	//Right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[16 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[21 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[20 + 16]);
				glEnd();

				glBegin(GL_POLYGON);	//Back
				//glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[22 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[21 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19 + 16]);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18 + 16]);
				glEnd();

				glBegin(GL_POLYGON);  //Left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[17 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[23 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[22 + 16]);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18 + 16]);
				glEnd();

				glBegin(GL_POLYGON);  //Bottom
				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18 + 16]);  //0
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19 + 16]);	//1
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[16 + 16]);	//2
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[17 + 16]);	//3
				glEnd();

				glBegin(GL_POLYGON);  //Top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[20 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[21 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[22 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[23 + 16]);
				glEnd();
			glPopMatrix();
			glPushMatrix();
			//Izquierdo
				glTranslatef(-3.75, -25, 0);
				glTranslatef(0, sentarse3, sentarse4); // animacion   sentarse
				glRotatef(-caminar1, 1, 0, 0);
				glRotatef(caminar2, 0, 0, 1);
				glBindTexture(GL_TEXTURE_2D, text3);
				glBegin(GL_POLYGON);	//Front
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[16 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[20 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[23 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[17 + 16]);
				glEnd();

				glBegin(GL_POLYGON);	//Right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[16 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[21 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[20 + 16]);
				glEnd();

				glBegin(GL_POLYGON);	//Back
				//glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[22 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[21 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19 + 16]);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18 + 16]);
				glEnd();

				glBegin(GL_POLYGON);  //Left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[17 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[23 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[22 + 16]);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18 + 16]);
				glEnd();

				glBegin(GL_POLYGON);  //Bottom
				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18 + 16]);  //0
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19 + 16]);	//1
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[16 + 16]);	//2
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[17 + 16]);	//3
				glEnd();

				glBegin(GL_POLYGON);  //Top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[20 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[21 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[22 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[23 + 16]);
				glEnd();
			glPopMatrix();
			glPushMatrix();
			//brazos 
			//izquierdo 
				glTranslatef(-8.75, -7.5, 0);
				glRotatef(caminar1, 1, 0, 0);
				glRotatef(-2*caminar2, 0, 0, 1);
				glBindTexture(GL_TEXTURE_2D, text4);
				glBegin(GL_POLYGON);	//Front
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[16 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[20 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[23 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[17 + 16]);
				glEnd();

				glBegin(GL_POLYGON);	//Right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[16 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[21 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[20 + 16]);
				glEnd();

				glBegin(GL_POLYGON);	//Back
				//glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[22 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[21 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19 + 16]);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18 + 16]);
				glEnd();

				glBegin(GL_POLYGON);  //Left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[17 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[23 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[22 + 16]);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18 + 16]);
				glEnd();

				glBegin(GL_POLYGON);  //Bottom
				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18 + 16]);  //0
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19 + 16]);	//1
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[16 + 16]);	//2
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[17 + 16]);	//3
				glEnd();
				glBindTexture(GL_TEXTURE_2D, text);
				glBegin(GL_POLYGON);  //Top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[20 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[21 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[22 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[23 + 16]);
				glEnd();
			glPopMatrix();
			glPushMatrix();
			//derecho
				glTranslatef(8.75, -7.5, 0);
				glRotatef(-caminar1, 1, 0, 0);
				glRotatef(2*caminar2, 0, 0, 1);
				glBindTexture(GL_TEXTURE_2D, text4);
				glBegin(GL_POLYGON);	//Front
				glNormal3f(0.0f, 0.0f, 1.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[16 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[20 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[23 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[17 + 16]);
				glEnd();

				glBegin(GL_POLYGON);	//Right
				glNormal3f(1.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[16 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[21 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[20 + 16]);
				glEnd();

				glBegin(GL_POLYGON);	//Back
				//glNormal3f(0.0f, 0.0f, -1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[22 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[21 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19 + 16]);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18 + 16]);
				glEnd();

				glBegin(GL_POLYGON);  //Left
				glNormal3f(-1.0f, 0.0f, 0.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[17 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[23 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[22 + 16]);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18 + 16]);
				glEnd();

				glBegin(GL_POLYGON);  //Bottom
				glNormal3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18 + 16]);  //0
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[19 + 16]);	//1
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[16 + 16]);	//2
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[17 + 16]);	//3
				glEnd();
				glBindTexture(GL_TEXTURE_2D, text);
				glBegin(GL_POLYGON);  //Top
				glNormal3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[20 + 16]);
				glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[21 + 16]);
				glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[22 + 16]);
				glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[23 + 16]);
				glEnd();
			glPopMatrix();
			
	

}
void prismaPerrito(float R, float G, float B)
{
	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front  
	glColor3f(R, G, B);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right   
	glColor3f(R - 0.1, G, B);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back   
	glColor3f(R, G, B);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left   
	glColor3f(R, G, B);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom  
	glColor3f(R, G, B);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top    
	glColor3f(R, G, B);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}
void CFiguras::perrito( float saltar) {
	//Pecho
	glPushMatrix();
	glScalef(2.0f, 1.5f, 2.0f);
	//Animacion
	glRotatef(-saltar, 1, 0, 0);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glPopMatrix();
	//Cadera
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(1.5f, 1.5f, 2.0f);
	//Animacion
	glRotatef(saltar, 1, 0, 0);
	glTranslatef(0, -(.016*saltar), 0);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glPopMatrix();
	//Cola
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -3.405f);
	glScalef(2.0f, 1.5f, 1.0f);
	//Animacion
	glRotatef(saltar, 1, 0, 0);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glPopMatrix();
	//Pies Delanteros
	//Pie derecho
	glPushMatrix();
	glTranslatef(0.66f, -1.51f, 0.66f);
	glScalef(0.666f, 2.0f, 0.666f);
	//Animacion
	glRotatef(saltar, 1, 0, 0);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glTranslatef(0.0f, -0.5f, 0.5f);
	glScalef(1.0f, 0.25f, 2.0f);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glPopMatrix();
	//Pie izquierdo
	glPushMatrix();
	glTranslatef(-0.66f, -1.51f, 0.66f);
	glScalef(0.666f, 2.0f, 0.666f);
	//Animacion
	glRotatef(saltar, 1, 0, 0);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glTranslatef(0.0f, -0.5f, 0.5f);
	glScalef(1.0f, 0.25f, 2.0f);
	prismaPerrito(0.94f, 0.60f, 0.023f);

	glPopMatrix();
	//Pies traseros
	//Pie derecho
	glPushMatrix();
	glTranslatef(0.66f, -1.51f, -3.572f);
	glScalef(0.666f, 2.0f, 0.666f);
	//Animacion
	glRotatef(saltar, 1, 0, 0);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glTranslatef(0.0f, -0.5f, 0.5f);
	glScalef(1.0f, 0.25f, 2.0f);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glPopMatrix();
	//Pie izquierdo
	glPushMatrix();
	glTranslatef(-0.66f, -1.51f, -3.572f);
	glScalef(0.666f, 2.0f, 0.666f);
	//Animacion
	glRotatef(saltar, 1, 0, 0);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glTranslatef(0.0f, -0.5f, 0.5f);
	glScalef(1.0f, 0.25f, 2.0f);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glPopMatrix();
	//Collar 
	glPushMatrix();
	glTranslatef(0.0f, 0.88f, 0.5f);
	glScalef(1.0f, 0.25f, 1.0f);
	prismaPerrito(0.031f, 0.49f, 0.0f);
	glPopMatrix();
	//Boca parte baja 
	glPushMatrix();
	glTranslatef(0.0f, 1.19f, 0.5f);
	glScalef(1.25f, 0.25f, 2.0f);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	//Garganta
	glTranslatef(0.0f, 1.0f, -0.225f);
	glScalef(1.0f, 1.47f, 0.55f);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glPopMatrix();
	// Lengua
	glPushMatrix();
	glTranslatef(0.0f, 1.49f, 1.25f);
	glScalef(0.5f, 0.25f, 1.3f);
	prismaPerrito(0.92f, 0.54f, 0.45f);
	glTranslatef(0.0f, -2.5f, 0.35f);
	glScalef(1.0f, 4.0f, 0.301f);
	prismaPerrito(0.92f, 0.54f, 0.45f);
	glPopMatrix();
	//Cabeza
	glPushMatrix();
	glTranslatef(0.0f, 1.75f, 0.7f);
	glScalef(1.25f, 0.25f, 2.4f);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glPopMatrix();
	//Nariz
	glPushMatrix();
	glTranslatef(0.0f, 2.0f, 1.75f);
	glScalef(0.5f, 0.25f, 0.5f);
	prismaPerrito(0.0f, 0.0f, 0.0f);
	glPopMatrix();
	//Cabeza
	glPushMatrix();
	glTranslatef(0.0f, 1.95f, 0.7f);
	glScalef(1.25f, 0.25f, 2.4f);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glPopMatrix();
	//Ojos
	glPushMatrix();
	glTranslatef(0.0f, 2.5f, -0.125f);
	glScalef(1.25f, 0.96f, 0.75f);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	//Blanco 
	glTranslatef(0.0f, 0.04f, 0.62f);
	glScalef(1.0f, 0.95f, 0.25f);
	prismaPerrito(1.0f, 1.0f, 1.0f);
	glPopMatrix();
	//Nuca
	glPushMatrix();
	glTranslatef(0.3f, 2.4f, 0.5f);
	glScalef(0.25f, 0.45f, 0.093f);
	prismaPerrito(0.0f, 0.0f, 0.0f);
	glPopMatrix();
	//Negro de los ojos
	glPushMatrix();
	glTranslatef(-0.3f, 2.5f, 0.5f);
	glScalef(0.25f, 0.45f, 0.093f);
	prismaPerrito(0.0f, 0.0f, 0.0f);
	glPopMatrix();
	//Frente
	glPushMatrix();
	glTranslatef(0.0f, 3.08f, -0.03f);
	glScalef(1.25f, 0.2f, 0.95f);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glPopMatrix();
	//Orejas 
	//Oreja Derecha
	glPushMatrix();
	glTranslatef(0.87f, 2.5f, -0.1f);
	glScalef(0.5f, 0.5f, 0.5f);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	//Negro Oreja
	glTranslatef(0.0f, 1.5f, 0.0f);
	glScalef(1.0f, 2.5f, 1.0f);
	prismaPerrito(0.0f, 0.0f, 0.0f);
	//Ahoi
	glTranslatef(0.0f, 0.4f, 0.7f);
	glScalef(1.0f, 0.25f, 2.25f);
	prismaPerrito(0.0f, 0.0f, 0.0f);
	glPopMatrix();
	//Oreja Izquierda
	glPushMatrix();
	glTranslatef(-0.87f, 2.5f, -0.1f);
	glScalef(0.5f, 0.5f, 0.5f);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	//Negro Oreja
	glTranslatef(0.0f, 1.5f, 0.0f);
	glScalef(1.0f, 2.5f, 1.0f);
	prismaPerrito(0.0f, 0.0f, 0.0f);
	//Ahoi
	glTranslatef(0.0f, 0.4f, 0.7f);
	glScalef(1.0f, 0.25f, 2.25f);
	prismaPerrito(0.0f, 0.0f, 0.0f);
	glPopMatrix();
	//Colita negra 
	glPushMatrix();
	glTranslatef(0.0f, 1.25f, -4.15f);
	glScalef(0.5f, 2.0f, 0.5f);
	prismaPerrito(0.0f, 0.0f, 0.0f);
	glRotatef(180, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.4f, 0.75f);
	glScalef(1.0f, 0.25f, 2.25f);
	prismaPerrito(0.0f, 0.0f, 0.0f);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 3.2f, 0.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	prismaPerrito(0.94f, 0.60f, 0.023f);
	glPopMatrix();
	glColor3f(1, 1, 1);
}
