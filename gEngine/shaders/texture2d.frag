#version 330 core
in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D Texture1;
uniform vec4 color;

void main()
{
	FragColor=texture(Texture1,TexCoord)*color;
}