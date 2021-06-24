#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 normal;

out vec3 v_normal;
out vec3 v_fragPos;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_proj;

void main()
{
	// send data to fragment shader
	v_normal = vec3(u_model * normal);
	v_fragPos = vec3(u_model * position);

	// compute transformation
	gl_Position = u_proj * u_view * u_model * position;
};

#shader fragment
#version 330 core

struct Material
{
	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;

	float Shininess;
};

struct Light
{
	vec3 Position;

	vec3 Ambient;
	vec3 Diffuse;
	vec3 Specular;
};

out vec4 color;

in vec3 v_normal;
in vec3 v_fragPos;

uniform Material u_mat;
uniform Light u_light;
uniform vec3 u_viewPos;

void main()
{
	// ambient
	vec3 ambient = u_light.Ambient * u_mat.Ambient;

	// diffuse
	vec3 normal = normalize(v_normal);
	vec3 lightDir = normalize(u_light.Position - v_fragPos);
	float diff = max(dot(lightDir, normal), 0);
	vec3 diffuse = u_light.Diffuse * (u_mat.Diffuse * diff);

	// specular
	vec3 viewDir = normalize(u_viewPos - v_fragPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), u_mat.Shininess);
	vec3 specular = u_light.Specular * (u_mat.Specular * spec);

	// set color
	vec3 result = (specular + diffuse + ambient) * vec3(1.0f, 0.5f, 0.31f);
	color = vec4(result, 1.0f);
};