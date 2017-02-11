

struct VAO {
    GLuint VertexArrayID;
    GLuint VertexBuffer;
    GLuint ColorBuffer;

    GLenum PrimitiveMode;
    GLenum FillMode;
    int NumVertices;
};
typedef struct VAO VAO;

typedef struct Floor{
    VAO* floor;
    int index;
    float x;
    float y;
    float z;
    float angle;
}Floor;

Floor FLOOR[105];

struct GLMatrices {
    glm::mat4 projection;
    glm::mat4 model;
    glm::mat4 view;
    GLuint MatrixID;
} Matrices;

void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods);
void keyboardChar (GLFWwindow* window, unsigned int key);
void mouseButton (GLFWwindow* window, int button, int action, int mods);
void reshapeWindow (GLFWwindow* window, int width, int height);
void error_callback(int error, const char* description);
void quit(GLFWwindow *window);
GLFWwindow* initGLFW (int width, int height);
void initGL (GLFWwindow* window, int width, int height);

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat* color_buffer_data, GLenum fill_mode);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode);
void draw3DObject (struct VAO* vao);

int do_rot, floor_rel;
GLuint programID;
double last_update_time, current_time;
glm::vec3 rect_pos, floor_pos;
float rectangle_rotation = 15;

float rectangle_rot_dir = 1;
bool rectangle_rot_status = true;

VAO *rectangle, *cam, *floor_vao;

float camera_rotation_angle = 0;
