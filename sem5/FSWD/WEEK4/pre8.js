const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

rl.question('Enter a string: ', (str)=>{
    let whitelist = new Set();
    let blacklist = new Set();

    for(const ch of str){
        if(blacklist.has(ch)) continue;
        if(whitelist.has(ch)){
            whitelist.delete(ch);
            blacklist.add(ch);
            continue;
        }
        whitelist.add(ch);
    }
    // console.log(blacklist);
    console.log(whitelist);

    for(let i = 0; i < str.length; i++){
        if(whitelist.has(str.charAt(i))){
            console.log(str.charAt(i));
            break;
        }
    }

    rl.close();
})
