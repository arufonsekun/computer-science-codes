const RED = 0xff0000;
const GREEN = 0x00ff00;

/*let cube = function(){
    let x, y, z;
    let geometry = new THREE.BoxGeometry(x,y,z);
    let material = new THREE.MeshBasicMaterial({color: RED})
}*/

var scene = new THREE.Scene();
var camera = new THREE.PerspectiveCamera(75, window.innerWidth/window.innerHeight, 0.1, 1000);

var renderer = new THREE.WebGLRenderer(depth = true);
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

var geometry = new THREE.BoxGeometry(40, 0.1, 20);
var geometryCube2 = new THREE.BoxGeometry(2, 2, 2);
var material = new THREE.MeshBasicMaterial({color: 0xff0000});
var blue = new THREE.MeshBasicMaterial({color: 0x0000ff});
var cube = new THREE.Mesh(geometry, material);

cube.rotation.x = 0.5;
cube.rotation.y = 0.0;

scene.add(cube);

camera.position.z = 20;

var cube2 = new THREE.Mesh(geometryCube2, blue);
cube2.position.y = 1;
cube2.position.x = 10;
cube2.rotation.x = 0.6;
cube2.rotation.y = -0.5;
cube2.scale.set(2,5,2);
scene.add(cube2);

var animate = function() {
    
    requestAnimationFrame(animate);

    renderer.render(scene, camera);
};

animate();