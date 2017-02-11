struct VAO {
    GLuint VertexArrayID;
    GLuint VertexBuffer;
    GLuint ColorBuffer;

    GLenum PrimitiveMode;
    GLenum FillMode;
    int NumVertices;
};
typedef struct VAO VAO;

struct GLMatrices {
	glm::mat4 projection;
	glm::mat4 model;
	glm::mat4 view;
	GLuint MatrixID;
};

extern struct GLMatrices Matrices;

extern int do_rot, floor_rel;
extern GLuint programID;
extern double last_update_time, current_time;
extern glm::vec3 rect_pos, floor_pos;
extern float rectangle_rotation;

void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods);
void keyboardChar (GLFWwindow* window, unsigned int key);
void mouseButton (GLFWwindow* window, int button, int action, int mods);
void reshapeWindow (GLFWwindow* window, int width, int height);
void error_callback(int error, const char* description);
void quit(GLFWwindow *window);
GLFWwindow* initGLFW (int width, int height);
void initGL (GLFWwindow* window, int width, int height);

extern float rectangle_rot_dir;
extern bool rectangle_rot_status;

void createCam();
void createFloor();
void createRectangle();
GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);