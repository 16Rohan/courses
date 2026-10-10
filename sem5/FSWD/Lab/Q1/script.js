function firstNonRepeatingChar(str) {
    const charCount = {};

    // Step 1: Build the frequency map
    for (const char of str) {
        charCount[char] = (charCount[char] || 0) + 1;
    }

    // Step 2: Find the first character with a frequency of 1
    for (const char of str) {
        if (charCount[char] === 1) {
            return char;
        }
    }

    // Return null (or any placeholder like '_') if all characters repeat
    return null; 
}

// Examples
console.log(firstNonRepeatingChar("geeksforgeeks"));
console.log(firstNonRepeatingChar("swiss"));         
console.log(firstNonRepeatingChar("aabbcc"));        
