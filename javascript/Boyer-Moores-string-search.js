function boyerMooreSearch(text, pattern) {
    const m = pattern.length;
    const n = text.length;

    // Build the bad character heuristic
    const badChar = {};
    for (let i = 0; i < m - 1; i++) {
        badChar[pattern[i]] = Math.max(1, m - i - 1);
    }

    let i = 0;
    while (i <= n - m) {
        let j = m - 1;

        // Check for a match
        while (j >= 0 && pattern[j] === text[i + j]) {
            j--;
        }

        // If the pattern is found
        if (j < 0) {
            return i;
        }

        // Shift the pattern based on the bad character heuristic
        i += Math.max(1, j - (badChar[text[i + j]] || -1));
    }

    return -1;
}

const namesArray = ['Alice', 'Bob', 'Charlie', 'David', 'Emma', 'Frank'];

const userInput = prompt('Enter a name to search:');

let foundIndex = -1;

for (let i = 0; i < namesArray.length; i++) {
    const name = namesArray[i].toLowerCase();
    const searchInput = userInput.toLowerCase();

    if (boyerMooreSearch(name, searchInput) !== -1) {
        foundIndex = i;
        break;
    }
}

if (foundIndex !== -1) {
    console.log(`Name found at index ${foundIndex} in the array.`);
} else {
    console.log('Name not found in the array.');
}
