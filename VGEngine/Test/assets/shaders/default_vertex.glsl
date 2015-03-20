attribute highp vec2 attrPosition;
attribute lowp vec4 attrColor;
attribute mediump vec2 attrTexCoord;

varying lowp vec4 varyColor;
varying mediump vec2 varyTexCoord;

void main()
{
	varyColor = vec4(1.0, 0.0, 0.0, 1.0);
	varyTexCoord = attrTexCoord;
	gl_Position = vec4(attrPosition, 1.0, 1.0);
}