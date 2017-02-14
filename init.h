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

typedef struct Block{
    VAO* block;
    float x;
    float y;
    float z;
    float angle;
    float angle_x;
    float angle_incr;
    float angle_incr_x;
    float trans_incr;
    int horizontal_z;
    int horizontal_x;
    glm::vec3 axis;
    glm::vec3 axis_x;
}Block;

extern Block BLOCK;

extern int do_rot, floor_rel;
extern GLuint programID;
extern double last_update_time, current_time;
extern glm::vec3 rect_pos, floor_pos;
extern float rectangle_rotation;
extern float TILE_WIDTH;
extern float BLOCK_HEIGHT;
extern int FOLLOW_VIEW_FLAG;
extern int BLOCK_VIEW_FLAG;

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
void createBlock();

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

extern glm::vec3 up,target,eye;
extern glm::vec3 TOP_VIEW_EYE,TOP_VIEW_TARGET,TOP_VIEW_UP,TOWER_VIEW_EYE,TOWER_VIEW_TARGET,TOWER_VIEW_UP;
extern int FLAG_DOWN,FLAG_LEFT;

extern float ROTATION_SPEED;


extern float BLOCK_WIDTH,BLOCK_HEIGHT;
