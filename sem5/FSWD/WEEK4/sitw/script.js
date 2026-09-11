const cat = document.getElementById("cat");

let x = 0; 
let y = 0;
const accel = 0.5;
const speed = 1;
let disp = 0;
let time = 0;

document.addEventListener("keydown", (event) => {
    time = time + 1;
    disp = speed * time + 0.5 * accel * time * time;
    switch (event.key) {

        case "ArrowUp":
            y -= disp;
            break;
        case "ArrowDown":
            y += disp;
            break;
        case "ArrowLeft":
            x -= disp;
            break;
        case "ArrowRight":
            x += disp;
            break;
    }

    cat.style.transform = `translate(${x}px, ${y}px)`;
});

document.addEventListener("keyup", () =>{
    disp = 0;
    time = 0;
})

