/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    
    const narr = new Array(arr.length);
    
    for(let i = 0; i < arr.length; i++){
        narr[i] = fn(arr[i], i);
    }
    
     
    
    return narr;
        

    
};