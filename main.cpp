#define ROTATE_DELTA 2.0f
#define MOVE_DELTA 2.0f

#include "main.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <Windows.h>

static float move_x = 0.0f, dmov_x = 0.0f;
static float move_y = 0.0f, dmov_y = 0.0f;
static float move_z = 0.0f, dmov_z = 0.0f;

static float rotate_x = 0.0f, drot_x = 0.0f;
static float rotate_y = 0.0f, drot_y = 0.0f;
static float rotate_z = 0.0f, drot_z = 0.0f;

static void key_callback(GLFWwindow* window, int key, int scancode,
	int action, int mods)
{
	// quit application when the user presses ESC
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}


	if (key == GLFW_KEY_Q && action == GLFW_PRESS) drot_z = -ROTATE_DELTA;
	if (key == GLFW_KEY_Q && action == GLFW_RELEASE) drot_z = 0.0f;
	if (key == GLFW_KEY_W && action == GLFW_PRESS) drot_z = ROTATE_DELTA;
	if (key == GLFW_KEY_W && action == GLFW_RELEASE) drot_z = 0.0f;

	if (key == GLFW_KEY_A && action == GLFW_PRESS) drot_y = -ROTATE_DELTA;
	if (key == GLFW_KEY_A && action == GLFW_RELEASE) drot_y = 0.0f;
	if (key == GLFW_KEY_S && action == GLFW_PRESS) drot_y = ROTATE_DELTA;
	if (key == GLFW_KEY_S && action == GLFW_RELEASE) drot_y = 0.0f;

	if (key == GLFW_KEY_Z && action == GLFW_PRESS) drot_x = -ROTATE_DELTA;
	if (key == GLFW_KEY_Z && action == GLFW_RELEASE) drot_x = 0.0f;
	if (key == GLFW_KEY_X && action == GLFW_PRESS) drot_x = ROTATE_DELTA;
	if (key == GLFW_KEY_X && action == GLFW_RELEASE) drot_x = 0.0f;



	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) dmov_x = -MOVE_DELTA;
	if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE) dmov_x = 0.0f;
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) dmov_x = MOVE_DELTA;
	if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE) dmov_x = 0.0f;

	if (key == GLFW_KEY_UP && action == GLFW_PRESS) dmov_y = MOVE_DELTA;
	if (key == GLFW_KEY_UP && action == GLFW_RELEASE) dmov_y = 0.0f;
	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) dmov_y = -MOVE_DELTA;
	if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE) dmov_y = 0.0f;

	if (key == GLFW_KEY_E && action == GLFW_PRESS) dmov_z = MOVE_DELTA;
	if (key == GLFW_KEY_E && action == GLFW_RELEASE) dmov_z = 0.0f;
	if (key == GLFW_KEY_D && action == GLFW_PRESS) dmov_z = -MOVE_DELTA;
	if (key == GLFW_KEY_D && action == GLFW_RELEASE) dmov_z = 0.0f;


}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void initLightAndMaterial()     // lighting and material settings
{
	glEnable(GL_LIGHTING);     // lighting ON
	glEnable(GL_LIGHT0);       // light source #0 ON

	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	//GLfloat position[] = { 0.0f, 10.0f, 0.0f, 0 };
	//GLfloat direction[] = { 0.0f, 0.0f, 0.0f };

	// GLfloat ambient[] = { 1.0, 1.0, 1.0, 0.0 };
	// GLfloat diffuse[] = { 1.0, 1.0, 1.0, 0.0 };
	// GLfloat specular[] = { 1.0, 1.0, 1.0, 0.0 };
	// GLfloat position[] = { 0.0f, 100.0f, 0.0f, 0 };


	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	//glLightfv(GL_LIGHT0, GL_POSITION, position);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);


	// material color          R    G    B  alpha 

	GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_emissive[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_shininess[] = { 0.0 };

	// GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 0.0 };
	// GLfloat mat_diffuse[] = { 0.6, 0.6, 0.6, 0.0 };
	// GLfloat mat_specular[] = { 0.2, 0.2, 0.2, 0.0 };
	// GLfloat mat_emissive[] = { 0.0, 0.0, 0.0, 0.0 };
	// GLfloat mat_shininess[] = { 60.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emissive);
}

int main(int argc, char* argv[])
{
	HWND hConsole = GetConsoleWindow();
	ShowWindow(hConsole, SW_HIDE);


	std::vector<triangle> facet;
	double x_min, x_max;
	double y_min, y_max;
	double z_min, z_max;

	{
		std::ifstream inputListFile;
		std::string listFileName = "./stllist.txt";

		std::vector<std::string> fileName;


		inputListFile.open((listFileName).c_str(), std::ifstream::in);

		if (inputListFile.fail())
		{
			std::cout << "ERROR: STL list load failed" << std::endl;
			exit(1);
		}


		std::cout << "STL list : ";
		while (!inputListFile.eof())
		{
			std::string str;
			std::getline(inputListFile, str);
			std::cout << "[" + str + "]";
			fileName.push_back(str + ".stl");
		}

		inputListFile.close();
		std::cout << std::endl;


		double offset = 40.0f;
		//double offset = 0.0f;
		std::cout << "offset : " << offset << std::endl;

		for (int i = 0; i < 10; ++i) {
			std::cout << "Read " << fileName[i] << std::endl;
			readBinarySTL(fileName[i], facet, x_min, x_max, y_min, y_max, z_min, z_max, offset);
		}

		std::cout << "Total triangles in the STL file : " << facet.size() << std::endl;
	}

	//-------------------------------------------------------
	// calculate translation parameters to move the center of the geometry approximately to the origin
	//-------------------------------------------------------
	float x_center = (float)(x_min + x_max) / 3.0f;
	float y_center = (float)(y_min + y_max) / 3.0f;
	float z_center = (float)(z_min + z_max) / 3.0f;

	// translation along X,Y,Z
	move_x = 0.0f;// - x_center;
	move_y = 0.0f;// - y_center;
	move_z = 0.0f;// - z_center;

	std::cout << "x,y,z center : " << x_center << y_center << z_center << std::endl;

	std::cout << "x,y,z max/min: ("
		<< x_max << "," << x_min << ")("
		<< y_max << "/" << y_min << ")("
		<< z_max << "/" << z_min << ")"
		<< std::endl;

	std::cout << "Need to translate the geometry by: " << move_x << " " << move_y << " " << move_z << std::endl;

	// calculate scaling factors along X, Y and Z
	float scale_x = (float)(x_max - x_min) / 1.0f;
	float scale_y = (float)(y_max - y_min) / 1.0f;
	float scale_z = (float)(z_max - z_min) / 1.0f;

	float scale_0 = scale_x;
	if (scale_y > scale_0) scale_0 = scale_y;
	if (scale_z > scale_0) scale_0 = scale_z;

	std::cout << "Need to scale the geometry by: " << 1.0f / scale_0 << std::endl;
	float scale = 3.2f * scale_0;

	//--------------------------------
	//   Create a WINDOW using GLFW
	//--------------------------------
	GLFWwindow* window;

	if (!glfwInit()) return -1;

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	window = glfwCreateWindow(mode->width, mode->height, "STL viewer", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(1);
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(1);
	}


	//------------------------------------------
	// create a vertex array based on facet data
	//------------------------------------------
	float* vertices = new float[facet.size() * 30]; // 30 * 8
	createVertexArray(facet, vertices); // custom function for VAO

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, facet.size() * 30 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);

	initLightAndMaterial();


	float light_x = 1.0f;
	float light_y = 1.0f;
	float light_z = -1.0f;

	glm::vec4 lightPos(light_x, light_y, light_z, 0.0f); // direction light


	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Viewing transformation
		{
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(50.0f, 1.0f, 0.1f, 10.0f);
		}


		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

		glm::mat4 rotMatrix = glm::mat4(1.0f);
		//rotMatrix = glm::rotate(rotMatrix, glm::radians(rotate_x), glm::vec3(-1.0f, 0.0f, 0.0f)); // 측면 기울임
		//rotMatrix = glm::rotate(rotMatrix, glm::radians(rotate_y), glm::vec3(0.0f, 0.0f, 1.0f));
		rotMatrix = glm::rotate(rotMatrix, glm::radians(rotate_z), glm::vec3(0.0f, -1.0f, 0.0f));


		glm::vec4 resPos = rotMatrix * lightPos;


		glScalef(1.0f / scale, 1.0f / scale, 1.0f / scale);
		glTranslatef(move_x, move_y, move_z);
		glRotatef(rotate_x, 1.0, 0.0, 0.0); glRotatef(rotate_y, 0.0, 1.0, 0.0); glRotatef(rotate_z, 0.0, 0.0, 1.0);

		glLightfv(GL_LIGHT0, GL_POSITION, (GLfloat*)&resPos);


		{
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_FLOAT, sizeof(float) * 10, (GLvoid*)((char*)NULL));

			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_FLOAT, sizeof(float) * 10, (GLvoid*)(((char*)NULL) + 12));

			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(4, GL_FLOAT, sizeof(float) * 10, (GLvoid*)(((char*)NULL) + 24));

			glDrawArrays(GL_TRIANGLES, 0, (int)facet.size() * 3);
		}


		/*QW W is drot_z = ROTATE_DELTA;
		AS S is drot_y = ROTATE_DELTA;
		ZX X is drot_x = ROTATE_DELTA;

		LEFT RIGHT dmov_x = MOVE_DELTA;
		UP DOWN dmov_y = -MOVE_DELTA;
		E D dmov_z = -MOVE_DELTA;*/

		// control section
		{
			move_x += dmov_x;
			move_y += dmov_y;
			move_z += dmov_z;

			rotate_x += drot_x;
			rotate_y += drot_y;
			rotate_z += drot_z;

			if (rotate_x < 0.0f) rotate_x += 360.0f; if (360.0f <= rotate_x) rotate_x -= 360.0f;
			if (rotate_y < 0.0f) rotate_y += 360.0f; if (360.0f <= rotate_y) rotate_y -= 360.0f;
			if (rotate_z < 0.0f) rotate_z += 360.0f; if (360.0f <= rotate_z) rotate_z -= 360.0f;
		}


		glfwSwapBuffers(window);

		glfwPollEvents();

	} // end of while loop

	delete[] vertices;

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
