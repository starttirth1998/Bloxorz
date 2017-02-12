#include "header.h"
#include "create_object.h"

// Creates the rectangle object used in this sample code
void createRectangle ()
{
    // GL3 accepts only Triangles. Quads are not supported
    static const GLfloat vertex_buffer_data [] = {
	-TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH, 
	-TILE_WIDTH, 0.0, TILE_WIDTH, 
	TILE_WIDTH, 0.0, TILE_WIDTH,
	-TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH, 
	TILE_WIDTH, 0.0, TILE_WIDTH,
	TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH,
	TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH,
	TILE_WIDTH, 0.0, TILE_WIDTH,
	TILE_WIDTH, 0.0, -TILE_WIDTH,
	TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH,
	TILE_WIDTH, 0.0, -TILE_WIDTH,
	TILE_WIDTH, TILE_HEIGHT, -TILE_WIDTH,
	TILE_WIDTH, TILE_HEIGHT, -TILE_WIDTH,
	TILE_WIDTH, 0.0, -TILE_WIDTH,
	-TILE_WIDTH, 0.0, -TILE_WIDTH,
	TILE_WIDTH, TILE_HEIGHT, -TILE_WIDTH,
	-TILE_WIDTH, 0.0, -TILE_WIDTH,
	-TILE_WIDTH, TILE_HEIGHT, -TILE_WIDTH,
	-TILE_WIDTH, TILE_HEIGHT, -TILE_WIDTH,
	-TILE_WIDTH, 0.0, -TILE_WIDTH,
	-TILE_WIDTH, 0.0, TILE_WIDTH, 
	-TILE_WIDTH, TILE_HEIGHT, -TILE_WIDTH,
	-TILE_WIDTH, 0.0, TILE_WIDTH, 
	-TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH, 
	-TILE_WIDTH, TILE_HEIGHT, -TILE_WIDTH,
	-TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH, 
	TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH,
	-TILE_WIDTH, TILE_HEIGHT, -TILE_WIDTH,
	TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH,
	TILE_WIDTH, TILE_HEIGHT, -TILE_WIDTH,
	-TILE_WIDTH, 0.0, TILE_WIDTH, 
	-TILE_WIDTH, 0.0, -TILE_WIDTH,
	TILE_WIDTH, 0.0, -TILE_WIDTH,
	-TILE_WIDTH, 0.0, TILE_WIDTH, 
	TILE_WIDTH, 0.0, -TILE_WIDTH,
	TILE_WIDTH, 0.0, TILE_WIDTH,
	-TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH,
	TILE_WIDTH, TILE_HEIGHT, -TILE_WIDTH,
	TILE_WIDTH, TILE_HEIGHT, -TILE_WIDTH,
    };

    static const GLfloat color_buffer_data [] = {
	0.4, 0.4, 0.4,
	0.8, 0.8, 0.8,
	0.8, 0.8, 0.8,
	0.4, 0.4, 0.4,
	0.8, 0.8, 0.8,
	0.8, 0.8, 0.8,

	0.4, 0.4, 0.4,
	0.8, 0.8, 0.8,
	0.8, 0.8, 0.8,
	0.4, 0.4, 0.4,
	0.8, 0.8, 0.8,
	0.8, 0.8, 0.8,

	0.4, 0.4, 0.4,
	0.8, 0.8, 0.8,
	0.8, 0.8, 0.8,
	0.4, 0.4, 0.4,
	0.8, 0.8, 0.8,
	0.8, 0.8, 0.8,

	0.2, 0.2, 0.2,
	0.6, 0.6, 0.6,
	0.6, 0.6, 0.6,
	0.2, 0.2, 0.2,
	0.8, 0.8, 0.8,
	0.8, 0.8, 0.8,

	0.4, 0.4, 0.4,	
	0.8, 0.8, 0.8,	
	0.8, 0.8, 0.8,	
	0.4, 0.4, 0.4,	
	0.8, 0.8, 0.8,	
	0.8, 0.8, 0.8,

	0.4, 0.4, 0.4,	
	0.8, 0.8, 0.8,	
	0.8, 0.8, 0.8,	
	0.4, 0.4, 0.4,	
	0.8, 0.8, 0.8,	
	0.8, 0.8, 0.8,
	0, 0, 0,
	0, 0, 0,
	1, 1, 1,
    };


	
    // create3DObject creates and returns a handle to a VAO that can be used later
	for(int i=0;i<100;i++)
	{
    	FLOOR[i].floor = create3DObject(GL_TRIANGLES, 13*3, vertex_buffer_data, color_buffer_data, GL_FILL);
	}
}
void createCam ()
{
    // GL3 accepts only Triangles. Quads are not supported
    static const GLfloat vertex_buffer_data [] = {
	-TILE_WIDTH, 0, 0,
	TILE_WIDTH, 0, 0, 
	0, TILE_WIDTH, 0,
    };

    static const GLfloat color_buffer_data [] = {
	1, 1, 1,
	1, 1, 1,
	1, 1, 1,
    };

    // create3DObject creates and returns a handle to a VAO that can be used later
    cam = create3DObject(GL_TRIANGLES, 1*3, vertex_buffer_data, color_buffer_data, GL_LINE);
}
void createFloor ()
{
    // GL3 accepts only Triangles. Quads are not supported
    static const GLfloat vertex_buffer_data [] = {
	-1, -1, 1,
	1, -1, 1, 
	-1, -1, -1,
	-1, -1, -1,
	1, -1, 1, 
	1, -1, -1,
    };

    static const GLfloat color_buffer_data [] = {
	TILE_WIDTH, TILE_WIDTH, TILE_WIDTH,
	TILE_WIDTH, TILE_WIDTH, TILE_WIDTH,
	TILE_WIDTH, TILE_WIDTH, TILE_WIDTH,
	TILE_WIDTH, TILE_WIDTH, TILE_WIDTH,
	TILE_WIDTH, TILE_WIDTH, TILE_WIDTH,
	TILE_WIDTH, TILE_WIDTH, TILE_WIDTH,
    };

    // create3DObject creates and returns a handle to a VAO that can be used later
    floor_vao = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, color_buffer_data, GL_FILL);
}