// Connect to Face Detection WebSocket
const ws = new WebSocket("ws://localhost:9001/face");

ws.onmessage = (event) => {
    let img = document.getElementById("faceImg");
    img.src = URL.createObjectURL(event.data);
};

// Initialize WebGL
function startWebGL() {
    let canvas = document.getElementById("webglCanvas");
    let gl = canvas.getContext("webgl");

    if (!gl) {
        alert("WebGL not supported!");
        return;
    }

    gl.clearColor(0.0, 0.0, 0.0, 1.0);
    gl.clear(gl.COLOR_BUFFER_BIT);
}
