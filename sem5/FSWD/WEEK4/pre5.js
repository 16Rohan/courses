const readline = require("readline")

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});


rl.question("Enter array: ", (arr)=>{
    arr = arr.split(" ");
    // console.log(arr);
    
    for(let i = 0; i < arr.length; i++){
        arr[i] = Number(arr[i]);
    }
    arr.sort();

    console.log(`Smallest: ${arr[0]}`);
    if(arr.length > 1) console.log(`Second Largest: ${arr[arr.length - 2]}`);
    rl.close();
})