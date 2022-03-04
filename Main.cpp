#include <stdlib.h>
#include <GL/glut.h>

static int shoulder1_y = 0, elbow1_y = 0, shoulder2_y = 0, elbow2_y = 0, elbow1_x = 0, elbow2_x = 0, upper_body = 0
, thumb_1_Base = 0, thumb_1_Up = 0, thumb_2_Base = 0, thumb_2_Up = 0, fingers_1_Base = 0, fingers_1_Up = 0
, fingers_2_Base = 0, fingers_2_Up = 0, shoulder1_x = 0, shoulder2_x = 0, leg1_y = 0, leg2_y = 0, leg1_z = 0, leg2_z = 0
, knee1_z = 0, knee2_z = 0;
int moving, startx, starty;

GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;  /* in degrees */

static GLfloat z_eye = 10.0; // z coordinate to zoom in or out
static GLfloat x_eye = 0.0;
static GLfloat y_eye = 0.0;
static GLfloat rotation_angle = 0;
static GLfloat rotation_angle_y = 0;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void)
{
	//shoulder & elbow
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x_eye, y_eye, z_eye, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(rotation_angle, 1.0, 0.0, 0.0);
	glRotatef(rotation_angle_y, 0.0, 1.0, 0.0);

	glPushMatrix();
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef((GLfloat)upper_body, 1.0, 0.0, 0.0);
	glTranslatef(1.5, 2.0, 0.0);
	glRotatef((GLfloat)shoulder1_y, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)shoulder1_x, 0.0, 1.0, 0.0);
	glPushMatrix();
	glScalef(0.7, 1.0, 0.4);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(0.0, -0.5, 0.0);
	glRotatef((GLfloat)elbow1_y, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)elbow1_x, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.5, 0.0);
	glPushMatrix();
	glScalef(0.7, 1, 0.4);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(0, -0.5, 0.15);

	//Draw finger finger_1_Base 
	glPushMatrix();
	glRotatef((GLfloat)thumb_1_Base, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.15, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	//Draw finger finger_1_Up
	glTranslatef(0.0, -0.15, 0.0);
	glRotatef((GLfloat)thumb_1_Up, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.15, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();

	//Draw finger finger_2_Base 
	glTranslatef(0.3, 0.0, -0.3);
	glPushMatrix();
	glRotatef((GLfloat)fingers_1_Base, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.15, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	//Draw finger finger_3_Base 
	glPushMatrix();
	glTranslatef(-0.2, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();
	//Draw finger finger_4_Base 
	glPushMatrix();
	glTranslatef(-0.4, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();
	//Draw finger finger_5_Base 
	glPushMatrix();
	glTranslatef(-0.6, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();

	//Draw finger finger_2_Up 
	glTranslatef(0.0, -0.15, 0.0);
	glRotatef((GLfloat)fingers_1_Up, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.15, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	//Draw finger finger_3_Up
	glPushMatrix();
	glTranslatef(-0.2, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();
	//Draw finger finger_4_Up
	glPushMatrix();
	glTranslatef(-0.4, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();
	//Draw finger finger_5_Up
	glPushMatrix();
	glTranslatef(-0.6, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	//Draw body
	glPushMatrix();
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef((GLfloat)upper_body, 1.0, 0.0, 0.0);
	glScalef(1.8, 2.8, 0.4);
	glTranslatef(0.0, 0.5, 0.0);
	glutWireCube(1);
	glPopMatrix();

	//Draw second Arm
	glPushMatrix();
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef((GLfloat)upper_body, 1.0, 0.0, 0.0);
	glTranslatef(-1.5, 2.0, 0.0);
	glRotatef((GLfloat)shoulder2_y, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)shoulder2_x, 0.0, 1.0, 0.0);
	glPushMatrix();
	glScalef(0.7, 1.0, 0.4);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(0.0, -0.5, 0.0);
	glRotatef((GLfloat)elbow2_y, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)elbow2_x, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.5, 0.0);
	glPushMatrix();
	glScalef(0.7, 1, 0.4);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(0, -0.5, 0.15);

	//Draw finger finger_1_Base 
	glPushMatrix();
	glRotatef((GLfloat)thumb_2_Base, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.15, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	//Draw finger finger_1_Up
	glTranslatef(0.0, -0.15, 0.0);
	glRotatef((GLfloat)thumb_2_Up, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.15, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();

	//Draw finger finger_2_Base 
	glTranslatef(0.3, 0.0, -0.3);
	glPushMatrix();
	glRotatef((GLfloat)fingers_2_Base, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.15, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	//Draw finger finger_3_Base 
	glPushMatrix();
	glTranslatef(-0.2, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();
	//Draw finger finger_4_Base 
	glPushMatrix();
	glTranslatef(-0.4, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();
	//Draw finger finger_5_Base 
	glPushMatrix();
	glTranslatef(-0.6, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();

	//Draw finger finger_2_Up 
	glTranslatef(0.0, -0.15, 0.0);
	glRotatef((GLfloat)fingers_2_Up, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.15, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	//Draw finger finger_3_Up
	glPushMatrix();
	glTranslatef(-0.2, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();
	//Draw finger finger_4_Up
	glPushMatrix();
	glTranslatef(-0.4, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();
	//Draw finger finger_5_Up
	glPushMatrix();
	glTranslatef(-0.6, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.1, 0.3, 0.1);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	//Draw the head
	glPushMatrix();
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef((GLfloat)upper_body, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 3.5, 0.0);
	glScalef(0.5, 0.5, 0.5);
	glutWireSphere(1, 12, 18);
	glPopMatrix();
	glPopMatrix();


	//Draw first leg
	glPushMatrix();
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glTranslatef(-0.65, 0, 0.0);
	glRotatef((GLfloat)leg1_y, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)leg1_z, 1.0, 0.0, 0.0);
	glTranslatef(0, -0.75, 0.0);
	glPushMatrix();
	glScalef(0.5, 1.5, 0.4);
	glutWireCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, -0.75, 0.0);
	glRotatef((GLfloat)knee1_z, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.75, 0.0);
	glScalef(0.5, 1.5, 0.4);
	glutWireCube(1);
	glPopMatrix();
	glTranslatef(0.0, -0.75, 0.0);
	glRotatef((GLfloat)knee1_z, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -1.65, 0.0);
	glScalef(0.5, 0.5, 1.0);
	glutSolidCube(1);
	glPopMatrix();


	//Draw second leg
	glPushMatrix();
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glTranslatef(0.65, 0, 0.0);
	glRotatef((GLfloat)leg2_y, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)leg2_z, 1.0, 0.0, 0.0);
	glTranslatef(0, -0.74, 0.0);
	glPushMatrix();
	glScalef(0.5, 1.5, 0.4);
	glutWireCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.75, 0.0);
	glRotatef((GLfloat)knee2_z, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.75, 0.0);
	glScalef(0.5, 1.5, 0.4);
	glutWireCube(1);
	glPopMatrix();
	glTranslatef(0.0, -0.75, 0.0);
	glRotatef((GLfloat)knee2_z, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -1.65, 0.0);
	glScalef(0.5, 0.5, 1.0);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();

}


void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glTranslatef(0.0, 0.0, -5.0);
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		/* Zoom out */
	case 'z':
		z_eye += 0.5;
		if (z_eye >= 10) z_eye = 10;
		glutPostRedisplay();
		break;

		/* Zoom in */
	case 'Z':
		z_eye -= 0.5;
		if (z_eye <= 0) z_eye = 0.5;
		glutPostRedisplay();
		break;


		//Movement of The First Arm
	case 'q':
		if (shoulder1_y < 170)
		{
			shoulder1_y = (shoulder1_y + 5);
		}
		glutPostRedisplay();
		break;

	case 'Q':
		if (shoulder1_y > 0)
		{
			shoulder1_y = (shoulder1_y - 5);
		}
		glutPostRedisplay();
		break;

	case 'w':
		if (shoulder1_x > -45)
		{
			shoulder1_x = (shoulder1_x - 5);
		}
		glutPostRedisplay();
		break;

	case 'W':
		if (shoulder1_x < 45)
		{
			shoulder1_x = (shoulder1_x + 5);
		}
		glutPostRedisplay();
		break;

	case 'e':
		if (elbow1_y < 140)
		{
			elbow1_y = (elbow1_y + 5);
		}
		glutPostRedisplay();
		break;

	case 'E':
		if (elbow1_y > -45)
		{
			elbow1_y = (elbow1_y - 5);
		}
		glutPostRedisplay();
		break;

	case 'r':
		if (elbow1_x > -90)
		{
			elbow1_x = (elbow1_x - 5);
		}
		glutPostRedisplay();
		break;

	case 'R':
		if (elbow1_x < 0)
		{
			elbow1_x = (elbow1_x + 5);
		}
		glutPostRedisplay();
		break;

		// Movement of first hand
	case 't':

		if (thumb_1_Base < 90)
		{
			thumb_1_Base = (thumb_1_Base + 5);
		}

		glutPostRedisplay();
		break;

	case 'T':
		if (thumb_1_Base > 0)
		{
			thumb_1_Base = (thumb_1_Base - 5);
		}
		glutPostRedisplay();
		break;

	case 'y':
		if (thumb_1_Up < 90)
		{
			thumb_1_Up = (thumb_1_Up + 5);
		}
		glutPostRedisplay();
		break;

	case 'Y':
		if (thumb_1_Up > 0)
		{
			thumb_1_Up = (thumb_1_Up - 5);
		}
		glutPostRedisplay();
		break;

	case 'u':
		if (fingers_1_Base > -90)
		{
			fingers_1_Base = (fingers_1_Base - 5);
		}
		glutPostRedisplay();
		break;

	case 'U':
		if (fingers_1_Base < 0)
		{
			fingers_1_Base = (fingers_1_Base + 5);
		}
		glutPostRedisplay();
		break;

	case 'i':
		if (fingers_1_Up > -90)
		{
			fingers_1_Up = (fingers_1_Up - 5);
		}
		glutPostRedisplay();
		break;

	case 'I':
		if (fingers_1_Up < 0)
		{
			fingers_1_Up = (fingers_1_Up + 5);
		}
		glutPostRedisplay();
		break;


		// Movement of The Second Arm
	case 'a':
		if (shoulder2_y > -170)
		{
			shoulder2_y = (shoulder2_y - 5);
		}
		glutPostRedisplay();
		break;

	case 'A':
		if (shoulder2_y < 0)
		{
			shoulder2_y = (shoulder2_y + 5);
		}
		glutPostRedisplay();
		break;

	case 's':
		if (shoulder2_x < 45)
		{
			shoulder2_x = (shoulder2_x + 5);
		}
		glutPostRedisplay();
		break;

	case 'S':
		if (shoulder2_x > -45)
		{
			shoulder2_x = (shoulder2_x - 5);
		}
		glutPostRedisplay();
		break;

	case 'd':
		if (elbow2_y > -140)
		{
			elbow2_y = (elbow2_y - 5);
		}
		glutPostRedisplay();
		break;

	case 'D':
		if (elbow2_y < 45)
		{
			elbow2_y = (elbow2_y + 5);
		}
		glutPostRedisplay();
		break;

	case 'f':
		if (elbow2_x > -90)
		{
			elbow2_x = (elbow2_x - 5);
		}

		glutPostRedisplay();
		break;

	case 'F':
		if (elbow2_x < 0)
		{
			elbow2_x = (elbow2_x + 5);
		}
		glutPostRedisplay();
		break;

		// Movement of second hand
	case 'g':

		if (thumb_2_Base < 90)
		{
			thumb_2_Base = (thumb_2_Base + 5);
		}
		glutPostRedisplay();
		break;

	case 'G':
		if (thumb_2_Base > 0)
		{
			thumb_2_Base = (thumb_2_Base - 5);
		}
		glutPostRedisplay();
		break;

	case 'h':
		if (thumb_2_Up < 90)
		{
			thumb_2_Up = (thumb_2_Up + 5);
		}
		glutPostRedisplay();
		break;

	case 'H':
		if (thumb_2_Up > 0)
		{
			thumb_2_Up = (thumb_2_Up - 5);
		}
		glutPostRedisplay();
		break;

	case 'j':
		if (fingers_2_Base > -90)
		{
			fingers_2_Base = (fingers_2_Base - 5);
		}
		glutPostRedisplay();
		break;

	case 'J':
		if (fingers_2_Base < 0)
		{
			fingers_2_Base = (fingers_2_Base + 5);
		}
		glutPostRedisplay();
		break;

	case 'k':
		if (fingers_2_Up > -90)
		{
			fingers_2_Up = (fingers_2_Up - 5);
		}
		glutPostRedisplay();
		break;

	case 'K':
		if (fingers_2_Up < 0)
		{
			fingers_2_Up = (fingers_2_Up + 5);
		}
		glutPostRedisplay();
		break;

		//  Body movement
	case 'l':
		if (upper_body < 90)
		{
			upper_body = (upper_body + 5);
		}
		glutPostRedisplay();
		break;

	case 'L':
		if (upper_body > 0)
		{
			upper_body = (upper_body - 5);
		}
		glutPostRedisplay();
		break;


		// Movement of lower body
		// Movement of lEG 1
	case 'm':
		if (leg1_y > -60)
		{
			leg1_y = (leg1_y - 5);
		}
		glutPostRedisplay();
		break;

	case 'M':
		if (leg1_y < 0)
		{
			leg1_y = (leg1_y + 5);
		}
		glutPostRedisplay();
		break;

	case 'n':
		if (leg1_z < 0)
		{
			leg1_z = (leg1_z + 5);
		}
		glutPostRedisplay();
		break;

	case 'N':
		if (leg1_z > -90)
		{
			leg1_z = (leg1_z - 5);
		}
		glutPostRedisplay();
		break;

	case 'b':
		if (knee1_z < 90)
		{
			knee1_z = (knee1_z + 5);
		}
		glutPostRedisplay();
		break;

	case 'B':
		if (knee1_z > 0)
		{
			knee1_z = (knee1_z - 5);
		}
		glutPostRedisplay();
		break;


		// Movement of lEG 2
	case 'v':
		if (leg2_y < 60)
		{
			leg2_y = (leg2_y + 5);
		}
		glutPostRedisplay();
		break;

	case 'V':
		if (leg2_y > 0)
		{
			leg2_y = (leg2_y - 5);
		}
		glutPostRedisplay();
		break;

	case 'c':
		if (leg2_z < 0)
		{
			leg2_z = (leg2_z + 5);
		}

		glutPostRedisplay();
		break;

	case 'C':
		if (leg2_z > -90)
		{
			leg2_z = (leg2_z - 5);
		}
		glutPostRedisplay();
		break;


	case 'x':
		if (knee2_z < 90)
		{
			knee2_z = (knee2_z + 5);
		}
		glutPostRedisplay();
		break;

	case 'X':
		if (knee2_z > 0)
		{
			knee2_z = (knee2_z - 5);
		}
		glutPostRedisplay();
		break;

	case 27:
		exit(0);
		break;

	default:
		break;
	}
}

static void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			moving = 1;
			startx = x;
			starty = y;
		}
		if (state == GLUT_UP) {
			moving = 0;
		}
	}
}


static void motion(int x, int y)
{
	if (moving) {
		angle = angle + (x - startx);
		angle2 = angle2 + (y - starty);
		startx = x;
		starty = y;
		glutPostRedisplay();
	}
}

void SpecialInput(int key, int x, int y)
{
	switch (key)
	{

		/* rotate around x-axis up */
	case GLUT_KEY_UP:
		rotation_angle -= 10;
		if (rotation_angle <= -90) rotation_angle = -90;
		glutPostRedisplay();
		break;

		/* rotate around x-axis down */
	case GLUT_KEY_DOWN:
		rotation_angle += 10;
		if (rotation_angle >= 90) rotation_angle = 90;
		glutPostRedisplay();
		break;

		/* rotate around y-axis left */
	case GLUT_KEY_LEFT:
		rotation_angle_y -= 10;
		if (rotation_angle_y <= -90) rotation_angle_y = -90;
		glutPostRedisplay();
		break;

		/* rotate around y-axis right */
	case GLUT_KEY_RIGHT:
		rotation_angle_y += 10;
		if (rotation_angle_y >= 90) rotation_angle_y = 90;
		glutPostRedisplay();
		break;
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(SpecialInput);
	glutMainLoop();
	return 0;
}
