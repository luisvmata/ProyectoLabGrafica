//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Func�on creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text);	//Func�on creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Func�on creacion cono
	void prisma_anun (GLuint text, GLuint text2);							//Func�on creacion movimiento
	void prisma (float altura, float largo, float profundidad, GLuint text);//Func�on creacion prisma
	void prisma2 (GLuint text, GLuint text2);
	void prisma3(GLuint text, GLuint text2);
	void prisma5(float altura, float largo, float profundidad, GLuint text, GLuint text2);
	void persona(GLuint text, GLuint text2, GLuint text3,GLuint text4, float angulo, float sentarse1, float sentarse2, float sentarse3, float sentarse4, float caminar1, float caminar2);
	void skybox(float altura, float largo, float profundidad, GLuint text, GLuint text2);	//Funcion creacion cielo
	void skybox2 (float altura, float largo, float profundidad, GLuint text);
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos, GLuint text);
	void logobatman(GLuint text);
	void perrito(float saltar);


};
