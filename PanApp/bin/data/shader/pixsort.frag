#version 400

in vec4 vColor;
in vec4 vfragPos;
out vec4 outputColor;
uniform sampler2DRect tex0;

void main()
{
	outputColor = vec4(vfragPos.x/1920.0, vfragPos.y/1080.0, 0.0, 1.0);
}