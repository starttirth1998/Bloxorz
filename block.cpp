#include "header.h"
#include "block.h"

// Creates the rectangle object used in this sample code
void createBlock ()
{
    // GL3 accepts only Triangles. Quads are not supported
    static const GLfloat vertex_buffer_data_block [] = {
	-BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 
	-BLOCK_WIDTH, 0.0, BLOCK_WIDTH, 
	BLOCK_WIDTH, 0.0, BLOCK_WIDTH,
	-BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 
	BLOCK_WIDTH, 0.0, BLOCK_WIDTH,
	BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH,
	BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH,
	BLOCK_WIDTH, 0.0, BLOCK_WIDTH,
	BLOCK_WIDTH, 0.0, -BLOCK_WIDTH,
	BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH,
	BLOCK_WIDTH, 0.0, -BLOCK_WIDTH,
	BLOCK_WIDTH, BLOCK_HEIGHT, -BLOCK_WIDTH,
	BLOCK_WIDTH, BLOCK_HEIGHT, -BLOCK_WIDTH,
	BLOCK_WIDTH, 0.0, -BLOCK_WIDTH,
	-BLOCK_WIDTH, 0.0, -BLOCK_WIDTH,
	BLOCK_WIDTH, BLOCK_HEIGHT, -BLOCK_WIDTH,
	-BLOCK_WIDTH, 0.0, -BLOCK_WIDTH,
	-BLOCK_WIDTH, BLOCK_HEIGHT, -BLOCK_WIDTH,
	-BLOCK_WIDTH, BLOCK_HEIGHT, -BLOCK_WIDTH,
	-BLOCK_WIDTH, 0.0, -BLOCK_WIDTH,
	-BLOCK_WIDTH, 0.0, BLOCK_WIDTH, 
	-BLOCK_WIDTH, BLOCK_HEIGHT, -BLOCK_WIDTH,
	-BLOCK_WIDTH, 0.0, BLOCK_WIDTH, 
	-BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 
	-BLOCK_WIDTH, BLOCK_HEIGHT, -BLOCK_WIDTH,
	-BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH, 
	BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH,
	-BLOCK_WIDTH, BLOCK_HEIGHT, -BLOCK_WIDTH,
	BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH,
	BLOCK_WIDTH, BLOCK_HEIGHT, -BLOCK_WIDTH,
	-BLOCK_WIDTH, 0.0, BLOCK_WIDTH, 
	-BLOCK_WIDTH, 0.0, -BLOCK_WIDTH,
	BLOCK_WIDTH, 0.0, -BLOCK_WIDTH,
	-BLOCK_WIDTH, 0.0, BLOCK_WIDTH, 
	BLOCK_WIDTH, 0.0, -BLOCK_WIDTH,
	BLOCK_WIDTH, 0.0, BLOCK_WIDTH,
	-BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH,
	BLOCK_WIDTH, BLOCK_HEIGHT, -BLOCK_WIDTH,
	BLOCK_WIDTH, BLOCK_HEIGHT, -BLOCK_WIDTH,
    };

    static const GLfloat color_buffer_data_block [] = {
	0.4, 0.4, 0.4,
	0.8, 0.1, 0,
	0.8, 0.4, 0.2,
	0.4, 0.4, 0.4,
	0.8, 0.4, 0.2,
	0.8, 0.3, 0.1,

	0.4, 0.4, 0.4,
	0.8, 0.1, 0,
	0.8, 0.4, 0.2,
	0.4, 0.4, 0.4,
	0.8, 0.4, 0.2,
	0.8, 0.3, 0.1,

	0.4, 0.4, 0.4,
	0.8, 0.1, 0,
	0.8, 0.4, 0.2,
	0.4, 0.4, 0.4,
	0.8, 0.4, 0.2,
	0.8, 0.3, 0.1,

	0.4, 0.4, 0.4,
	0.8, 0.1, 0,
	0.8, 0.4, 0.2,
	0.4, 0.4, 0.4,
	0.8, 0.4, 0.2,
	0.8, 0.3, 0.1,

	0.4, 0.4, 0.4,
	0.8, 0.1, 0,
	0.8, 0.4, 0.2,
	0.4, 0.4, 0.4,
	0.8, 0.4, 0.2,
	0.8, 0.3, 0.1,

	0.4, 0.4, 0.4,
	0.8, 0.1, 0,
	0.8, 0.4, 0.2,
	0.4, 0.4, 0.4,
	0.8, 0.4, 0.2,
	0.8, 0.3, 0.1,

	0, 0, 0,
	0, 0, 0,
	1, 1, 1,
    };


	
    // create3DObject creates and returns a handle to a VAO that can be used later
    BLOCK.block = create3DObject(GL_TRIANGLES, 13*3, vertex_buffer_data_block, color_buffer_data_block, GL_FILL);
}