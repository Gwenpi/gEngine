#version 330 core
layout (location=0) in vec3 position;

uniform mat4 projection_matrix=mat4(1.0f);
uniform mat4 view_matrix=mat4(1.0f);
uniform mat4 model_matrix=mat4(1.0f);

void main()
{
	gl_Position=projection_matrix*view_matrix*model_matrix*vec4(position,1.0f);
}