#version 330 core

layout (location=0) in vec2 position;
layout (location=1) in vec2 texCoord;

uniform mat4 projection_matrix=mat4(1.0);
uniform mat4 view_matrix=mat4(1.0);
uniform mat4 model_matrix=mat4(1.0);

out vec2 TexCoord;

void main()
{
	gl_Position=projection_matrix*view_matrix*model_matrix*vec4(position,1.0f,1.0f);
	TexCoord=texCoord;
}