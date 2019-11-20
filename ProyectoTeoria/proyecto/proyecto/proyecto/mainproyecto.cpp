//Semestre 2020 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;
char s[30];
const double PI = 3.1415926535897;
CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;
float LightAngle = 30.0f;

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position
GLfloat LightDirection[] = { 0.0f, 0.0f, -2.0f };
GLfloat LightPosition[] = { 0.0f, 0.0f, 1.0f, 0.0f };
GLfloat spot[] = { -1,-1,0,1};  //REVISAR PRACTICA 7 O 6 PARA LA LUZ. 
GLfloat spotPosicion[] = { 0,1,0,1 };

/////Figuras a utilizar/////////////

CFiguras cielo;
CFiguras carpa;
CFiguras puntaCarpa;
CFiguras persona;
CFiguras persona2;
CFiguras puertaI;
CFiguras puertaD;
CFiguras bancas1;
CFiguras bancas2;
CFiguras bancas3;
CFiguras piso;
CFiguras cuerda1I;
CFiguras cuerda2I;
CFiguras cuerda3;
CFiguras posteAro;
CFiguras aro;
CFiguras base1;
CFiguras base2;
CFiguras perro;
CFiguras pelota;
CFiguras placas;
CFiguras letrero;
CFiguras proyector;
CFiguras conito;
CFiguras lampara;

/////Texturas a utilizar////////////

CTexture sky;
CTexture pasto;
CTexture circo;
CTexture tierra;
CTexture banca;
CTexture arena;
CTexture circocartel;
CTexture azul;
CTexture amarillo;
CTexture rojo;
CTexture naranja;
CTexture rosa;
CTexture verde;
CTexture carita;
CTexture carapayaso;
CTexture azulyamarillo;
CTexture amarilloyamarillo;
CTexture rojoyamarillo;
CTexture naranjayamarillo;
CTexture rosayamarillo;
CTexture verdeyamarillo;
CTexture piel;
CTexture pelotat;
CTexture hueso;
CTexture negro;
CTexture mantel;
CTexture metal;


bool f_animacion = false;
bool g_animacion = false;
bool h_animacion = false;
bool i_animacion = false;
bool j_animacion = false;
bool k_animacion = false;
bool l_animacion = false;
bool m_animacion = false;
bool n_animacion = false;
bool o_animacion = false;
bool p_animacion = false;
bool q_animacion = false;
bool r_animacion = false;
bool s_animacion = false;
bool t_animacion = false;
bool u_animacion = false;
bool v_animacion = false;
bool w_animacion = false;
bool x_animacion = false;
bool y_animacion = false;
bool z_animacion = false;
bool aa_animacion = false;
bool ab_animacion = false;
bool ac_animacion = false;
bool ad_animacion = false;
bool ae_animacion = false;
bool af_animacion = true;
bool ag_animacion = false;
bool ah_animacion = false;
bool ai_animacion = false;
bool aj_animacion = true;
bool ak_animacion = false;
bool al_animacion = false;
bool am_animacion = false;
bool an_animacion = false;
bool ao_animacion = true;;
bool ap_animacion = false;
bool aq_animacion = false;
bool ar_animacion = false;
bool as_animacion = true;
bool at_animacion = false;
bool au_animacion = true;;
bool av_animacion = false;
bool aw_animacion = false;
bool ax_animacion = false;
bool ay_animacion = false;
bool az_animacion = false;
bool ba_animacion = false;
bool bb_animacion = false;

bool f_silla = false;
bool g_silla = false;
bool h_silla = false;
bool i_silla = false;

float gira = 0.0;
float girasilla1 = 0.0;
float girasilla2 = 0.0;

float angulo = 0.0;
float sentarse1 = 0.0;
float sentarse2 = 0.0;
float sentarse3 = 0.0;
float sentarse4 = 0.0;
float caminar1 = 0.0;
float caminar2 = 0.0;
float caminar3 = 0.0;
float saltar = 0.0;
float saltar1 = 0.0;
float saltar2 = 0.0;
float girar1 = 0.0;
float salir = 0.0;
float pasos1 = 0.0;
float pasos2 = 0.0;
float girarpelota = 0.0;
float ocultarpayaso = 0.0;
float abrepuertas = 0.1;
float movpersona = 0.0;
float girapersona = 0.0;
float movtraspes = 0.0;
float giratraspes = 0.0;
float giraproyector1 = 0.0;
float giraproyector2 = 0.0;
float movpersona2 = 0.0;
float girapersona2 = 0.0;
float caminar5 = 0.1;


float vx=0.0;
float vy=0.0;
float v;



void ciudad ()
{
	
		
				glFlush();
				frame++;
}

GLuint createDL() 
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL,GL_COMPILE);
	// call the function that contains 
	// the rendering commands
		ciudad();
		//monito();
	// endList
	glEndList();

	return(ciudadDL);
}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	sky.LoadTGA("city/city.tga");	
	sky.BuildGLTexture();
	sky.ReleaseImage();

	pasto.LoadTGA("city/pasto.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();

	circo.LoadTGA("city/circo.tga");
	circo.BuildGLTexture();
	circo.ReleaseImage();

	tierra.LoadTGA("city/tierra.tga");
	tierra.BuildGLTexture();
	tierra.ReleaseImage();

	banca.LoadTGA("city/bancas.tga");
	banca.BuildGLTexture();
	banca.ReleaseImage();

	arena.LoadTGA("city/arena.tga");
	arena.BuildGLTexture();
	arena.ReleaseImage();

	circocartel.LoadTGA("city/letrero.tga");
	circocartel.BuildGLTexture();
	circocartel.ReleaseImage();

	azul.LoadTGA("city/azul.tga");
	azul.BuildGLTexture();
	azul.ReleaseImage();

	rosa.LoadTGA("city/rosa.tga");
	rosa.BuildGLTexture();
	rosa.ReleaseImage();

	verde.LoadTGA("city/verde.tga");
	verde.BuildGLTexture();
	verde.ReleaseImage();

	naranja.LoadTGA("city/naranja.tga");
	naranja.BuildGLTexture();
	naranja.ReleaseImage();

	amarillo.LoadTGA("city/amarillo.tga");
	amarillo.BuildGLTexture();
	amarillo.ReleaseImage();

	rojo.LoadTGA("city/rojo.tga");
	rojo.BuildGLTexture();
	rojo.ReleaseImage();

	carita.LoadTGA("city/carita.tga");
	carita.BuildGLTexture();
	carita.ReleaseImage();
    
	rosayamarillo.LoadTGA("city/rosayamarillo.tga");
	rosayamarillo.BuildGLTexture();
	rosayamarillo.ReleaseImage();

	rojoyamarillo.LoadTGA("city/rojoyamarillo.tga");
	rojoyamarillo.BuildGLTexture();
	rojoyamarillo.ReleaseImage();

	azulyamarillo.LoadTGA("city/azulyamarillo.tga");
	azulyamarillo.BuildGLTexture();
	azulyamarillo.ReleaseImage();

	amarilloyamarillo.LoadTGA("city/amarilloyamarillo.tga");
	amarilloyamarillo.BuildGLTexture();
	amarilloyamarillo.ReleaseImage();

	verdeyamarillo.LoadTGA("city/verdeyamarillo.tga");
	verdeyamarillo.BuildGLTexture();
	verdeyamarillo.ReleaseImage();

	naranjayamarillo.LoadTGA("city/naranjayamarillo.tga");
	naranjayamarillo.BuildGLTexture();
	naranjayamarillo.ReleaseImage();

	piel.LoadTGA("city/piel.tga");
	piel.BuildGLTexture();
	piel.ReleaseImage();

	pelotat.LoadTGA("city/pelota.tga");
	pelotat.BuildGLTexture();
	pelotat.ReleaseImage();

	carapayaso.LoadTGA("city/caritapayaso.tga");
	carapayaso.BuildGLTexture();
	carapayaso.ReleaseImage();

	negro.LoadTGA("city/negro.tga");
	negro.BuildGLTexture();
	negro.ReleaseImage();

	hueso.LoadTGA("city/hueso.tga");
	hueso.BuildGLTexture();
	hueso.ReleaseImage();

	mantel.LoadTGA("city/mantel.tga");
	mantel.BuildGLTexture();
	mantel.ReleaseImage();

	metal.LoadTGA("city/metal.tga");
	metal.BuildGLTexture();
	metal.ReleaseImage();

	//END NEW//////////////////////////////

	//objCamera.Position_Camera(0,-35.5,20, 0,-10.5,10, 0, 10, 0);  //5.5 y - 2.5 y - 2 y
	objCamera.Position_Camera(0, -60.5f, 75, 0, -60.5f, 0, 0, 75, 0);
	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);

		
		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				if (!an_animacion) {
					glColor3f(.1, .1, .2);
				}
				cielo.skybox(100, 150, 150, sky.GLindex, tierra.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			//Carpa
			glPushMatrix();
				glDisable(GL_LIGHTING);
				glTranslatef(0, 0, -10);
				glTranslatef(0, -76, 0);
				if(!an_animacion){
					glColor3f(.1, .1, .2);
				}
				carpa.cilindro(40, 40, 10, circo.GLindex);
				glTranslatef(0, 41, 0);
				puntaCarpa.cono(30, 42, 40, circo.GLindex);
				glTranslatef(5, -31, 44);
				puertaI.prisma(20, 10, 14, circo.GLindex);
				glTranslatef(-10.2, 0, 0);
				glRotatef(180, 0, 1, 0);
				puertaD.prisma(20, 10, 14, circo.GLindex);
				glTranslatef(-6, 1, 42.5);
				bancas1.torus(35, 30, 6, 6, banca.GLindex);
				//glTranslatef(6, -6, 42.5);
				glTranslatef(0, -4, 0);
				bancas1.torus(32, 25, 6, 6, banca.GLindex);
				glTranslatef(0, -4, 0);
				bancas1.torus(27, 20, 6, 6, banca.GLindex);
				glTranslatef(0, -2, 2);
				glDisable(GL_LIGHTING);
				glColor3f(1, 1, 1);
				piso.cilindro(37, 0.5, 40, arena.GLindex);
				
				//Cuerdas para caminar 
				glTranslatef(-15, 30, 10);
				cuerda1I.cilindro(.5, 10, 40, arena.GLindex);
				glTranslatef(20, 0, 0);
				cuerda2I.cilindro(.5, 10, 40, arena.GLindex);
				glRotatef(90, 0, 0, 1);
				cuerda3.cilindro(.5, 20, 40, arena.GLindex);
				glDisable(GL_LIGHTING);
				//Aro para brincar 
				glTranslatef(-20, -5, 0);
				glTranslatef(salir, 0, 0);
				glRotatef(-90, 0, 0, 1);
				glTranslatef(-10, -30, -10);
				posteAro.cilindro(1, 6, 40, metal.GLindex);
				glRotatef(90, 0, 0, 1);
				glRotatef(90, 1, 0, 0);
				glTranslatef(12, 0, 0);
				aro.torus(6, 4, 40, 40, metal.GLindex);
				glTranslatef(-10, -12, 0);
				glPushMatrix();
					glRotatef(girar1, 1, 0, 0);
					base1.prisma5(7, 7, 7, mantel.GLindex, amarillo.GLindex);
				glPopMatrix();
				glTranslatef(0, 18.5, 0);
				glPushMatrix();
					glRotatef(girar1, 1, 0, 0);
					base2.prisma5(7, 7, 7, mantel.GLindex, amarillo.GLindex);
				glPopMatrix();
				glRotatef(270, 0, 0, 1);
				glRotatef(90, 0, 1, 0);
				glTranslatef(0, 5.5, 1);
				//animacion
				glTranslatef(0, saltar2, -saltar1);
				glRotatef(girar1, 0, 1, 0);
				glScalef(.5, .5, .5);
				glDisable(GL_LIGHTING);
				perro.perrito(saltar);
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHTING);
				glColor3f(1, 1, 1);
			glPopMatrix();
			glPushMatrix();
			if (an_animacion) {
				glDisable(GL_LIGHTING);
			}
			glColor3f(1, 1, 1);
				glPushMatrix();
					glTranslatef(0, -60.25, -36.6);
					glScalef(.2, .2, .2);
					persona.persona(rojo.GLindex, carita.GLindex, piel.GLindex, rojoyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(30, 0, 0);
					persona.persona(amarillo.GLindex, carita.GLindex, piel.GLindex, rosayamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(0, -16.0, 19.75);
					persona.persona(azul.GLindex, carita.GLindex, piel.GLindex, azulyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(25, 0, 0);
					persona.persona(rosa.GLindex, carita.GLindex, piel.GLindex, rosayamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(-10,-20, 22);
					persona.persona(verde.GLindex, carita.GLindex, piel.GLindex, verdeyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(-50, 0, 0);
					persona.persona(rojo.GLindex, carita.GLindex, piel.GLindex, rojoyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
				glPopMatrix();
				//siguientes personitas
				glPushMatrix();
					glTranslatef(-30.5, -61.0, -15);
					glScalef(.2, .2, .2);
					glRotatef(60, 0, 1, 0);
					glTranslatef(40, 3.5, 12);
					persona.persona(verde.GLindex, carita.GLindex, piel.GLindex, verdeyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(30, 0, 0);
					persona.persona(azul.GLindex, carita.GLindex, piel.GLindex, azulyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(30, 0, 0);
					persona.persona(amarillo.GLindex, carita.GLindex, piel.GLindex, amarilloyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(0, -16.0, 19.75);
					persona.persona(rojo.GLindex, carita.GLindex, piel.GLindex, rojoyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(-35, -19.5, 22);
					persona.persona(rosa.GLindex, carita.GLindex, piel.GLindex, rosayamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(-25,0,0);
					persona.persona(verde.GLindex, carita.GLindex, piel.GLindex, verdeyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
				glPopMatrix();
				//sig personas
				glPushMatrix();
					glRotatef(120, 0, 1, 0);
					glTranslatef(-3.0, -61.0, -25.25);
					glScalef(.2, .2, .2);
					glTranslatef(40, 3.5, 12);
					persona.persona(rojo.GLindex, carita.GLindex, piel.GLindex, rojoyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(30, 0, 0);
					persona.persona(verde.GLindex, carita.GLindex, piel.GLindex, verdeyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(30, 0, 0);
					persona.persona(amarillo.GLindex, carita.GLindex, piel.GLindex, amarilloyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(0, -16.0, 19.75);
					persona.persona(naranja.GLindex, carita.GLindex, piel.GLindex, naranjayamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(-35, -19.5, 22);
					persona.persona(verde.GLindex, carita.GLindex, piel.GLindex, verdeyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(-25, 0, 0);
					persona.persona(rosa.GLindex, carita.GLindex, piel.GLindex, rosayamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
				glPopMatrix();
				// sig 
				glPushMatrix();
					glTranslatef(10, -61.0, 22);
					glScalef(.2, .2, .2);
					glRotatef(180, 0, 1, 0);
					glTranslatef(40, 3.5, 12);
					persona.persona(rojo.GLindex, carita.GLindex, piel.GLindex, rojoyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(30, 0, 0);
					persona.persona(rosa.GLindex, carita.GLindex, piel.GLindex, rosayamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(0, -16.0, 19.75);
					persona.persona(verde.GLindex, carita.GLindex, piel.GLindex, verdeyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(25, 0, 0);
					persona.persona(azul.GLindex, carita.GLindex, piel.GLindex, azulyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(-10, -20, 22);
					persona.persona(verde.GLindex, carita.GLindex, piel.GLindex, verdeyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(-50, 0, 0);
					persona.persona(amarillo.GLindex, carita.GLindex, piel.GLindex, amarilloyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
				glPopMatrix();
				// siguientess
				glPushMatrix();
					glTranslatef(-6.55, -0.015, -13);
					glRotatef(-120, 0, 1, 0);
					glTranslatef(0, -60.25, -36.6);
					glScalef(.2, .2, .2);
					persona.persona(azul.GLindex, carita.GLindex, piel.GLindex, azulyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(30, 0, 0);
					persona.persona(verde.GLindex, carita.GLindex, piel.GLindex, verdeyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(0, -16.0, 19.75);
					persona.persona(naranja.GLindex, carita.GLindex, piel.GLindex, naranjayamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(25, 0, 0);
					persona.persona(rojo.GLindex, carita.GLindex, piel.GLindex, rojoyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(-10,-20, 22);
					persona.persona(verde.GLindex, carita.GLindex, piel.GLindex, verdeyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(-50, 0, 0);
					persona.persona(azul.GLindex, carita.GLindex, piel.GLindex, azulyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
				glPopMatrix();
				//ultimas personitas
				glPushMatrix();
					glTranslatef(23.0, -61.0, -31);
					glScalef(.2, .2, .2);
					glRotatef(-60, 0, 1, 0);
					glTranslatef(40, 3.5, 12);
					persona.persona(rosa.GLindex, carita.GLindex, piel.GLindex, rosayamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(30, 0, 0);
					persona.persona(verde.GLindex, carita.GLindex, piel.GLindex, verdeyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(30, 0, 0);
					persona.persona(rojo.GLindex, carita.GLindex, piel.GLindex, rojoyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(0, -16.0, 19.75);
					persona.persona(amarillo.GLindex, carita.GLindex, piel.GLindex, amarilloyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(-35, -19.5, 22);
					persona.persona(rojo.GLindex, carita.GLindex, piel.GLindex, rojoyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
					glTranslatef(-25, 0, 0);
					persona.persona(azul.GLindex, carita.GLindex, piel.GLindex, azulyamarillo.GLindex, 90.0, -3.7, 1.25, 8, 7.5, 0.0, 0.0);
				glPopMatrix();
				if (an_animacion) {
					glEnable(GL_LIGHTING);
				}
			glPopMatrix();
			glPushMatrix();
				glDisable(GL_LIGHTING);
				glTranslatef(0, ocultarpayaso, 0);
				glTranslatef(0, -71.6, 0);
				//Baticueva
				glTranslatef(girasilla1, 0, girasilla2);
				glRotatef(gira, 0, 1, 0);
				glPushMatrix();
					glRotatef(-girarpelota, 1, 0, 0);
					pelota.esfera(3, 30, 30, pelotat.GLindex);
				glPopMatrix();
				glScalef(0.2, 0.2, 0.2);
				glTranslatef(0, 46.5, 0);
				persona.persona(verde.GLindex, carapayaso.GLindex,azul.GLindex,rosa.GLindex, 0.0, 0.0, 0.0, 0.0, 0.0, pasos1, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix();
			if (an_animacion)
			{
				glDisable(GL_LIGHTING);
			}
				glTranslatef(-3, -41.35, -20.51);
				glRotatef(90, 0, 1, 0);
				glScalef(.1, .1, .1);
				glTranslatef(0, 0, movtraspes);
				glRotatef(giratraspes, 0, 1, 0);
				persona.persona(azul.GLindex, carita.GLindex,azul.GLindex,azul.GLindex, 0.0, 0.0, 0.0, 0.0, 0.0,caminar3, caminar2);
			if (an_animacion)
			{
				glEnable(GL_LIGHTING);
			}
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0, .5, -10);
				glScalef(abrepuertas, 1, abrepuertas);
				glTranslatef(0, -75, 0);
				placas.prisma(.2, 2, 2, NULL);
			glPopMatrix();
			//inician las personas 
			glPushMatrix();
				glTranslatef(55, -68.5, 40);
				glRotatef(-80, 0, 1, 0);
				glTranslatef(0, 0, movpersona2);
				glScalef(.2, .2, .2);
				glRotatef(girapersona2, 0, 1, 0);
				persona.persona(rojo.GLindex, carita.GLindex, piel.GLindex,rojoyamarillo.GLindex,0, 0, 0, 0, 0,caminar1,0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(52, -68.5, 35);
				glRotatef(-65, 0, 1, 0);
				glTranslatef(0, 0, movpersona2);
				glScalef(.2, .2, .2);
				glRotatef(girapersona2, 0, 1, 0);
				persona.persona(amarillo.GLindex, carita.GLindex, piel.GLindex,amarilloyamarillo.GLindex,0, 0, 0, 0, 0, caminar5, 0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-42, -68.5, 80);
				glRotatef(180, 0, 1, 0);
				glTranslatef(0, 0, 1.5*movpersona);
				glScalef(.2, .2, .2);
				glRotatef(girapersona, 0, 1, 0);
				persona.persona(azul.GLindex, carita.GLindex, piel.GLindex,azulyamarillo.GLindex,0, 0, 0, 0, 0, caminar1, 0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-55, -68.5, 70);
				glRotatef(90, 0, 1, 0);
				glTranslatef(0, 0, movpersona);
				glScalef(.2, .2, .2);
				glRotatef(girapersona, 0, 1, 0);
				persona.persona(verde.GLindex, carita.GLindex, piel.GLindex,verdeyamarillo.GLindex,0, 0, 0, 0, 0, caminar1, 0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-40, -68.5, 70);
				glRotatef(113, 0, 1, 0);
				glTranslatef(0, 0, movpersona);
				glScalef(.2, .2, .2);
				glRotatef(girapersona, 0, 1, 0);
				persona.persona(naranja.GLindex, carita.GLindex, piel.GLindex,naranjayamarillo.GLindex,0, 0, 0, 0, 0, caminar1, 0);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-52, -68.5, 29);
				glRotatef(65, 0, 1, 0);
				glTranslatef(0, 0, movpersona2);
				glScalef(.2, .2, .2);
				glRotatef(girapersona2, 0, 1, 0);
				persona.persona(rosa.GLindex,carita.GLindex, piel.GLindex,rosayamarillo.GLindex,0, 0, 0, 0, 0, caminar5, 0);
			glPopMatrix();
			glPushMatrix();
			glColor3f(1, 1, 1);
				glDisable(GL_LIGHTING);
				glTranslatef(0, -45, 28.5);
				glScalef(12, 10, .5);
				letrero.prisma2(circocartel.GLindex, circocartel.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(20, -75, 35);
				lampara.cilindro(5, 6, 20, negro.GLindex);
				glTranslatef(0, 6, 0);
				glRotatef(giraproyector1, 0, 0, 1);
				glRotatef(giraproyector2, 1, 0, 0);
				proyector.esfera(3.5, 10, 10, amarillo.GLindex);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glRotatef(180, 1, 0, 0);
				glTranslatef(0, -40, 0);
				if (!an_animacion) {
					conito.cono(40, 6, 20, hueso.GLindex);
				}
				glDisable(GL_BLEND);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-20, -75, 35);
				lampara.cilindro(5, 6, 20, negro.GLindex);
				glTranslatef(0, 6, 0);
				glRotatef(-giraproyector1, 0, 0, 1);
				glRotatef(giraproyector2, 1, 0, 0);
				proyector.esfera(3.5, 10, 10, amarillo.GLindex);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glRotatef(180, 1, 0, 0);
				glTranslatef(0, -40, 0);
				if (!an_animacion) {
					conito.cono(40, 6, 20, hueso.GLindex);
				}
				glDisable(GL_BLEND);
			glPopMatrix();
			//Llamada la ciudad, se agrega carretera 
			glPushMatrix();
				glEnable ( GL_COLOR_MATERIAL );
					glColor3f(1, 1, 1);
					glCallList(ciudad_display_list);
				glDisable ( GL_COLOR_MATERIAL );
			glPopMatrix();
		glPopMatrix();
		
	glPopMatrix();
	
	glutSwapBuffers ( );
}

void animacion()
{
		//###########Acto salta perrito#################
		if (m_animacion) {
			saltar += 1.0;
			if (saltar >= 15) {
				m_animacion = false;
				n_animacion = true;
			}
		}
		if (n_animacion) {
			vx -= 0.14;
			vy += 0.1;
			saltar1 = vx;
			saltar2 = vy;
			if (saltar2 >= 5) {
				n_animacion = false;
				o_animacion = true;
			}
		}
		if (o_animacion) {
			vx -= .2;
			vy -= .1;
			saltar1 = vx;
			saltar2 = vy;
			if (saltar2 <= 0) {
				o_animacion = false;
				t_animacion = true;
			}
		}
		if (t_animacion) {
			saltar -= 1.0;
			if (saltar <= 0) {
				t_animacion = false;
				p_animacion = true;
			}
		}
		if (p_animacion) {
			girar1 += 1.0;
			if (girar1 == 180) {
				p_animacion = false;
				u_animacion = true;
			}
		}
		if (u_animacion) {
			saltar += 1.0;
			if (saltar >= 15) {
				u_animacion = false;
				q_animacion = true;
			}
		}
		if (q_animacion) {
			vx += .14;
			vy += .1;
			saltar1 = vx;
			saltar2 = vy;
			if (saltar2 >= 5.5) {
				q_animacion = false;
				r_animacion = true;
			}
		}
		if (r_animacion) {
			vx += .2;
			vy -= .1;
			saltar1 = vx;
			saltar2 = vy;
			if (saltar2 <= 0) {
				r_animacion = false;
				v_animacion = true;
				vx = 0;
				vy = 0;
			}
		}
		if (v_animacion) {
			saltar -= 1.0;
			if (saltar <= 0) {
				v_animacion = false;
				s_animacion = true;
			}
		}

		if (s_animacion) {
			girar1 -= 1.0;
			if (girar1 == 0) {
				s_animacion = false;
			}
		}
		//#######Salir#################
		if (w_animacion) {
			salir  += .2;
			if (salir >= 20) {
				w_animacion = false;
				ae_animacion = true;
			}
		}
		if (x_animacion) {
			salir -= .2;
			if (salir <= 1) {
				x_animacion = false;
				ac_animacion = true;
				//ae_animacion = true;
			}
		}
		//######Payaso caminando#######
		if (y_animacion) {
			pasos1 += 0.5;
			if (pasos1 >= 10) {
				y_animacion = false;
				z_animacion = true;
			}
		}
		if (z_animacion) {
			pasos1 -= 0.5;
			if (pasos1 <= 0) {
				z_animacion = false;
				y_animacion = true;
			}
		}
		if (aa_animacion) {
			girarpelota += 1.0;
		}
		//De la baticueva
		if (f_silla)
		{
			girasilla1 -= .1;
			gira -= 1;
			if (girasilla1 <= -5.0)
			{
				f_silla = false;
				g_silla = true;

			}
		}
		if (g_silla)
		{
			gira -= 1;
			girasilla2 -= 0.1;
			if (girasilla2 <= -15)
			{
				h_silla = true;
				g_silla = false;
			}
		}
		if (h_silla) {
			girasilla1 += 0.1;
			gira -= 1;
			if (girasilla1 >= 9.0)
			{
				i_silla = true;
				h_silla = false;

			}
		}
		if (i_silla) {
			gira -= 1;
			girasilla2 += 0.1;
			if (girasilla2 >= 4)
			{
				i_silla = false;
				f_silla = true;

			}
		}
		if (ab_animacion) {
			ocultarpayaso -= 1.0;
			if (ocultarpayaso <= -20) {
				ab_animacion = false;
				w_animacion = true;
				// ae_animacion = true;
			}
		}
		if (ac_animacion) {
			ocultarpayaso += 1.0;
			if (ocultarpayaso >= 0) {
				ac_animacion = false;
				g_animacion = true;
				//ae_animacion = true;
			}
		}
		//#####Abrir placas##############
		if (ad_animacion) {
			abrepuertas += .5;
			if (abrepuertas > 12) {
				ad_animacion = false;
				ab_animacion = true;
			}
		}
		if (ae_animacion) {
			abrepuertas -= .5;
			if (abrepuertas < .1) {
				ae_animacion = false;
			}
		}
		if (f_animacion) {
			abrepuertas += .5;
			if (abrepuertas > 12) {
				f_animacion = false;
				x_animacion = true;
				//ab_animacion = true;
			}
		}
		if (g_animacion) {
			abrepuertas -= .5;
			if (abrepuertas < .1) {
				g_animacion = false;
			}
		}
		//#########Caminar de las personas######
		if (af_animacion) {
			movpersona += .5;
			if (movpersona >= 110) {
				af_animacion = false;
				ag_animacion = true;
			}
		}
		if (ag_animacion) {
			girapersona += 10;
			if (girapersona >= 180) {
				ag_animacion = false;
				ah_animacion = true;
				aw_animacion = true;
			}
		}
		if (ah_animacion) {
			movpersona -= .5;
			if (movpersona <= 0) {
				ah_animacion = false;
				ai_animacion = true;
			}
		}
		if (ai_animacion) {
			girapersona -= 10;
			if (girapersona <= 0) {
				ai_animacion = false;
				af_animacion = true;
			}
		}
		if (as_animacion) {
			caminar1 += 1;
			if (caminar1 >= 10) {
				as_animacion = false;
				at_animacion = true;
			}
		}
		if (at_animacion) {
			caminar1 -= 1;
			if (caminar1 <= 0) {
				at_animacion = false;
				as_animacion = true;
			}
		}
		//#####################
		if (aw_animacion) {
			movpersona2 += .5;
			if (movpersona2 >= 110) {
				aw_animacion = false;
				ax_animacion = true;
			}
		}
		if (ax_animacion) {
			girapersona2 += 10;
			if (girapersona2 >= 180) {
				ax_animacion = false;
				ay_animacion = true;
			}
		}
		if (ay_animacion) {
			movpersona2 -= .5;
			if (movpersona2 <= 0) {
				ay_animacion = false;
				az_animacion = true;
			}
		}
		if (az_animacion) {
			girapersona2 -= 10;
			if (girapersona2 <= 0) {
				az_animacion = false;
				aw_animacion = true;
			}
		}
		if (ba_animacion) {
			caminar5 += 1;
			if (caminar5 >= 10) {
				ba_animacion = false;
				bb_animacion = true;
			}
		}
		if (bb_animacion) {
			caminar5 -= 1;
			if (caminar1 <= 0) {
				bb_animacion = false;
				ba_animacion = true;
			}
		}
		//#################
		//####Animacion trapesista######
		if (aj_animacion) {
			movtraspes += .5;
			if (movtraspes >= 170) {
				aj_animacion = false;
				ak_animacion = true;
			}
		}
		if (ak_animacion) {
			giratraspes += 5;
			if (giratraspes >= 180) {
				ak_animacion = false;
				al_animacion = true;
			}
		}
		if (al_animacion) {
			movtraspes -= .5;
			if (movtraspes <= 10) {
				al_animacion = false;
				am_animacion = true;
			}
		}
		if (am_animacion) {
			giratraspes -= 1;
			if (giratraspes <= 0) {
				am_animacion = false;
				aj_animacion = true;
			}
		}
		if (au_animacion) {
			caminar3 += 1;
			caminar2 += 1;
			if (caminar3 >= 10) {
				au_animacion = false;
				av_animacion = true;
			}
		}
		if (av_animacion) {
			caminar3 -= 1;
			caminar2 -= 1;
			if (caminar3 <= 0) {
				av_animacion = false;
				au_animacion = true;
			}
		}
		//######proyectores##########
		if (ao_animacion){
			giraproyector1 += 1;
			if (giraproyector1 >= 45) {
				ao_animacion = false;
				ap_animacion = true;
			}
		}
		if (ap_animacion) {
			giraproyector2 += 1;
			if (giraproyector2 >= 180) {
				ap_animacion = false;
				aq_animacion = true;
			}
		}
		if (aq_animacion) {
			giraproyector1 -= 1;
			if (giraproyector1 <= 0) {
				aq_animacion = false;
				ar_animacion = true;
			}
		}
		if (ar_animacion) {
			giraproyector2 -= 1;
			if (giraproyector2 <= 0) {
				ar_animacion = false;
				ao_animacion = true;
			}
		}
		glutPostRedisplay();
}


void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.1 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.1));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.2));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'i':
		case 'I':
			if (m_animacion) {
				m_animacion = false;
			}
			else {
				m_animacion = true;
			}
			break;
		case 'z':
		case 'Z':
			//mostar el aro y el perrito, aun no queda 
			if (ad_animacion) {
				ad_animacion = false;
			}
			else {
				ad_animacion = true;
			}
			break;
		case 'r':
		case 'R':
			if (f_animacion) {
				f_animacion = false;
			}
			else {
				f_animacion = true;
			}
			break;

		case 'O':
		case 'o':
			if (f_silla | g_silla | h_silla | i_silla | y_animacion | aa_animacion | z_animacion)
			{
				f_silla = false;
				g_silla = false;
				h_silla = false;
				i_silla = false;
				y_animacion = false;
				aa_animacion = false;
				z_animacion = false;
			}
			else
			{
				y_animacion = true;
				aa_animacion = true;
				f_silla = true;
			}
			break;
		case 'q':
		case 'Q':
			if (ad_animacion) {
				ad_animacion = false;
			}
			else {
				ad_animacion = true;
			}
			break;

		case 'y':
		case 'Y':
			if (an_animacion) {
				an_animacion = false;
			}
			else {
				an_animacion = true;
			}
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;  
		
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto Final"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc        ( animacion );

  glutMainLoop        ( );          // 

  return 0;
}
