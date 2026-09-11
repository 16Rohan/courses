const readline = require("readline")

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});


rl.question("Enter a string: ", (str)=>{
    let list = str.split(" ");
    for(let i = 0; i < list.length; i++){
        list[i] = list[i].split("").reverse().join("");
    }
    str = list.join(" ");
    console.log(str)
    rl.close();
})