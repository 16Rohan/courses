const { stdin } = require("process");
const readline = require("readline");

const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

rl.question('Enter a string: ', (str)=>{
    for(let size = 1; size < str.length; size++){
        for(let idx = 0; idx <= str.length - size; idx++){
            console.log(str.slice(idx, idx + size));
        }
    }
    rl.close();
})