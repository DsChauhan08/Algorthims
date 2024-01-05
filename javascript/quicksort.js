function quicksort(arr) {
    if (arr.length <= 1) {
        return arr;
    }

    const pivot = arr[0];
    const left = [];
    const right = [];

    for (let i = 1; i < arr.length; i++) {
        if (arr[i] < pivot) {
            left.push(arr[i]);
        } else {
            right.push(arr[i]);
        }
    }

    return [...quicksort(left), pivot, ...quicksort(right)];
}

// Example usage
const unsortedArray = [5, 2, 9, 1, 5, 6];
const sortedArray = quicksort(unsortedArray);

console.log("Unsorted Array:", unsortedArray);
console.log("Sorted Array:", sortedArray);
