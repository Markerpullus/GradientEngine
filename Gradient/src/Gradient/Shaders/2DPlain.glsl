#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

void main()
{
	gl_Position = position;
};

#shader fragment
#version 330 core

out vec4 color;

uniform vec3 u_color;

void main()
{
	color = vec4(u_color, 1.0f);
};