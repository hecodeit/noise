#version 150

out vec4 outputColor;

void main() {

//    float f = length(gl_PointCoord - vec2(0.5, 0.5));
//    if (f > 0.5) {
//        discard;
//    }

    // vec2 p = (gl_FragCoord.xy * 2.0 - resolution) / min(resolution.x, resolution.y);

//     vec4 color = vec4(vec3(1.0), 1.0);
//    //
//     if(vPosition.z < 0.5) {
//         outputColor = vec4(vec3(0.75, 0.75, 0.78), 1.0);
//     } else {
//         outputColor = color;
//     }

    vec4 color = vec4(0.0, 0.0, 0.0, 1.0);
//    vec4 color = vec4(vec3(smoothstep(float(vPosition), 1.0, 0.0)), 1.0);
    outputColor = color;

}

