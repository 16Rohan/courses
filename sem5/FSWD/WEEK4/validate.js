const readline = require("readline")

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});


rl.question("Enter a string: ", (str)=>{
    let invalid = false;
    let digits = "0123456789";
    let alphabets = "qwertyuiopasdfghjklzxcvbnm";
    if(str.length != 10) invalid = true;
    if(!invalid && !digits.includes(str.charAt(0))) invalid = true;
    if(!invalid && !alphabets.includes(str.charAt(str.length - 1).toLowerCase())) invalid = true;
    if(invalid){
        console.log("This string is invalid");
    }
    else{
        console.log("This string is valid");
    }
    rl.close();
})

