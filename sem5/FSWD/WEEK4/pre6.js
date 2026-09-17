const readline = require("readline")

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});


rl.question("Enter string: ", (str)=>{

    dict = {}

    console.log(str.split(""));
    let strset = new Set(str.split(""));
    // console.log(strset);
    strset.forEach((element) => {
        // if(element  {}) console.log(element);
        count = 0;
        for(let i = 0; i < str.length; i++){
            if(str.charAt(i) === element) count++;
        }
        dict[element] = count;
    })

    for(const [key, value] of Object.entries(dict)){
        console.log(`${key}: ${value}`);
    }

    rl.close();
})