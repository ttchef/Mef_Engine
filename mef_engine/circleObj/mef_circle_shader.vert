
#version 430 core

void main(void)
{
    if (gl_VertexID == 0) gl_Position = vec4(-1.0, -1.0, 0.0, 1.0);
    else if (gl_VertexID == 1) gl_Position = vec4(-1.0, 1.0, 0.0, 1.0);
    else if (gl_VertexID == 2) gl_Position = vec4(1.0, -1.0, 0.0, 1.0);
    else if (gl_VertexID == 3) gl_Position = vec4(1.0, 1.0, 0.0, 1.0);
    else 1.0, -1.0, 0.0, 1.0;
}


