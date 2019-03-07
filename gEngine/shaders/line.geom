#version 330 core

layout (points)in;
layout (line_strip,max_vertices=2)out;

uniform mat4 projection_matrix=mat4(1.0f);
uniform mat4 view_matrix=mat4(1.0f);
uniform mat4 model_matrix=mat4(1.0f);

uniform vec2 vertex1;
uniform vec2 vertex2;

void main()
{
	gl_Position=projection_matrix*view_matrix*model_matrix*(gl_in[0].gl_Position+vec4(vertex1,0.0f,0.0f));
	EmitVertex();
	gl_Position=projection_matrix*view_matrix*model_matrix*(gl_in[0].gl_Position+vec4(vertex2,0.0f,0.0f));
	EmitVertex();

	EndPrimitive();
}