// A majority element in an array A[] of size n is an element that appears more than n/2 times
// Examples
// [3 3 3 2 2] -> 3
// [3 2 3 2 3] -> 3
// Moore vooting algorithm
function isMajorityElement(chain, candidate) {
    var count = 0;
    for (var i = 0; i < chain.length; i += 1) {
        count = (candidate == chain[i]) ? count + 1 : count - 1;
        if (count > chain.length / 2) {
            return true;
        }
    }
    return false;
}

function findCandidate(chain) {
    var candidate = 0;
    var count = 0;
    // Check if chain exist and set candidate to the first element in the array
    if (chain.length > 0) {
        candidate = chain[0];
        count = 1;
    }
    // O(n) loop to find the element which occur more in the array
    for (var i = 1; i < chain.length; i += 1) {
        count = (candidate == chain[i]) ? count + 1 : count - 1;
        // Change the candidate to the actual number
        if (count == 0) {
            candidate = chain[i];
            count = 1;
        }
    }
    return candidate;
}
function main() {
    var chain = [7, 7, 5, 6, 7, 7];
    var candidate = findCandidate(chain);
    isMajorityElement(chain, candidate);
}
