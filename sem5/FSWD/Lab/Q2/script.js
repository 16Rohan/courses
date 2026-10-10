function move(dist, x, y) {
    img = document.getElementById("pic");
    if(x === 0){
        img.style.transform = `translateY(${y * dist}px)`;
    }   
    if(y === 0){
        img.style.transform = `translateX(${x * dist}px)`;
    }   
}

document.getElementById("up").addEventListener("click", () => {
    move(50, 0, -1);
});

document.getElementById("down").addEventListener("click", () => {
    move(50, 0, 1);
});

document.getElementById("left").addEventListener("click", () => {
    move(50, -1, 0);
});

document.getElementById("right").addEventListener("click", () => {
    move(50, 1, 0);
});