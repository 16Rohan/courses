const { count } = require("console");
const readline = require("readline")

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});


rl.question("Enter array: ", (str)=>{
    
    dict = {}

    let strcpy = new Set(str.split(""));
    strcpy.forEach((char) => {
        count = 0;
        for(let i = 0; i < str.length; i++){
            if(str[i] === char) count++;
        }
        dict[char] = count;
    })
    rl.close();
})