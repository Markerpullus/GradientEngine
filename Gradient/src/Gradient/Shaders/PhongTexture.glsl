#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 normal;
layout(location = 2) in vec2 texCoords;
layout(location = 3) in vec4 tangent;

out vec3 v_normal;
out vec2 v_texCoords;
out vec3 v_fragPos;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_proj;

void main()
{
	// send data to fragment shader
	v_normal = vec3(u_model * normal);
	v_texCoords = texCoords;
	v_fragPos = vec3(u_model * position);

	// compute transformation
	gl_Position = u_proj * u_view * u_model * position;
};

#shader fragment
#version 330 core

struct MaterialTexture
{
	sampler2D Diffuse;
	sampler2D Specular;

	float Shininess;
};

struct Light
{
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;

	vec3 Position;
};

out vec4 color;

in vec3 v_normal;
in vec2 v_texCoords;
in vec3 v_fragPos;

uniform MaterialTexture u_mat;
uniform Light u_light;
uniform vec3 u_viewPos;

void main()
{
	// ambient
	vec3 ambient = u_light.Ambient * vec3(texture(u_mat.Diffuse, v_texCoords));

	// diffuse
	vec3 normal = normalize(v_normal);
	vec3 lightDir = normalize(u_light.Position - v_fragPos);
	float diff = max(dot(lightDir, normal), 0);
	vec3 diffuse = u_light.Diffuse * diff * vec3(texture(u_mat.Diffuse, v_texCoords));

	// specular
	vec3 viewDir = normalize(u_viewPos - v_fragPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), u_mat.Shininess);
	vec3 specular = u_light.Specular * spec * vec3(texture(u_mat.Specular, v_texCoords));

	// set color
	color result = vec4(ambient + diffuse + specular, 1.0f);
};