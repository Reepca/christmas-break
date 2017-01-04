// Shaders woooo


// Vertex Shaders
char* img_vshader_src = "#version 150"

"in vec2 position;"
"in vec2 uv_in;"
""
"out vec2 uv_out;"
""
"void main()"
"{"
"  gl_Position = vec4(position, 0.0, 1.0);"
"  uv_out = uv_in;"
"}";

// Geometry Shaders suck


// Fragment Shader
char* img_fshader_src = "#version 150"
""
"in vec2 uv_in;"
"out vec4 outColor;"
""
"uniform sampler2D tex;"
""
"void main()"
"{"
"  outColor = texture(tex, uv_in);"
"}";
