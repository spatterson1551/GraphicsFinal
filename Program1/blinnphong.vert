#version 130

uniform mat4 u_modelMatrix;
uniform mat4 u_projMatrix;
uniform vec4 u_lightPos;
uniform vec4 u_camPos;

uniform vec3 u_color;

in vec4 vs_position;
in vec4 vs_normal;
in vec3 vs_color;

out vec3 fs_light;
out vec3 fs_normal;
out vec3 fs_position;
out vec3 fs_color;
out vec3 camPosition;

void main() {
	//fs_color = vs_color;
	fs_color = u_color;

	fs_normal = normalize((u_modelMatrix * vs_normal).xyz);
	//fs_normal = normalize((u_modelMatrix * vec4(vs_normal, 0.0)).xyz);
	fs_light = normalize(u_lightPos.xyz - (u_modelMatrix*vs_position).xyz);
	//fs_light = normalize((u_lightPos - u_modelMatrix * vs_position).xyz); 
	fs_position = (u_modelMatrix*vs_position).xyz;

	//camPosition = u_camPos.xyz;
	camPosition = (u_modelMatrix*u_camPos).xyz;

    gl_Position = u_projMatrix * u_modelMatrix * vs_position;

}